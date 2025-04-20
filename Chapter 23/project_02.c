#include <stdio.h>
#include <ctype.h>

int main(void) {

  char ch;

  while ((ch = getchar()) != EOF) {
    if (!isspace(ch)) {
      putchar(ch);
    }
  }
  putchar('\n');

  return 0;
}

