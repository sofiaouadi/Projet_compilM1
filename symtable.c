#include <stdio.h>
#include <string.h>
#include "symtable.h"

#define MAX 100

Symbole table[MAX];
int taille = 0;

void inserer(char *nom, char *type, int isConst)
{
    for (int i = 0; i < taille; i++)
    {
        if (strcmp(table[i].nom, nom) == 0)
        {
            printf("❌ Erreur sémantique : double déclaration de %s\n", nom);
            return;
        }
    }

    strcpy(table[taille].nom, nom);
    strcpy(table[taille].type, type);
    table[taille].isConst = isConst;
    table[taille].initialisee = 0;
    taille++;
}

int existe(char *nom)
{
    for (int i = 0; i < taille; i++)
    {
        if (strcmp(table[i].nom, nom) == 0)
            return 1;
    }
    return 0;
}

char *getType(char *nom)
{
    for (int i = 0; i < taille; i++)
    {
        if (strcmp(table[i].nom, nom) == 0)
            return table[i].type;
    }
    return NULL;
}

int isConstante(char *nom)
{
    for (int i = 0; i < taille; i++)
    {
        if (strcmp(table[i].nom, nom) == 0)
            return table[i].isConst;
    }
    return 0;
}

int estInitialisee(char *nom)
{
    for (int i = 0; i < taille; i++)
    {
        if (strcmp(table[i].nom, nom) == 0)
            return table[i].initialisee;
    }
    return 0;
}

void setInitialisee(char *nom)
{
    for (int i = 0; i < taille; i++)
    {
        if (strcmp(table[i].nom, nom) == 0)
        {
            table[i].initialisee = 1;
        }
    }
}

void afficherTable()
{
    printf("\n===== TABLE DES SYMBOLES =====\n");
    for (int i = 0; i < taille; i++)
    {
        printf("%s | %s | const=%d | init=%d\n",
               table[i].nom,
               table[i].type,
               table[i].isConst,
               table[i].initialisee);
    }
}

int compatible(char *t1, char *t2)
{
    if (strcmp(t1, t2) == 0)
        return 1;

    if (strcmp(t1, "FLOAT") == 0 && strcmp(t2, "INTEGER") == 0)
        return 1;

    if (strcmp(t1, "INTEGER") == 0 && strcmp(t2, "FLOAT") == 0)
        return 1;

    return 0;
}