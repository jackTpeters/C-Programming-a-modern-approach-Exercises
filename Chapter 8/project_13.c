#include <stdio.h>

int main(void) {

  char ch, first, last[20];
  int len_last;

  printf("Enter a first and last name: ");
  scanf(" %c", &first);

  while (getchar() != ' ')
    ;
  for (int i = 0; (ch = getchar()) != '\n' && (int) (sizeof(last) / sizeof(last[0])); i++, len_last = i) {
    last[i] = ch;
  }

  printf("You entered the name: ");
  for (int i = 0; i < len_last; i++) {
    putchar(last[i]);
  }
  printf(", %c\n", first);

  return 0;
}

