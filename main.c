#include <stdio.h>
#include <stdlib.h>

extern int yyparse();
extern FILE *yyin;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage : %s <fichier.mga>\n", argv[0]);
        return 1;
    }
    yyin = fopen(argv[1], "r");
    if (!yyin) {
        perror("Impossible d'ouvrir le fichier source");
        return 1;
    }
    printf("=== Compilation de '%s' ===\n\n", argv[1]);
    yyparse();
    fclose(yyin);
    return 0;
}
