%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtable.h"
#include "quad.h"

//#define YYDEBUG 1

extern int yylex();// déclaration de la fonction de lexing
void yyerror(const char *s);// déclaration de la fonction de gestion des erreurs


// On indique à Bison que 'ligne' est définie dans lex.yy.c
extern int ligne;

char* current_type;// pour stocker le type courant lors des déclarations
int current_const = 0;// 0 = variable, 1 = constante
%}

%union {
    int ival;
    float fval;
    char* str;

    struct {
        char* type;
        char* place; // 🔥 T1, T2, A, B...
    } expr;
}
 

%token PROGRAM DECL ENDDECL BEGIN_T END_T
%token INTEGER FLOAT_T CONST 
%token IF ELSE WHILE FOR WRITE
%token EQL EQ NEQ GE LE 
%token <str> IDF
%token <ival> INT_CONST
%token <fval> FLOAT_CONST
%token TO DO
%token AND OR

//%type <str> type expression condition
%type <expr> expression condition
%left '+' '-'
%left '*' '/'

%%

programme://début de la grammaire
    PROGRAM IDF declarations BEGIN_T instructions END_T
    {
        
        printf(" Analyse terminee avec succes ! BRAVO !!!\n");
    }
;

/* ===== DECLARATIONS ===== */

declarations:
    DECL liste_declarations ENDDECL
;

liste_declarations:
    liste_declarations declaration
    |/* vide */
;

declaration:
    type ':' liste_id ';'
    |declaration_constante
;
type:
    INTEGER { current_type = "INTEGER"; current_const = 0; }
    | FLOAT_T { current_type = "FLOAT"; current_const = 0; }
;

liste_id:
    IDF {
        inserer($1, current_type, current_const);
    }
   
    /* Cas récursif pour les listes : INTEGER : A, B, C ; */
    | liste_id ',' IDF { 
        inserer($3, current_type, current_const); 
    }
    
    /* Cas récursif avec initialisation : INTEGER : A, B = 5, C ; */
    | liste_id ',' IDF EQL expression {
        inserer($3, current_type, current_const);
        setInitialisee($3);
        
        if (!compatible(current_type, $5)) {
            printf(" Erreur ligne %d : Incompatibilité de type lors de l'initialisation de %s (%s attendu, %s reçu)\n", 
                    ligne, $3, current_type, $5);
        }
    }
    /* Cas avec initialisation : INTEGER : i = 0 ; */
    | IDF EQL expression { 
        // 1. Insertion dans la table des symboles
        inserer($1, current_type, current_const);
        
        // 2. Marquage comme initialisée
        setInitialisee($1);
        
        // 3. Vérification de la compatibilité des types
        // current_type est le type à gauche, $3 est le type de l'expression à droite
        if (!compatible(current_type, $3)) {
            printf(" Erreur ligne %d : Incompatibilité de type lors de l'initialisation de %s (%s attendu, %s reçu)\n", 
                    ligne, $1, current_type, $3);
        }
    }
    | IDF '[' INT_CONST ']' {
    inserer_tableau($1, current_type, $3);
    if ($3 <= 0) {
    printf("Erreur : taille tableau invalide ligne %d\n", ligne);
        }
    }
    
;

/* ===== CONST ===== */

declaration_constante:
    CONST IDF EQL INT_CONST ';' {
        if (existe($2)) {
            printf(" Erreur sémantique ligne %d : double déclaration de %s\n", ligne, $2);
        } else {
            inserer($2, "INTEGER", 1);
            setInitialisee($2);

            // 🔥 ETAPE 4 + 5 : génération quadruplet
            char buffer[20];
            sprintf(buffer, "%d", $4);

            generer_quad("=", buffer, "", $2);
        }
    }

    | CONST IDF EQL FLOAT_CONST ';' {
        if (existe($2)) {
            printf(" Erreur sémantique ligne %d : double déclaration de %s\n", ligne, $2);
        } else {
            inserer($2, "FLOAT", 1);
            setInitialisee($2);

            // génération quadruplet
            char buffer[20];
            sprintf(buffer, "%f", $4);

            generer_quad("=", buffer, "", $2);
        }
    }
;

/* ===== INSTRUCTIONS ===== */

instructions:
    /* vide */
    | instructions instruction
;

instruction:affectation
    | declaration_constante
    | InstructionFor
    | InstructionWhile
    | InstructionIf
    | write
    
    
;




/* ===== AFFECTATION ===== */

affectation:
    IDF EQL expression ';'
    {
        // 1. Vérifier déclaration
        if (!existe($1)) {
            printf(" ERREUR SEMANTIQUE : %s non déclaré\n", $1);
        }
        else {
            char* type_gauche = getType($1);
            char* type_droite = $3.type;

            // 2. Vérification des types
            if (!compatible(type_gauche, type_droite)) {
                printf("ERREUR SEMANTIQUE : ligne %d : incompatibilité entre %s et %s\n",
                       ligne, type_gauche, type_droite);
            }

            // GENERATION QUADRUPLET
            generer_quad("=", $3.place, "", $1);

            // Marquer initialisée
            setInitialisee($1);
        }
    }
;

/* ===== EXPRESSIONS ===== */

expression:

    /* ===== CONSTANTE ENTIERE ===== */
    INT_CONST {
        char buffer[20];
        sprintf(buffer, "%d", $1);

        char* temp = newTemp();
        generer_quad("=", buffer, "", temp);

        $$.type = "INTEGER";
        $$.place = temp;
    }

    /* ===== CONSTANTE FLOAT ===== */
    | FLOAT_CONST {
        char buffer[20];
        sprintf(buffer, "%f", $1);

        char* temp = newTemp();
        generer_quad("=", buffer, "", temp);

        $$.type = "FLOAT";
        $$.place = temp;
    }

    /* ===== IDENTIFICATEUR ===== */
    | IDF {
        if (!existe($1)) {
            printf("❌ %s non déclaré\n", $1);
        }

        if (!estInitialisee($1)) {
            printf("⚠️ variable non initialisée : %s\n", $1);
        }

        $$.type = getType($1);
        $$.place = $1;
    }

    /* ===== ADDITION ===== */
    | expression '+' expression {

        if (!compatible($1.type, $3.type)) {
            printf("❌ Type incompatible dans +\n");
        }

        char* temp = newTemp();
        generer_quad("+", $1.place, $3.place, temp);

        $$.type =
            (strcmp($1.type, "FLOAT") == 0 || strcmp($3.type, "FLOAT") == 0)
            ? "FLOAT" : "INTEGER";

        $$.place = temp;
    }

    /* ===== SOUSTRACTION ===== */
    | expression '-' expression {

        if (!compatible($1.type, $3.type)) {
            printf("❌ Type incompatible dans -\n");
        }

        char* temp = newTemp();
        generer_quad("-", $1.place, $3.place, temp);

        $$.type =
            (strcmp($1.type, "FLOAT") == 0 || strcmp($3.type, "FLOAT") == 0)
            ? "FLOAT" : "INTEGER";

        $$.place = temp;
    }

    /* ===== MULTIPLICATION ===== */
    | expression '*' expression {

        if (!compatible($1.type, $3.type)) {
            printf("❌ Type incompatible dans *\n");
        }

        char* temp = newTemp();
        generer_quad("*", $1.place, $3.place, temp);

        $$.type =
            (strcmp($1.type, "FLOAT") == 0 || strcmp($3.type, "FLOAT") == 0)
            ? "FLOAT" : "INTEGER";

        $$.place = temp;
    }

    /* ===== DIVISION ===== */
    | expression '/' expression {

        if (!compatible($1.type, $3.type)) {
            printf("❌ Type incompatible dans /\n");
        }

        // ⚠️ division par zéro (si tu veux améliorer après)
        char* temp = newTemp();
        generer_quad("/", $1.place, $3.place, temp);

        $$.type = "FLOAT";
        $$.place = temp;
    }

    /* ===== PARENTHESES ===== */
    | '(' expression ')' {
        $$ = $2;
    }
    /* ====
;


/* ===== INSTRUCTIONS FOR ===== */
InstructionFor:
    FOR '(' IDF ':' INT_CONST ':' INT_CONST ':' INT_CONST ')' '{' instructions '}'
    {
        // $3 est l'IDF, $5 est le 1er INT_CONST, $7 le 2eme, $9 le 3eme
        if (!existe($3)) {
            printf(" ERREUR SEMANTIQUE : ligne %d : variable %s non declaree\n", ligne, $3);
        } else {
            if (isConstante($3)) {
                printf(" ERREUR SEMANTIQUE : ligne %d : %s est une constante\n", ligne, $3);
            }

            // Vérification du type de l'IDF (doit être INTEGER pour une boucle)
            if (strcmp(getType($3), "INTEGER") != 0) {
                printf(" ERREUR SEMANTIQUE :ligne %d : l'indice du FOR doit etre un INTEGER\n", ligne);
            }

            // Vérification logique : la valeur de fin ($7) doit être > valeur de début ($5)
            if ($9 < 0) {
                printf(" ERREUR SEMANTIQUE : ligne %d : le pas de progression ne peut pas etre negatif\n", ligne);
            }
            
            if ($7 < $5) {
                printf(" ATTENTION ligne %d : la borne de fin est inferieure a la borne de debut\n", ligne);
            }

            setInitialisee($3);
        }
    }
    ;
/* ===== INSTRUCTIONS WHILE ===== */
InstructionWhile:
    WHILE '(' condition ')' '{' instructions '}'
    {
        if (strcmp($3.type, "INTEGER") != 0) {
            printf("ERREUR SEMANTIQUE: Erreur ligne %d : La condition du WHILE doit être de type INTEGER\n", ligne);
        }
    }
    ;
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
    ;

/*=====CONDITION===========*/
condition : | expression '>' expression {
    char* temp = newTemp();
    generer_quad(">", $1.place, $3.place, temp);

    $$.type = "INTEGER";
    $$.place = temp;
}
| expression '<' expression{ $$ = strdup("INTEGER"); }
|expression EQ expression{ $$ = strdup("INTEGER"); }
|expression LE expression { $$ = strdup("INTEGER"); }
|expression GE expression { $$ = strdup("INTEGER"); }
|expression '!' expression { $$ = strdup("INTEGER"); }
|condition AND condition { $$ = strdup("INTEGER"); }
|condition OR condition { $$ = strdup("INTEGER"); }
|'!' expression {
    char* temp = newTemp();
    generer_quad("!", $2.place, "", temp);

    $$.type = "INTEGER";
    $$.place = temp;
}

/*=====INSTRUCTION WRITE =====*/
write :
    WRITE expression ';'
    {
        if (strcmp($2, "INTEGER") != 0 && strcmp($2, "FLOAT") != 0) {
            printf("❌ write ne peut afficher que des INTEGER ou FLOAT\n");
        }
    }
    ;

%%

void yyerror(const char *s) {
    printf("Erreur Syntaxique : ligne %d , %s\n", ligne, s);
}