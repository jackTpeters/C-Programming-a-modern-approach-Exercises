#include <stdio.h>

int main(void) {

  int a[100], *p;
  char ch;

  printf("Enter a message: ");
  for (p = a; (ch = getchar()) != '\n' && p < a + 100; p++) {
    *p = ch;
  }

  printf("Reversal is: ");
  for (; p >= a ; p--) {
    putchar(*p);
  }
  printf("\n");

  return 0;
}

