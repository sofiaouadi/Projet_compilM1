%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtable.h"
#include "quad.h"

extern int yylex();
void yyerror(const char *s);

extern int ligne;
extern int colonne;

char *current_type  = NULL;   /* type courant (INTEGER / FLOAT) */
int   current_const = 0;      /* 0 = variable, 1 = constante  */
%}

/* ────────────────────────────────────────
   UNION des valeurs sémantiques
   ──────────────────────────────────────── */
%union {
    int   ival;
    float fval;
    char *str;
    struct {
        char *type;    /* "INTEGER" ou "FLOAT" */
        char *place;   /* T0, T1 … ou nom de variable */
        int valeur;     
    int isConst; 
    } expr;
}

/* ────────────────────────────────────────
   TOKENS
   ──────────────────────────────────────── */
%token PROGRAM DECL ENDDECL BEGIN_T END_T
%token INTEGER FLOAT_T CONST
%token IF ELSE WHILE FOR WRITE
%token EQL EQ NEQ GE LE
%token AND OR

%token <str>  IDF
%token <ival> INT_CONST
%token <fval> FLOAT_CONST

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

/* ────────────────────────────────────────
   TYPES DES NON-TERMINAUX
   ──────────────────────────────────────── */
%type <expr> expression condition

/* ────────────────────────────────────────
   PRIORITÉS ET ASSOCIATIVITÉ
   ──────────────────────────────────────── */
%left OR
%left AND
%right '!'
%left EQ NEQ
%left '<' '>' GE LE
%left '+' '-'
%left '*' '/'

%%

/* ════════════════════════════════════════
   PROGRAMME
   ════════════════════════════════════════ */
programme:
    PROGRAM IDF declarations BEGIN_T instructions END_T
    {
        afficherTable();
        afficher_quads();
        optimiser_quads();
        printf("\n=== APRES OPTIMISATION ===\n");
        afficher_quads();
        generer_asm_8086("output.asm");
        printf("\nAnalyse et compilation terminees avec succes !\n");
    }
    | PROGRAM error declarations BEGIN_T instructions END_T
    {
        printf(" Erreur Syntaxique : ligne %d : identificateur du programme manquant\n", ligne);
        yyerrok;
    }
;
     | error IDF declarations BEGIN_T instructions END_T
    {
        printf(" Erreur Syntaxique : ligne %d : mot-cle {PROGRAM}   manquant\n", ligne);
        yyerrok;
    }
    | PROGRAM IDF declarations error instructions END_T
    {
        printf(" Erreur Syntaxique : ligne %d : mot-cle {BEGIN} manquant\n", ligne);
        yyerrok;
    }
;
     | PROGRAM IDF declarations BEGIN_T instructions error
    {
        printf(" Erreur Syntaxique : ligne %d , colonne %d : mot-cle {END} manquant\n",
               ligne, colonne);
        yyerrok;  // permet de continuer proprement
    }
;

/* ════════════════════════════════════════
   DÉCLARATIONS
   ════════════════════════════════════════ */
declarations:
    DECL liste_declarations ENDDECL
     |error liste_declarations ENDDECL
    {
        printf(" Erreur Syntaxique : ligne %d : mot-cle {DECL}  manquant\n", ligne);
        yyerrok;
    }
    || DECL liste_declarations error
    {
        printf(" Erreur Syntaxique : ligne %d : mot-cle {ENDDECL} manquant\n", ligne);
        yyerrok;
    }
;

liste_declarations:
    /* vide */
    | liste_declarations declaration
;

declaration:
    type ':' liste_id ';'
    | declaration_constante
;

type:
    INTEGER { current_type = "INTEGER"; current_const = 0; }
    | FLOAT_T { current_type = "FLOAT";   current_const = 0; }
;

/* ── liste d'identifiants (possiblement avec init ou tableau) ── */
liste_id:
    liste_id ',' IDF {
        inserer($3, current_type, current_const);
    }
    | liste_id ',' IDF EQL expression {
        inserer($3, current_type, current_const);
        setInitialisee($3);
        if (!compatible(current_type, $5.type))
            printf("Erreur semantique ligne %d : incompatibilite de type pour '%s' (%s attendu, %s recu)\n",
                   ligne, $3, current_type, $5.type);
        else
            generer_quad("=", $5.place, "", $3);
    }
    | IDF {
        inserer($1, current_type, current_const);
    }
    | IDF EQL expression {
        inserer($1, current_type, current_const);
        setInitialisee($1);
        if (!compatible(current_type, $3.type))
            printf("Erreur semantique ligne %d : incompatibilite de type pour '%s' (%s attendu, %s recu)\n",
                   ligne, $1, current_type, $3.type);
        else
            generer_quad("=", $3.place, "", $1);
    }
    | IDF '[' INT_CONST ']' {
        if ($3 <= 0)
            printf("Erreur semantique ligne %d : taille de tableau invalide pour '%s'\n", ligne, $1);
        else
            inserer_tableau($1, current_type, $3);
    }
;

/* ── Constante ── */
declaration_constante:
    CONST IDF EQL INT_CONST ';' {
        if (existe($2))
            printf("Erreur semantique ligne %d : double declaration de '%s'\n", ligne, $2);
        else {
            inserer($2, "INTEGER", 1);
            setInitialisee($2);
            char buf[30]; sprintf(buf, "%d", $4);
            generer_quad("=", buf, "", $2);
        }
    }
    | CONST IDF EQL FLOAT_CONST ';' {
        if (existe($2))
            printf("Erreur semantique ligne %d : double declaration de '%s'\n", ligne, $2);
        else {
            inserer($2, "FLOAT", 1);
            setInitialisee($2);
            char buf[30]; sprintf(buf, "%f", $4);
            generer_quad("=", buf, "", $2);
        }
    }
;

/* ════════════════════════════════════════
   INSTRUCTIONS
   ════════════════════════════════════════ */
instructions:
    /* vide */
    | instructions instruction
    /*ELSE mal placé*/
    |ELSE '{' instructions '}'
    {
        printf(" Erreur Syntaxique : ligne %d : ELSE sans IF\n", ligne);
    }

;

instruction:
    affectation
    | declaration_constante
    | InstructionFor
    | InstructionWhile
    | InstructionIf
    | write
;

/* ────────────────────────────────────────
   AFFECTATION
   ──────────────────────────────────────── */
affectation:
    IDF EQL expression ';' {
        if (!existe($1))
            printf("Erreur semantique ligne %d : '%s' non declare\n", ligne, $1);
        else if (isConstante($1))
            printf("Erreur semantique ligne %d : '%s' est une constante, affectation interdite\n", ligne, $1);
        else {
    if (!compatible(getType($1), $3.type)) {
        printf("Erreur semantique ligne %d : incompatibilite de type (%s = %s)\n",
               ligne, getType($1), $3.type);
    } else {
        generer_quad("=", $3.place, "", $1);
        setInitialisee($1);
    }
}
    }
    /* accès tableau : T[i] = expr */
    | IDF '[' expression ']' EQL expression ';' {
        if (!existe($1))
            printf("Erreur semantique ligne %d : '%s' non declare\n", ligne, $1);
        else if (!isTableau($1))
            printf("Erreur semantique ligne %d : '%s' n'est pas un tableau\n", ligne, $1);
        else {
            /* vérification d'indice si constante */
            char res[40];
            sprintf(res, "%s[%s]", $1, $3.place);
            generer_quad("=", $6.place, "", res);
        }
    }
;

/* ════════════════════════════════════════
   EXPRESSIONS
   ════════════════════════════════════════ */
expression:
     INT_CONST {
    char buffer[20];
    sprintf(buffer, "%d", $1);

    char* temp = newTemp();
    generer_quad("=", buffer, "", temp);

    $$.type = "INTEGER";
    $$.place = temp;

    $$.valeur = $1;
    $$.isConst = 1;
}
    | FLOAT_CONST {
        char buf[30]; sprintf(buf, "%f", $1);
        char *t = newTemp();
        generer_quad("=", buf, "", t);
        $$.type  = "FLOAT";
        $$.place = t;
        $$.valeur = $1;
        $$.isConst = 1;
    }
    | IDF {
        if (!existe($1))
            printf("Erreur semantique ligne %d : '%s' non declare\n", ligne, $1);
        else if (!estInitialisee($1))
            printf("Avertissement ligne %d : '%s' utilisee sans initialisation\n", ligne, $1);
        $$.type  = existe($1) ? getType($1) : "INTEGER";
        $$.place = $1;
    }
    /* accès tableau : T[i] */
    | IDF '[' expression ']' {
        if (!existe($1))
            printf("Erreur semantique ligne %d : '%s' non declare\n", ligne, $1);
        else if (!isTableau($1))
            printf("Erreur semantique ligne %d : '%s' n'est pas un tableau\n", ligne, $1);
        char *t = newTemp();
        char  src[40]; sprintf(src, "%s[%s]", $1, $3.place);
        generer_quad("=", src, "", t);
        $$.type  = existe($1) ? getType($1) : "INTEGER";
        $$.place = t;
    }
    | expression '+' expression {
        if (!compatible($1.type, $3.type))
            printf("Erreur semantique ligne %d : types incompatibles dans '+'\n", ligne);
        char *t = newTemp();
        generer_quad("+", $1.place, $3.place, t);
        $$.type  = (strcmp($1.type,"FLOAT")==0 || strcmp($3.type,"FLOAT")==0) ? "FLOAT" : "INTEGER";
        $$.place = t;
    }
    | expression '-' expression {
        if (!compatible($1.type, $3.type))
            printf("Erreur semantique ligne %d : types incompatibles dans '-'\n", ligne);
        char *t = newTemp();
        generer_quad("-", $1.place, $3.place, t);
        $$.type  = (strcmp($1.type,"FLOAT")==0 || strcmp($3.type,"FLOAT")==0) ? "FLOAT" : "INTEGER";
        $$.place = t;
    }
    | expression '*' expression {
        if (!compatible($1.type, $3.type))
            printf("Erreur semantique ligne %d : types incompatibles dans '*'\n", ligne);
        char *t = newTemp();
        generer_quad("*", $1.place, $3.place, t);
        $$.type  = (strcmp($1.type,"FLOAT")==0 || strcmp($3.type,"FLOAT")==0) ? "FLOAT" : "INTEGER";
        $$.place = t;
    }
    | expression '/' expression {

    if (!compatible($1.type, $3.type)) {
        printf("❌ Type incompatible dans /\n");
    }

    // 🔥 detection fiable
    if ($3.isConst && $3.valeur == 0) {
        printf(" Erreur semantique ligne %d : division par zero\n", ligne);
    }

    char* temp = newTemp();
    generer_quad("/", $1.place, $3.place, temp);

    $$.type = "FLOAT";
    $$.place = temp;

    $$.isConst = 0;
}
| '(' expression ')' {
        $$.type = $2.type;
        $$.place = $2.place;
        $$.valeur = $2.valeur;
        $$.isConst = $2.isConst;
    }
;

/* ════════════════════════════════════════
   CONDITIONS
   ════════════════════════════════════════ */
condition:
    expression '>' expression {
        char *t = newTemp();
        generer_quad(">", $1.place, $3.place, t);
        $$.type = "INTEGER"; $$.place = t;
    }
    | expression '<' expression {
        char *t = newTemp();
        generer_quad("<", $1.place, $3.place, t);
        $$.type = "INTEGER"; $$.place = t;
    }
    | expression EQ expression {
        char *t = newTemp();
        generer_quad("==", $1.place, $3.place, t);
        $$.type = "INTEGER"; $$.place = t;
    }
    | expression NEQ expression {
        char *t = newTemp();
        generer_quad("!=", $1.place, $3.place, t);
        $$.type = "INTEGER"; $$.place = t;
    }
    | expression GE expression {
        char *t = newTemp();
        generer_quad(">=", $1.place, $3.place, t);
        $$.type = "INTEGER"; $$.place = t;
    }
    | expression LE expression {
        char *t = newTemp();
        generer_quad("<=", $1.place, $3.place, t);
        $$.type = "INTEGER"; $$.place = t;
    }
    | '!' condition {
        char *t = newTemp();
        generer_quad("!", $2.place, "", t);
        $$.type = "INTEGER"; $$.place = t;
    }
    | condition AND condition {
        char *t = newTemp();
        generer_quad("&&", $1.place, $3.place, t);
        $$.type = "INTEGER"; $$.place = t;
    }
    | condition OR condition {
        char *t = newTemp();
        generer_quad("||", $1.place, $3.place, t);
        $$.type = "INTEGER"; $$.place = t;
    }
    | '(' condition ')' {
        $$.type = $2.type;
        $$.place = $2.place;
    }
;

/* ════════════════════════════════════════
   INSTRUCTION IF / ELSE
   ════════════════════════════════════════

   Correction du conflit réduction/réduction :
   On utilise UNE SEULE règle IF avec un
   non-terminal "partie_else" optionnel.
   Cela évite que Bison génère deux règles
   vides @1 et @2 indiscernables au même
   point de lecture ('{' après la condition).

   Quadruplets générés (avec ELSE) :
     ifFalse cond _ Lfaux
     <instructions THEN>
     goto _ _ Lend
     label _ _ Lfaux
     <instructions ELSE>
     label _ _ Lend

   Quadruplets générés (sans ELSE) :
     ifFalse cond _ Lfaux
     <instructions THEN>
     goto _ _ Lend   <- goto vers Lend = Lfaux ici (même label)
     label _ _ Lfaux
     label _ _ Lend  <- optimisé en 1 seul label après
   ════════════════════════════════════════ */

/* ===== INSTRUCTIONS IF ===== */
InstructionIf:
    IF '(' condition ')' '{' instructions '}'
    {
        if (strcmp($3.type, "INTEGER") != 0) {
            printf("❌ Condition de IF doit être de type INTEGER\n");
        }
    }
    | IF '(' condition ')' '{' instructions '}' ELSE '{' instructions '}'
    {
        if (strcmp($3.type, "INTEGER") != 0) {
            printf("❌ Condition de IF doit être de type INTEGER\n");           
        }
    }
    
        //IF sans condition
        |IF error '{' instructions '}'
    {
        printf(" Erreur Syntaxique : ligne %d : condition du IF manquante\n", ligne);
        yyerrok;
    }
;



/* ════════════════════════════════════════
   INSTRUCTION WHILE
   ════════════════════════════════════════

   Quadruplets générés :
     label _ _ Ldebut
     <évaluation condition>
     ifFalse cond _ Lfin
     <instructions>
     goto _ _ Ldebut
     label _ _ Lfin
   ════════════════════════════════════════ */
InstructionWhile:
    WHILE
        {
            char *ldebut = newLabel();
            generer_quad("label", "", "", ldebut);
            $<str>$ = ldebut;
        }
    '(' condition ')'
        {
            char *lfin = newLabel();
            generer_quad("ifFalse", $4.place, "", lfin);
            $<str>$ = lfin;
        }
    '{' instructions '}'
        {
            generer_quad("goto",  "", "", $<str>2);   /* retour en début de boucle */
            generer_quad("label", "", "", $<str>6);   /* label de sortie           */
        }
        //while sans condition
        | WHILE error '{' instructions '}'
    {
        printf(" Erreur Syntaxique : ligne %d : condition du WHILE manquante\n", ligne);
        yyerrok;
    }
;

/* ════════════════════════════════════════
   INSTRUCTION FOR
   ════════════════════════════════════════

   FOR (i : debut : pas : fin)
   Quadruplets générés :
     i = debut
     label _ _ Ldebut
     T = i <= fin          (ou i < fin+1 selon convention)
     ifFalse T _ Lfin
     <instructions>
     i = i + pas
     goto _ _ Ldebut
     label _ _ Lfin
   ════════════════════════════════════════ */
   
InstructionFor:
    FOR '(' IDF ':' INT_CONST ':' INT_CONST ':' INT_CONST ')'
        {
            /* ── vérifications sémantiques ── */
            if (!existe($3))
                printf("Erreur semantique ligne %d : '%s' non declare\n", ligne, $3);
            else if (isConstante($3))
                printf("Erreur semantique ligne %d : '%s' est une constante\n", ligne, $3);
            else if (strcmp(getType($3), "INTEGER") != 0)
                printf("Erreur semantique ligne %d : l'indice de FOR doit etre INTEGER\n", ligne);

            if ($7 == 0)
                printf("Erreur semantique ligne %d : le pas du FOR ne peut pas etre 0\n", ligne);
            if ($7 > 0 && $9 < $5)
                printf("Avertissement ligne %d : borne de fin < borne de debut (boucle vide)\n", ligne);

            /* ── initialisation de l'indice ── */
            char buf_debut[20], buf_pas[20], buf_fin[20];
            sprintf(buf_debut, "%d", $5);
            sprintf(buf_pas,   "%d", $7);
            sprintf(buf_fin,   "%d", $9);

            generer_quad("=", buf_debut, "", $3);
            setInitialisee($3);

            /* ── label de début de boucle ── */
            char *ldebut = newLabel();
            generer_quad("label", "", "", ldebut);

            /* ── condition i <= fin ── */
            char *tcond = newTemp();
            generer_quad("<=", $3, buf_fin, tcond);

            /* ── saut de sortie ── */
            char *lfin = newLabel();
            generer_quad("ifFalse", tcond, "", lfin);

            /* stocker pour après les instructions */
            $<str>$ = ldebut;      /* on réutilise $$ pour stocker ldebut */

            /* NOTE : buf_pas et lfin sont stockés via une astuce —
               on les passe en global temporairement */
            /* Pour simplifier : on les stocke dans des variables globales ad-hoc */
            extern char _for_pas[20];
            extern char _for_idf[20];
            extern char _for_lfin[30];
            strcpy(_for_pas,  buf_pas);
            strcpy(_for_idf,  $3);
            strcpy(_for_lfin, lfin);
        }
    '{' instructions '}'
        {
            extern char _for_pas[20];
            extern char _for_idf[20];
            extern char _for_lfin[30];

            /* incrémenter l'indice */
            char *tinc = newTemp();
            generer_quad("+", _for_idf, _for_pas, tinc);
            generer_quad("=", tinc, "", _for_idf);

            /* retour au début */
            generer_quad("goto",  "", "", $<str>11);

            /* label de fin */
            generer_quad("label", "", "", _for_lfin);
        }
        //FOR sans éléments
        | FOR error '{' instructions '}'
    {
        printf(" Erreur Syntaxique : ligne %d : syntaxe du FOR incorrecte\n", ligne);
        yyerrok;
    }
;

/* ════════════════════════════════════════
   INSTRUCTION WRITE
   ════════════════════════════════════════ */
write:
    WRITE '(' expression ')' ';' {
        if (strcmp($3.type, "INTEGER") != 0 && strcmp($3.type, "FLOAT") != 0)
            printf("Erreur semantique ligne %d : WRITE ne peut afficher que INTEGER ou FLOAT\n", ligne);
        generer_quad("write", $3.place, "", "");
    }
    | WRITE '(' IDF ')' ';' {
    if (!existe($3)) {
        printf("Erreur semantique ligne %d : '%s' non declare\n", ligne, $3); [cite: 143]
    } else {
        if (!estInitialisee($3)) {
            printf("Avertissement ligne %d : '%s' utilisee sans initialisation\n", ligne, $3); 
        }
        if (isTableau($3)) {
            printf("Erreur semantique ligne %d : '%s' est un tableau (indexation requise)\n", ligne, $3); 
        }
        generer_quad("WRITE", $3, "", ""); [cite: 138]
    }
}
| WRITE '(' IDF '[' expression ']' ')' ';' {
    // Vérification pour les éléments de tableau
    if (!existe($3)) {
        printf("Erreur semantique ligne %d : '%s' non declare\n", ligne, $3);
    } else if (!isTableau($3)) {
        printf("Erreur semantique ligne %d : '%s' n'est pas un tableau\n", ligne, $3);
    } else if (strcmp($5.type, "INTEGER") != 0) {
        printf("Erreur semantique ligne %d : l'indice du tableau doit etre un entier\n", ligne); 
    } else {
        generer_quad("WRITE", $5.place, "", ""); 
    }
}
;

%%

/* ─────────────────────────────────────────
   Variables globales pour la boucle FOR
   ───────────────────────────────────────── */
char _for_pas[20]  = "";
char _for_idf[20]  = "";
char _for_lfin[30] = "";

/* ─────────────────────────────────────────
   Gestion des erreurs syntaxiques
   ───────────────────────────────────────── */
void yyerror(const char *s) {
    printf("Erreur syntaxique : ligne %d, colonne %d : %s\n", ligne, colonne, s);
}
