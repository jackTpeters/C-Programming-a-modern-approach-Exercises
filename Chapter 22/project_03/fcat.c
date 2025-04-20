#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

  int ret = 0, ch;
  FILE *fp;

  if (argc < 2) {
    printf("usage: fcat filename1 filename2 ...\n");
    ret = EXIT_FAILURE;
  } else {
    for (int i = 1; i < argc && !ret; i++) {
      if (fp = fopen(argv[i], "rb")) {
        while ((ch = getc(fp)) != EOF) {
          putchar(ch);
        }
        fclose(fp);
      } else {
        printf("\n failed to open file %s, aborting\n", argv[i]);
        ret = EXIT_FAILURE;
      }
    }
  }

  return ret;
}

