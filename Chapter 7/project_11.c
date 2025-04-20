#include <stdio.h>

int main(void) {

  char first, ch;

  printf("Enter a first and last name: ");
  scanf(" %c", &first);

  while (getchar() != ' ')
    ;
  while ((ch = getchar()) != '\n') {
    putchar(ch);
  }
  printf(", %c\n", first);

  return 0;
}

