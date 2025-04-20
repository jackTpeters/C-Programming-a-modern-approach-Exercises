#include <stdlib.h>
#include <stdio.h>

#define KEY (char) '&'

int main(int argc, char **argv) {

  int ok = 1, ch;
  FILE *fp_input, *fp_output;

  if (argc != 3) {
    printf("usage: xor inputfile outputfile\n");
    ok = 0;
  } else {
    if (fp_input = fopen(argv[1], "rb")){
      if (fp_output = fopen(argv[2], "wb")) {
        while ((ch = getc(fp_input)) != EOF) {
          putc(ch ^ KEY, fp_output);
        }
        fclose(fp_output);
      } else {
        printf("unable to open output file %s\n", argv[2]);
        ok = 0;
      }
      fclose(fp_input);
    } else {
      printf("unable to open input file %s\n", argv[1]);
      ok = 0;
    }
  }

  return ok ? EXIT_SUCCESS : EXIT_FAILURE;
}

