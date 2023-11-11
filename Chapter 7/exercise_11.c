#include <stdio.h>

int main(void) {
  char ch, first;
  printf("Enter a first and last name: ");
  while ((ch = getchar()) == ' ') {
    ;
  }
  first = ch;
  while ((ch = getchar()) != ' ') {
    ;
  }
  while ((ch = getchar()) == ' ') {
    ;
  }
  putchar(ch);
  while ((ch = getchar()) != '\n') {
    if (ch == ' ') {
      continue;
    }
    else {
      putchar(ch);
    }
  }
  printf(", %c.\n", first);
  return 0;
}
