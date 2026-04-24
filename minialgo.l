%{
#include "minialgo.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ligne = 1;
int colonne = 1;
%}

 /* Expressions régulières */
ID              [a-zA-Z][a-zA-Z0-9_]{0,7}
INT             [0-9]+
FLOAT           [0-9]+"."[0-9]+

SIGNED_INT      \([+-][0-9]+\)
SIGNED_FLOAT    \([+-][0-9]+"."[0-9]+\)


%%
 
 /* ===== Mots clés ===== */
"PROGRAM"   { colonne += yyleng; return PROGRAM; }
"DECL"      { colonne += yyleng; return DECL; }
"ENDDECL"   { colonne += yyleng; return ENDDECL; }
"BEGIN"     { colonne += yyleng; return BEGIN_T; }
"END"       { colonne += yyleng; return END_T; }
"INTEGER"   { colonne += yyleng; return INTEGER; }
"FLOAT"     { colonne += yyleng; return FLOAT_T; }
"CONST"     { colonne += yyleng; return CONST; }
"IF"        { colonne += yyleng; return IF; }
"ELSE"      { colonne += yyleng; return ELSE; }
"WHILE"     { colonne += yyleng; return WHILE; }
"FOR"       { colonne += yyleng; return FOR; }
"WRITE"     { colonne += yyleng; return WRITE; }
"to"    { colonne += yyleng;return TO; }
"do"    { colonne += yyleng;return DO; }
"&&" { colonne += yyleng; return AND; }
"||" { colonne += yyleng; return OR; }

 /* ===== Constantes signées ===== */
{SIGNED_INT} {
    int val = atoi(yytext + 1);
    if (val < -32768 || val > 32767) {
        printf("❌ Erreur ligne %d, colonne %d : entier hors intervalle \"%s\"\n", ligne, colonne, yytext);
    }
    yylval.ival = val;
    colonne += yyleng;
    return INT_CONST;
}

{SIGNED_FLOAT} {
    yylval.fval = atof(yytext + 1);
    colonne += yyleng;
    return FLOAT_CONST;
}

 /* ===== Constantes normales ===== */
{FLOAT} {
    yylval.fval = atof(yytext);
    colonne += yyleng;
    return FLOAT_CONST;
}

{INT} {
    int val = atoi(yytext);
    if (val < -32768 || val > 32767) {
        printf("❌ Erreur ligne %d, colonne %d : entier hors intervalle \"%s\"\n", ligne, colonne, yytext);
    }
    yylval.ival = val;
    colonne += yyleng;
    return INT_CONST;
}

 /* ===== Identificateurs ===== */
{ID} {
    yylval.str = strdup(yytext);
    colonne += yyleng;
    return IDF;
}

 /* ===== Opérateurs ===== */
"==" { colonne += yyleng; return EQ; }
"!=" { colonne += yyleng; return NEQ; }
">=" { colonne += yyleng; return GE; }
"<=" { colonne += yyleng; return LE; }
"="  { colonne += yyleng ; return EQL; }
">"  { colonne += yyleng; return '>'; }
"<"  { colonne += yyleng; return '<'; }
"+"  { colonne += yyleng; return '+'; }
"-"  { colonne += yyleng; return '-'; }
"*"  { colonne += yyleng; return '*'; }
"/"  { colonne += yyleng; return '/'; }
"!" {colonne += yyleng ; return '!';}


 /* ===== Délimiteurs ===== */
";" { colonne += yyleng; return ';'; }
":" { colonne += yyleng; return ':'; }
"," { colonne += yyleng; return ','; }
"(" { colonne += yyleng; return '('; }
")" { colonne += yyleng; return ')'; }
"{" { colonne += yyleng; return '{'; }
"}" { colonne += yyleng; return '}'; }
"[" { colonne += yyleng; return '['; }
"]" { colonne += yyleng; return ']'; }


 /* ===== Commentaires ===== */
"//".* { colonne += yyleng; }
"/*"(.|\n)*"*/" { colonne += yyleng; }

 /* ===== Espaces ===== */
[ \t]+ { colonne += yyleng; }
\n { ligne++; colonne = 1; }

 /* ===== Erreurs spécifiques ===== */

[0-9]+[a-zA-Z_]+ {
    printf("❌ Erreur ligne %d, colonne %d : identificateur invalide \"%s\"\n", ligne, colonne, yytext);
    colonne += yyleng;
}

[a-zA-Z][a-zA-Z0-9_]{8,} {
    printf("❌ Erreur ligne %d, colonne %d : identificateur trop long \"%s\"\n", ligne, colonne, yytext);
    colonne += yyleng;
}

[+-][0-9]+"."[0-9]+ {
    printf("❌ Erreur ligne %d, colonne %d : réel signé invalide \"%s\"\n", ligne, colonne, yytext);
    colonne += yyleng;
}
 /* ❌ erreur : nombre entre parenthèses sans signe + nombre signee sans parenthese */
 /*[+-][0-9]+ {
    printf("❌ ligne %d : entier signé invalide \"%s\" (doit être entre parenthèses)\n", ligne, yytext);}
 */
 




 /* ===== Erreur générale ===== */
. {
    printf("❌ Erreur ligne %d, colonne %d : symbole inconnu \"%s\"\n", ligne, colonne, yytext);
    colonne += yyleng;
}

%%

int yywrap() { return 1; }