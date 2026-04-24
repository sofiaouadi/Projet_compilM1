#ifndef QUAD_H
#define QUAD_H

typedef struct {
    char op[10];
    char arg1[20];
    char arg2[20];
    char res[20];
} Quad;

void generer_quad(char* op, char* arg1, char* arg2, char* res);
char* newTemp();
void afficher_quads();

#endif