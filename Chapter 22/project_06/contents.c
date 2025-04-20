#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define OFFSET (int) 10

int main(int argc, char **argv) {

  int ok = 1, ch;
  char buffer_str[OFFSET + 1];
  FILE *fp;

  if (argc != 2) {
    printf("usage: contents filename\n");
    ok = 0;
  } else {
    if (fp = fopen(argv[1], "rb")) {
      printf("Offset               Bytes               Characters\n");
      printf("------   -----------------------------   ----------\n");
      for (int i = 0; (ch = getc(fp)) != EOF; i++) {
        if (!(i % OFFSET)) {
          printf("%6d  ", i);
        }
        printf(" %.2X", ch);
        strncat(buffer_str, isprint(ch) ? (char *) &ch : ".", sizeof(buffer_str) - strlen(buffer_str) - 1);
        if (i % OFFSET == OFFSET - 1) {
          printf("   %s\n", buffer_str);
          buffer_str[0] = '\0';
        }
      }
      if (strlen(buffer_str) < 10) {
        for (int i = 0; i < sizeof(buffer_str) - strlen(buffer_str) - 1; i++) {
          printf("   ");
        }
        printf("   %s\n", buffer_str);
      }
      fclose(fp);
    } else {
      printf("failed to open file %s\n", argv[1]);
      ok = 0;
    }
  }

  return ok ? EXIT_SUCCESS : EXIT_FAILURE;
}

