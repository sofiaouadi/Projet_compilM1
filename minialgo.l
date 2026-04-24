%{
#include "minialgo.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ligne   = 1;
int colonne = 1;
%}

/* ── Expressions régulières de base ── */
ID           [a-zA-Z][a-zA-Z0-9_]{0,7}
INT          [0-9]+
FLOAT        [0-9]+"."[0-9]+
SIGNED_INT   \([+-][0-9]+\)
SIGNED_FLOAT \([+-][0-9]+"."[0-9]+\)

%%

 /* ─────────────────────────────────────────
    MOTS CLÉS  (doivent précéder la règle ID)
    ───────────────────────────────────────── */
"PROGRAM"   { colonne += yyleng; return PROGRAM;  }
"DECL"      { colonne += yyleng; return DECL;     }
"ENDDECL"   { colonne += yyleng; return ENDDECL;  }
"BEGIN"     { colonne += yyleng; return BEGIN_T;  }
"END"       { colonne += yyleng; return END_T;    }
"INTEGER"   { colonne += yyleng; return INTEGER;  }
"FLOAT"     { colonne += yyleng; return FLOAT_T;  }
"CONST"     { colonne += yyleng; return CONST;    }
"IF"        { colonne += yyleng; return IF;       }
"ELSE"      { colonne += yyleng; return ELSE;     }
"WHILE"     { colonne += yyleng; return WHILE;    }
"FOR"       { colonne += yyleng; return FOR;      }
"WRITE"     { colonne += yyleng; return WRITE;    }
"&&"        { colonne += yyleng; return AND;      }
"||"        { colonne += yyleng; return OR;       }

 /* ─────────────────────────────────────────
    CONSTANTES SIGNÉES  (entre parenthèses)
    ───────────────────────────────────────── */
{SIGNED_INT} {
    /* extraire la valeur sans la parenthèse ouvrante */
    int val = atoi(yytext + 1);
    if (val < -32768 || val > 32767)
        printf("Erreur lexicale ligne %d, col %d : entier hors intervalle \"%s\"\n",
               ligne, colonne, yytext);
    yylval.ival = val;
    colonne += yyleng;
    return INT_CONST;
}

{SIGNED_FLOAT} {
    yylval.fval = atof(yytext + 1);
    colonne += yyleng;
    return FLOAT_CONST;
}

 /* ─────────────────────────────────────────
    CONSTANTES NON SIGNÉES
    ───────────────────────────────────────── */
{FLOAT} {
    yylval.fval = atof(yytext);
    colonne += yyleng;
    return FLOAT_CONST;
}

{INT} {
    int val = atoi(yytext);
    if (val < 0 || val > 32767)
        printf("Erreur lexicale ligne %d, col %d : entier hors intervalle \"%s\"\n",
               ligne, colonne, yytext);
    yylval.ival = val;
    colonne += yyleng;
    return INT_CONST;
}

 /* ─────────────────────────────────────────
    IDENTIFICATEURS
    ───────────────────────────────────────── */
{ID} {
    yylval.str = strdup(yytext);
    colonne   += yyleng;
    return IDF;
}

 /* ─────────────────────────────────────────
    OPÉRATEURS
    ───────────────────────────────────────── */
"=="  { colonne += yyleng; return EQ;  }
"!="  { colonne += yyleng; return NEQ; }
">="  { colonne += yyleng; return GE;  }
"<="  { colonne += yyleng; return LE;  }
"="   { colonne += yyleng; return EQL; }
">"   { colonne += yyleng; return '>'; }
"<"   { colonne += yyleng; return '<'; }
"+"   { colonne += yyleng; return '+'; }
"-"   { colonne += yyleng; return '-'; }
"*"   { colonne += yyleng; return '*'; }
"/"   { colonne += yyleng; return '/'; }
"!"   { colonne += yyleng; return '!'; }

 /* ─────────────────────────────────────────
    DÉLIMITEURS
    ───────────────────────────────────────── */
";"  { colonne += yyleng; return ';'; }
":"  { colonne += yyleng; return ':'; }
","  { colonne += yyleng; return ','; }
"("  { colonne += yyleng; return '('; }
")"  { colonne += yyleng; return ')'; }
"{"  { colonne += yyleng; return '{'; }
"}"  { colonne += yyleng; return '}'; }
"["  { colonne += yyleng; return '['; }
"]"  { colonne += yyleng; return ']'; }

 /* ─────────────────────────────────────────
    COMMENTAIRES
    ───────────────────────────────────────── */
"//"[^\n]*          { colonne += yyleng; }
"/*"([^*]|\*+[^*/])*\*+"/"  {
    /* compter les sauts de ligne dans le commentaire multilignes */
    for (int k = 0; k < yyleng; k++) {
        if (yytext[k] == '\n') { ligne++; colonne = 1; }
        else colonne++;
    }
}

 /* ─────────────────────────────────────────
    ESPACES / SAUT DE LIGNE
    ───────────────────────────────────────── */
[ \t]+  { colonne += yyleng; }
\n      { ligne++; colonne = 1; }

 /* ─────────────────────────────────────────
    ERREURS LEXICALES SPÉCIFIQUES
    ───────────────────────────────────────── */

 /* identificateur commençant par un chiffre */
[0-9]+[a-zA-Z_][a-zA-Z0-9_]* {
    printf("Erreur lexicale ligne %d, col %d : identificateur invalide \"%s\"\n",
           ligne, colonne, yytext);
    colonne += yyleng;
}

 /* identificateur trop long (> 8 caractères) */
[a-zA-Z][a-zA-Z0-9_]{8,} {
    printf("Erreur lexicale ligne %d, col %d : identificateur trop long \"%s\" (max 8 car.)\n",
           ligne, colonne, yytext);
    colonne += yyleng;
}

 /* réel signé sans parenthèses */
[+-][0-9]+"."[0-9]+ {
    printf("Erreur lexicale ligne %d, col %d : reel signe sans parentheses \"%s\"\n",
           ligne, colonne, yytext);
    colonne += yyleng;
}

 /* ─────────────────────────────────────────
    ERREUR GÉNÉRALE (tout caractère inconnu)
    ───────────────────────────────────────── */
. {
    printf("Erreur lexicale ligne %d, col %d : symbole inconnu \"%s\"\n",
           ligne, colonne, yytext);
    colonne += yyleng;
}

%%

int yywrap() { return 1; }
