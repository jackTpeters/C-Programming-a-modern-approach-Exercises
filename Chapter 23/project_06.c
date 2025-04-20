#include <stdio.h>
#include <ctype.h>

int main(void) {

  char ch;

  while ((ch = getchar()) != EOF) {
    if (ch != '\n' && iscntrl(ch)) {
      ch = '?';
    }
    putchar(ch);
  }
  putchar('\n');

  return 0;
}

