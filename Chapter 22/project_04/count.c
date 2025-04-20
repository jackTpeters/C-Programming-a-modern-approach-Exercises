#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {

  int i, ok = 1, line_count = 0, word_count = 0, char_count = 0;
  char line[1000], ch, ch_prev;
  FILE *fp;

  if (argc != 2) {
    printf("usage: count filename\n");
    ok = 0;
  } else {
    if (fp = fopen(argv[1], "rb")) {
      while (fgets(line, sizeof(line), fp)) {
        line_count++;
        for (i = 0, ch_prev = '\0'; i < sizeof(line) && (ch = line[i]) != '\0'; i++, ch_prev = ch) {
          if (ch == ' ' && ch_prev != ' ') {
            word_count++;
          }
        }
        word_count++; // count last word in line
        char_count += (i - 1);
      }
      fclose(fp);
      printf("Line count: %d\n", line_count);
      printf("Word count: %d\n", word_count);
      printf("Character count: %d\n", char_count);
    } else {
      printf("Can't open file %s\n", argv[1]);
      ok = 0;
    }
  }

  return ok ? EXIT_SUCCESS : EXIT_FAILURE;
}

