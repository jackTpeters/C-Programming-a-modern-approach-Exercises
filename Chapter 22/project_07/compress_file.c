#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {

  int ok = 1, ch, prev_ch = '\0', byte_count = 0;
  FILE *fp_input, *fp_output;

  if (argc != 2) {
    printf("usage: compress_file filename\n");
    ok = 0;
  } else {
    if (fp_input = fopen(argv[1], "rb")) {
      char filename_output[strlen(argv[1]) + 5];
      filename_output[0] = '\0';
      strncat(filename_output, argv[1], sizeof(filename_output) - strlen(filename_output) - 1);
      strncat(filename_output, ".rle", sizeof(filename_output) - strlen(filename_output) - 1 );
      if (fp_output = fopen(filename_output, "wb")) {
        do {
          ch = getc(fp_input);
          if (prev_ch == '\0') {
            prev_ch = ch;
          }
          if (ch == prev_ch) {
            byte_count++;
          } else {
            putc(byte_count, fp_output);
            putc(prev_ch, fp_output);
            byte_count = 1;
            prev_ch = ch;
          }
        } while (ch != EOF);
        fclose(fp_output);
      } else {
        printf("unable to open output file for writing\n");
        ok = 0;
      }
      fclose(fp_input);
    } else {
      printf("unable to open file %s\n", argv[1]);
      ok = 0;
    }
  }

  return ok ? EXIT_SUCCESS : EXIT_FAILURE;
}

