#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "quad.h"

/* ─────────────────────────────────────────
   Stockage des quadruplets
   ───────────────────────────────────────── */
#define MAX_QUADS 2000
Quad quads[MAX_QUADS];
int  qc         = 0;   /* quad counter   */
int  tempCount  = 0;   /* T0, T1, T2 … */
int  labelCount = 0;   /* L0, L1, L2 … */

/* ─────────────────────────────────────────
   Génération d'un quadruplet
   ───────────────────────────────────────── */
void generer_quad(char *op, char *arg1, char *arg2, char *res) {
    if (qc >= MAX_QUADS) { fprintf(stderr,"Trop de quadruplets\n"); return; }
    strncpy(quads[qc].op,   op   ? op   : "", sizeof(quads[qc].op)   - 1);
    strncpy(quads[qc].arg1, arg1 ? arg1 : "", sizeof(quads[qc].arg1) - 1);
    strncpy(quads[qc].arg2, arg2 ? arg2 : "", sizeof(quads[qc].arg2) - 1);
    strncpy(quads[qc].res,  res  ? res  : "", sizeof(quads[qc].res)  - 1);
    qc++;
}

/* ─────────────────────────────────────────
   Nouveau temporaire  T0, T1 …
   ───────────────────────────────────────── */
char *newTemp() {
    char *t = (char *)malloc(12);
    sprintf(t, "T%d", tempCount++);
    return t;
}

/* ─────────────────────────────────────────
   Nouveau label  L0, L1 …
   ───────────────────────────────────────── */
char *newLabel() {
    char *l = (char *)malloc(12);
    sprintf(l, "L%d", labelCount++);
    return l;
}

/* Index du prochain quad */
int getQC() { return qc; }

/* ─────────────────────────────────────────
   Affichage des quadruplets
   ───────────────────────────────────────── */
void afficher_quads() {
    printf("\n-----------------------------------------------------------\n");
    printf(  "|                   QUADRUPLETS                           |\n");
    printf(  "-----------------------------------------------------------\n");
    printf(  "|  Idx  |    OP    |   ARG1   |   ARG2   |    RESULTAT    |\n");
    printf(  "-----------------------------------------------------------\n");
    for (int i = 0; i < qc; i++) {
        printf("|  %3d  | %-8s | %-8s | %-8s | %-14s |\n",
               i,
               quads[i].op,
               quads[i].arg1,
               quads[i].arg2,
               quads[i].res);
    }
    printf("-----------------------------------------------------------\n");
}

/* ═══════════════════════════════════════════
   OPTIMISATION DU CODE INTERMÉDIAIRE
   ═══════════════════════════════════════════

   Passes appliquées :
   1. Propagation de constantes  (= N, "" → remplace les uses par N)
   2. Élimination des affectations mortes  (= T, "" → résultat jamais utilisé)
   3. Simplification des expressions constantes  (op N1 N2)
   4. Élimination du code mort (goto vers le label juste après)
   ─────────────────────────────────────────── */

/* utilitaire : est-ce une constante numérique ? */
static int estNombre(const char *s) {
    if (!s || !*s) return 0;
    char *end;
    strtod(s, &end);
    return (*end == '\0');
}

/* utilitaire : le quad i est-il une copie simple ?  (op = "=" et arg2 vide) */
static int estCopie(int i) {
    return strcmp(quads[i].op, "=") == 0 && quads[i].arg2[0] == '\0';
}

/* ── PASSE 1 : propagation de constantes ── */
static void passe_propagation() {
    for (int i = 0; i < qc; i++) {
        if (estCopie(i) && estNombre(quads[i].arg1)) {
            /* quad i : res = constante  →  remplacer toutes les occurrences de res par arg1 */
            const char *cste = quads[i].arg1;
            const char *var  = quads[i].res;
            for (int j = i + 1; j < qc; j++) {
                if (strcmp(quads[j].arg1, var) == 0) strncpy(quads[j].arg1, cste, 29);
                if (strcmp(quads[j].arg2, var) == 0) strncpy(quads[j].arg2, cste, 29);
                /* stopper si la variable est réaffectée */
                if (strcmp(quads[j].res, var) == 0) break;
            }
        }
    }
}

/* ── PASSE 2 : simplification d'expressions constantes ── */
static void passe_constantes() {
    for (int i = 0; i < qc; i++) {
        if (!estNombre(quads[i].arg1) || !estNombre(quads[i].arg2)) continue;
        double a = atof(quads[i].arg1);
        double b = atof(quads[i].arg2);
        double r = 0;
        int    ok = 1;
        if      (strcmp(quads[i].op, "+") == 0) r = a + b;
        else if (strcmp(quads[i].op, "-") == 0) r = a - b;
        else if (strcmp(quads[i].op, "*") == 0) r = a * b;
        else if (strcmp(quads[i].op, "/") == 0) {
            if (b == 0) { printf("Erreur semantique : division par zero\n"); ok = 0; }
            else r = a / b;
        }
        else ok = 0;

        if (ok) {
            /* remplacer le quad par une simple copie */
            char buf[30];
            if (r == (long)r) sprintf(buf, "%ld", (long)r);
            else              sprintf(buf, "%g",   r);
            strcpy(quads[i].op,   "=");
            strcpy(quads[i].arg1, buf);
            strcpy(quads[i].arg2, "");
        }
    }
}

/* ── PASSE 3 : élimination des temporaires inutilisés ── */
static void passe_mort() {
    int used[MAX_QUADS] = {0};
    /* marquer les résultats utilisés comme arg1 ou arg2 ailleurs */
    for (int i = 0; i < qc; i++) {
        for (int j = 0; j < qc; j++) {
            if (strcmp(quads[j].arg1, quads[i].res) == 0 ||
                strcmp(quads[j].arg2, quads[i].res) == 0)
            {
                used[i] = 1;
                break;
            }
        }
        /* un quad dont le résultat est une variable du programme est toujours utile */
        if (quads[i].res[0] && quads[i].res[0] != 'T') used[i] = 1;
        /* labels, sauts, affectations finales toujours utiles */
        if (strcmp(quads[i].op, "goto")  == 0) used[i] = 1;
        if (strcmp(quads[i].op, "if")    == 0) used[i] = 1;
        if (strcmp(quads[i].op, "label") == 0) used[i] = 1;
        if (strcmp(quads[i].op, "write") == 0) used[i] = 1;
        if (quads[i].res[0] == '\0')            used[i] = 1;
    }
    /* compacter le tableau en supprimant les quads inutiles */
    int nouveau = 0;
    for (int i = 0; i < qc; i++)
        if (used[i]) quads[nouveau++] = quads[i];
    int supprime = qc - nouveau;
    qc = nouveau;
    if (supprime > 0)
        printf("  Optimisation : %d quadruplet(s) mort(s) elimine(s)\n", supprime);
}

/* ── PASSE 4 : goto vers label immediatement suivant ── */
static void passe_goto_mort() {
    for (int i = 0; i < qc - 1; i++) {
        if (strcmp(quads[i].op, "goto") == 0) {
            /* chercher si le label cible est le quad juste apres */
            if (strcmp(quads[i+1].op,  "label") == 0 &&
                strcmp(quads[i+1].res,  quads[i].res) == 0)
            {
                /* supprimer le goto inutile */
                for (int j = i; j < qc - 1; j++) quads[j] = quads[j+1];
                qc--;
                i--;
            }
        }
    }
}

void optimiser_quads() {
    printf("\n--- OPTIMISATION DU CODE INTERMEDIAIRE ---\n");
    int avant = qc;
    passe_propagation();
    passe_constantes();
    passe_mort();
    passe_goto_mort();
    printf("  Quadruplets avant : %d  |  apres : %d\n", avant, qc);
}

/* ═══════════════════════════════════════════
   GÉNÉRATION ASSEMBLEUR 8086
   ═══════════════════════════════════════════
   Convention :
   - Variables/temporaires → segment DATA (.data)
   - Entiers  → DW  (16 bits)
   - Résultat de / → toujours traité comme mot signé
   ─────────────────────────────────────────── */

/* liste des variables/temporaires à déclarer en DATA */
#define MAX_VARS 300
static char vars_asm[MAX_VARS][30];
static int  nb_vars = 0;

static int var_connue(const char *v) {
    if (!v || !*v) return 1;
    if (estNombre(v))  return 1;
    for (int i = 0; i < nb_vars; i++)
        if (strcmp(vars_asm[i], v) == 0) return 1;
    return 0;
}
static void enregistrer_var(const char *v) {
    if (!v || !*v || estNombre(v)) return;
    if (strcmp(v,"") == 0) return;
    if (!var_connue(v)) strncpy(vars_asm[nb_vars++], v, 29);
}

/* émettre un opérande vers AX */
static void load_ax(FILE *f, const char *v) {
    if (estNombre(v))  fprintf(f, "    MOV AX, %s\n", v);
    else               fprintf(f, "    MOV AX, [%s]\n", v);
}
/* émettre un opérande vers BX */
static void load_bx(FILE *f, const char *v) {
    if (estNombre(v))  fprintf(f, "    MOV BX, %s\n", v);
    else               fprintf(f, "    MOV BX, [%s]\n", v);
}

void generer_asm_8086(const char *fichier) {
    /* collecter toutes les variables */
    nb_vars = 0;
    for (int i = 0; i < qc; i++) {
        enregistrer_var(quads[i].res);
        enregistrer_var(quads[i].arg1);
        enregistrer_var(quads[i].arg2);
    }

    FILE *f = fopen(fichier, "w");
    if (!f) { perror("Impossible d'ouvrir le fichier ASM"); return; }

    /* ── segment DATA ── */
    fprintf(f, "; -----------------------------------------------------------\n");
    fprintf(f, ";   Code genere automatiquement par MiniAlgo Compiler\n");
    fprintf(f, "; -----------------------------------------------------------\n\n");
    fprintf(f, ".MODEL SMALL\n");
    fprintf(f, ".STACK 100h\n\n");
    fprintf(f, ".DATA\n");
    for (int i = 0; i < nb_vars; i++)
        fprintf(f, "    %s DW 0\n", vars_asm[i]);
    /* buffer pour l'affichage (WRITE) */
    fprintf(f, "    _buf DB 6 DUP(?), '$'\n");
    fprintf(f, "\n.CODE\n");
    fprintf(f, "MAIN PROC\n");
    fprintf(f, "    MOV AX, @DATA\n");
    fprintf(f, "    MOV DS, AX\n\n");

    /* ── translation des quadruplets ── */
    for (int i = 0; i < qc; i++) {
        char *op   = quads[i].op;
        char *a1   = quads[i].arg1;
        char *a2   = quads[i].arg2;
        char *res  = quads[i].res;

        fprintf(f, "    ; [%d] (%s, %s, %s, %s)\n", i, op, a1, a2, res);

        if (strcmp(op, "=") == 0 && a2[0] == '\0') {
            /* affectation simple */
            load_ax(f, a1);
            fprintf(f, "    MOV [%s], AX\n", res);

        } else if (strcmp(op, "+") == 0) {
            load_ax(f, a1);
            load_bx(f, a2);
            fprintf(f, "    ADD AX, BX\n");
            fprintf(f, "    MOV [%s], AX\n", res);

        } else if (strcmp(op, "-") == 0) {
            load_ax(f, a1);
            load_bx(f, a2);
            fprintf(f, "    SUB AX, BX\n");
            fprintf(f, "    MOV [%s], AX\n", res);

        } else if (strcmp(op, "*") == 0) {
            load_ax(f, a1);
            load_bx(f, a2);
            fprintf(f, "    IMUL BX\n");
            fprintf(f, "    MOV [%s], AX\n", res);

        } else if (strcmp(op, "/") == 0) {
            load_ax(f, a1);
            fprintf(f, "    CWD\n");   /* étendre AX → DX:AX */
            load_bx(f, a2);
            fprintf(f, "    IDIV BX\n");
            fprintf(f, "    MOV [%s], AX\n", res);

        } else if (strcmp(op, "label") == 0) {
            fprintf(f, "%s:\n", res);

        } else if (strcmp(op, "goto") == 0) {
            fprintf(f, "    JMP %s\n", res);

        } else if (strcmp(op, "ifFalse") == 0) {
            /* ifFalse cond goto label */
            load_ax(f, a1);
            fprintf(f, "    CMP AX, 0\n");
            fprintf(f, "    JE %s\n", res);

        } else if (strcmp(op, ">") == 0) {
            load_ax(f, a1);
            load_bx(f, a2);
            fprintf(f, "    CMP AX, BX\n");
            fprintf(f, "    MOV AX, 0\n");
            fprintf(f, "    JLE _skip%d\n", i);
            fprintf(f, "    MOV AX, 1\n");
            fprintf(f, "_skip%d:\n", i);
            fprintf(f, "    MOV [%s], AX\n", res);

        } else if (strcmp(op, "<") == 0) {
            load_ax(f, a1);
            load_bx(f, a2);
            fprintf(f, "    CMP AX, BX\n");
            fprintf(f, "    MOV AX, 0\n");
            fprintf(f, "    JGE _skip%d\n", i);
            fprintf(f, "    MOV AX, 1\n");
            fprintf(f, "_skip%d:\n", i);
            fprintf(f, "    MOV [%s], AX\n", res);

        } else if (strcmp(op, "==") == 0) {
            load_ax(f, a1);
            load_bx(f, a2);
            fprintf(f, "    CMP AX, BX\n");
            fprintf(f, "    MOV AX, 0\n");
            fprintf(f, "    JNE _skip%d\n", i);
            fprintf(f, "    MOV AX, 1\n");
            fprintf(f, "_skip%d:\n", i);
            fprintf(f, "    MOV [%s], AX\n", res);

        } else if (strcmp(op, "!=") == 0) {
            load_ax(f, a1);
            load_bx(f, a2);
            fprintf(f, "    CMP AX, BX\n");
            fprintf(f, "    MOV AX, 0\n");
            fprintf(f, "    JE _skip%d\n", i);
            fprintf(f, "    MOV AX, 1\n");
            fprintf(f, "_skip%d:\n", i);
            fprintf(f, "    MOV [%s], AX\n", res);

        } else if (strcmp(op, ">=") == 0) {
            load_ax(f, a1);
            load_bx(f, a2);
            fprintf(f, "    CMP AX, BX\n");
            fprintf(f, "    MOV AX, 0\n");
            fprintf(f, "    JL _skip%d\n", i);
            fprintf(f, "    MOV AX, 1\n");
            fprintf(f, "_skip%d:\n", i);
            fprintf(f, "    MOV [%s], AX\n", res);

        } else if (strcmp(op, "<=") == 0) {
            load_ax(f, a1);
            load_bx(f, a2);
            fprintf(f, "    CMP AX, BX\n");
            fprintf(f, "    MOV AX, 0\n");
            fprintf(f, "    JG _skip%d\n", i);
            fprintf(f, "    MOV AX, 1\n");
            fprintf(f, "_skip%d:\n", i);
            fprintf(f, "    MOV [%s], AX\n", res);

        } else if (strcmp(op, "!") == 0) {
            load_ax(f, a1);
            fprintf(f, "    CMP AX, 0\n");
            fprintf(f, "    MOV AX, 0\n");
            fprintf(f, "    JNE _skip%d\n", i);
            fprintf(f, "    MOV AX, 1\n");
            fprintf(f, "_skip%d:\n", i);
            fprintf(f, "    MOV [%s], AX\n", res);

        } else if (strcmp(op, "write") == 0) {
            /* affichage entier via DOS int 21h  (conversion → chaîne dans _buf) */
            fprintf(f, "    ; --- WRITE %s ---\n", a1);
            load_ax(f, a1);
            fprintf(f, "    LEA DI, _buf+5\n");
            fprintf(f, "    MOV BYTE PTR [DI+1], '$'\n");
            fprintf(f, "    CWD\n");
            fprintf(f, "    PUSH AX\n");
            fprintf(f, "    OR AX, AX\n");
            fprintf(f, "    JNS _pos%d\n", i);
            fprintf(f, "    NEG AX\n");
            fprintf(f, "_pos%d:\n", i);
            fprintf(f, "_wloop%d:\n", i);
            fprintf(f, "    MOV BX, 10\n");
            fprintf(f, "    XOR DX, DX\n");
            fprintf(f, "    DIV BX\n");
            fprintf(f, "    ADD DL, '0'\n");
            fprintf(f, "    MOV [DI], DL\n");
            fprintf(f, "    DEC DI\n");
            fprintf(f, "    OR AX, AX\n");
            fprintf(f, "    JNZ _wloop%d\n", i);
            fprintf(f, "    POP AX\n");
            fprintf(f, "    JS _neg%d\n", i);
            fprintf(f, "    INC DI\n");
            fprintf(f, "    JMP _print%d\n", i);
            fprintf(f, "_neg%d:\n", i);
            fprintf(f, "    MOV BYTE PTR [DI], '-'\n");
            fprintf(f, "_print%d:\n", i);
            fprintf(f, "    MOV AH, 09h\n");
            fprintf(f, "    MOV DX, DI\n");
            fprintf(f, "    INT 21h\n");
            /* newline */
            fprintf(f, "    MOV AH, 02h\n");
            fprintf(f, "    MOV DL, 0Dh\n");
            fprintf(f, "    INT 21h\n");
            fprintf(f, "    MOV DL, 0Ah\n");
            fprintf(f, "    INT 21h\n");
        }
        fprintf(f, "\n");
    }

    /* fin du programme */
    fprintf(f, "    ; --- FIN ---\n");
    fprintf(f, "    MOV AH, 4Ch\n");
    fprintf(f, "    INT 21h\n");
    fprintf(f, "MAIN ENDP\n");
    fprintf(f, "END MAIN\n");

    fclose(f);
    printf("\nCode assembleur 8086 genere dans '%s'\n", fichier);
}
