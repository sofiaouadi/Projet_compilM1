#ifndef QUAD_H
#define QUAD_H

/* ─────────────────────────────────────────
   Structure d'un quadruplet
   (op, arg1, arg2, résultat)
   ───────────────────────────────────────── */
typedef struct {
    char op[10];
    char arg1[30];
    char arg2[30];
    char res[30];
} Quad;

/* Génération */
void  generer_quad(char *op, char *arg1, char *arg2, char *res);
char *newTemp();
char *newLabel();          /* génère L0, L1, L2 … */
int   getQC();             /* retourne l'index courant (prochain quad) */

/* Affichage */
void afficher_quads();

/* Optimisation du code intermédiaire */
void optimiser_quads();

/* Génération code assembleur 8086 */
void generer_asm_8086(const char *fichier);

#endif /* QUAD_H */
