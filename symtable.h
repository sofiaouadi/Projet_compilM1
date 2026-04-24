#ifndef SYMTABLE_H
#define SYMTABLE_H

typedef struct {
    char nom[20];
    char type[10];      // "INTEGER" ou "FLOAT"
    int  isConst;       // 1 = constante, 0 = variable
    int  initialisee;   // 1 = initialisée
    int  isTableau;     // 1 = tableau
    int  taille;        // taille du tableau (0 si simple)
} Symbole;

/* CRUD table des symboles */
void inserer(char *nom, char *type, int isConst);
void inserer_tableau(char *nom, char *type, int taille);
int  existe(char *nom);
char *getType(char *nom);
int  isConstante(char *nom);
int  estInitialisee(char *nom);
void setInitialisee(char *nom);
int  isTableau(char *nom);
int  getTaille(char *nom);

/* Affichage & utilitaires */
void afficherTable();
int  compatible(char *t1, char *t2);

#endif /* SYMTABLE_H */
