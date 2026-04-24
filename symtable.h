#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

typedef struct
{
    char nom[20];
    char type[10]; // "INTEGER" ou "FLOAT"
    int isConst;
    int initialisee;
} Symbole;

void inserer(char *nom, char *type, int isConst);
int existe(char *nom);
char *getType(char *nom);
int isConstante(char *nom);
int estInitialisee(char *nom);
void setInitialisee(char *nom);
void afficherTable();
int compatible(char *t1, char *t2);

#endif