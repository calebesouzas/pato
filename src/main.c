#include <stdio.h>
// #include <string.h>
// #include "pato.h"
#include "guides.h"

int main(int argc, char *argv[]) {
  char version[] = "0.0.1-dev";
  FILE *p_pato_file = fopen(argv[1], "r");
  FILE *p_pato_proj_file = fopen(".patox", "r");

  if (argc == 1) {
    printf("Pato Lang\tversion %s\n", version);
    return 0;
  }
  /* Here we check if the first argument for the program
   * is a file, else we'll check if it's a command. */
  if (p_pato_file != NULL || p_pato_proj_file != NULL) {
    return 0;
  }
  fclose(p_pato_file);
  fclose(p_pato_proj_file);
  return 0;
}
