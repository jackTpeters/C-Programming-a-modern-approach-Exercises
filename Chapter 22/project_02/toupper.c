#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int main(int argc, char **argv) {

  int ret = 0, ch;
  FILE *fp;

  if (argc != 2) {
    printf("usage: toupper filename\n");
    ret = EXIT_FAILURE;
  } else {
    if (fp = fopen(argv[1], "rb")) {
      while ((ch = getc(fp)) != EOF) {
        if (isalpha(ch)) {
          ch = toupper(ch);
        }
        putchar(ch);
      }
      fclose(fp);
    } else {
      ret = EXIT_FAILURE;
    }
  }

  return ret;
}

