#include <stdio.h>
#include <ctype.h>

int main(void) {

  char ch, prev_ch = ' ';

  while ((ch = getchar()) != EOF) {
    if (isspace(prev_ch) && !isspace(ch)) {
      ch = toupper(ch);
    }
    putchar(ch);
    prev_ch = ch;
  }
  putchar('\n');

  return 0;
}

