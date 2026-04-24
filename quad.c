#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "quad.h"

Quad quads[1000];
int qc = 0;
int tempCount = 0;

// Génération quadruplet
void generer_quad(char* op, char* arg1, char* arg2, char* res) {
    strcpy(quads[qc].op, op);
    strcpy(quads[qc].arg1, arg1);
    strcpy(quads[qc].arg2, arg2);
    strcpy(quads[qc].res, res);
    qc++;
}

// Générer temporaire
char* newTemp() {
    char* temp = (char*) malloc(10);
    sprintf(temp, "T%d", tempCount++);
    return temp;
}

// Affichage
void afficher_quads() {
    printf("\n===== QUADRUPLETS =====\n");
    for (int i = 0; i < qc; i++) {
        printf("%d : (%s , %s , %s , %s)\n",
            i,
            quads[i].op,
            quads[i].arg1,
            quads[i].arg2,
            quads[i].res);
    }
}