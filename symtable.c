#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "symtable.h"

#define MAX_SYMBOLES 200

Symbole table[MAX_SYMBOLES];
int taille = 0;

/* ─────────────────────────────────────────
   INSERTION variable simple
   ───────────────────────────────────────── */
void inserer(char *nom, char *type, int isConst) {
    for (int i = 0; i < taille; i++) {
        if (strcmp(table[i].nom, nom) == 0) {
            printf("Erreur semantique : double declaration de '%s'\n", nom);
            return;
        }
    }
    if (taille >= MAX_SYMBOLES) {
        printf("Erreur interne : table des symboles pleine\n");
        return;
    }
    strncpy(table[taille].nom,  nom,  sizeof(table[taille].nom)  - 1);
    strncpy(table[taille].type, type, sizeof(table[taille].type) - 1);
    table[taille].isConst    = isConst;
    table[taille].initialisee = 0;
    table[taille].isTableau  = 0;
    table[taille].taille     = 0;
    taille++;
}

/* ─────────────────────────────────────────
   INSERTION tableau
   ───────────────────────────────────────── */
void inserer_tableau(char *nom, char *type, int sz) {
    for (int i = 0; i < taille; i++) {
        if (strcmp(table[i].nom, nom) == 0) {
            printf("Erreur semantique : double declaration de '%s'\n", nom);
            return;
        }
    }
    if (sz <= 0) {
        printf("Erreur semantique : taille de tableau invalide pour '%s'\n", nom);
        return;
    }
    if (taille >= MAX_SYMBOLES) {
        printf("Erreur interne : table des symboles pleine\n");
        return;
    }
    strncpy(table[taille].nom,  nom,  sizeof(table[taille].nom)  - 1);
    strncpy(table[taille].type, type, sizeof(table[taille].type) - 1);
    table[taille].isConst    = 0;
    table[taille].initialisee = 1;   /* un tableau est toujours "déclaré" */
    table[taille].isTableau  = 1;
    table[taille].taille     = sz;
    taille++;
}

/* ─────────────────────────────────────────
   RECHERCHE
   ───────────────────────────────────────── */
int existe(char *nom) {
    for (int i = 0; i < taille; i++)
        if (strcmp(table[i].nom, nom) == 0) return 1;
    return 0;
}

char *getType(char *nom) {
    for (int i = 0; i < taille; i++)
        if (strcmp(table[i].nom, nom) == 0) return table[i].type;
    return "UNKNOWN";
}

int isConstante(char *nom) {
    for (int i = 0; i < taille; i++)
        if (strcmp(table[i].nom, nom) == 0) return table[i].isConst;
    return 0;
}

int estInitialisee(char *nom) {
    for (int i = 0; i < taille; i++)
        if (strcmp(table[i].nom, nom) == 0) return table[i].initialisee;
    return 0;
}

void setInitialisee(char *nom) {
    for (int i = 0; i < taille; i++)
        if (strcmp(table[i].nom, nom) == 0) { table[i].initialisee = 1; return; }
}

int isTableau(char *nom) {
    for (int i = 0; i < taille; i++)
        if (strcmp(table[i].nom, nom) == 0) return table[i].isTableau;
    return 0;
}

int getTaille(char *nom) {
    for (int i = 0; i < taille; i++)
        if (strcmp(table[i].nom, nom) == 0) return table[i].taille;
    return 0;
}

/* ─────────────────────────────────────────
   AFFICHAGE
   ───────────────────────────────────────── */
void afficherTable() {
    printf("\n╔══════════════════════════════════════════════════════╗\n");
    printf(  "║              TABLE DES SYMBOLES                     ║\n");
    printf(  "╠═══════════╦═════════╦═══════╦══════╦═══════╦═══════╣\n");
    printf(  "║ Nom       ║ Type    ║ Const ║ Init ║ Tab.  ║ Taille║\n");
    printf(  "╠═══════════╬═════════╬═══════╬══════╬═══════╬═══════╣\n");
    for (int i = 0; i < taille; i++) {
        printf("║ %-9s ║ %-7s ║  %3d  ║  %3d ║  %3d  ║  %4d ║\n",
               table[i].nom, table[i].type,
               table[i].isConst, table[i].initialisee,
               table[i].isTableau, table[i].taille);
    }
    printf(  "╚═══════════╩═════════╩═══════╩══════╩═══════╩═══════╝\n");
}

/* ─────────────────────────────────────────
   COMPATIBILITÉ DE TYPES
   INTEGER ↔ FLOAT autorisé (promotion implicite)
   ───────────────────────────────────────── */
int compatible(char *t1, char *t2) {
    if (!t1 || !t2) return 0;
    if (strcmp(t1, t2) == 0)                                       return 1;
    if (strcmp(t1,"FLOAT")==0   && strcmp(t2,"INTEGER")==0)        return 1;
    if (strcmp(t1,"INTEGER")==0 && strcmp(t2,"FLOAT")==0)          return 1;
    return 0;
}
