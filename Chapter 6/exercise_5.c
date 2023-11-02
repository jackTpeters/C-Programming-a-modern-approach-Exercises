#include <stdio.h>

int main(void) {
  int n, remainder, reversed;
  printf("Enter an integer: ");
  scanf("%d", &n);
  reversed = 0;
  do {
    remainder = n % 10;
    n = n / 10;
    reversed = reversed * 10 + remainder;
  } while (n != 0);
  printf("The number reversed: %d\n", reversed);
  return 0;
}
