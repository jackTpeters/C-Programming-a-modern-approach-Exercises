#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

  int ok = 1, ch, ch_count;
  FILE *fp_input, *fp_output;

  if (argc != 2 &&
    strlen(argv[1]) > 4 &&
    strrchr(argv[1], '.') &&
    strncmp(strrchr(argv[1], '.'), ".rle", 4)
  ) {
    printf("usage: uncompress_file compressedfile.rle\n");
    ok = 0;
  } else {
    if (fp_input = fopen(argv[1], "rb")) {
      char filename_output[strlen(argv[1]) - 3];
      filename_output[0] = '\0';
      strncat(filename_output, argv[1], sizeof(filename_output)/sizeof(filename_output[0]) - 1);
      if (fp_output = fopen(filename_output, "wb")) {

        while ((ch_count = getc(fp_input)) != EOF) {
          ch = getc(fp_input);
          while (ch_count--) {
            putc(ch, fp_output);
          }
        }
        fclose(fp_output);
      } else {
        printf("unable to write to output file\n");
        ok = 0;
      }
      fclose(fp_input);
    } else {
      printf("unable to open file %s\n");
      ok = 0;
    }
  }

  return ok ? EXIT_SUCCESS : EXIT_FAILURE;
}
