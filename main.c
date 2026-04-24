#include <stdio.h>
#include "symtable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern int yyparse();

int main()
{
  /*extern int yydebug;
  yydebug = 1;*/
  printf("=== Lancement du compilateur ===\n");

  yyparse(); // lance parser → lexer → semantique
  afficherTable();

  printf("=== Fin ===\n");
  return 0;
}