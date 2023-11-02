#include <stdio.h>

int main(void) {
  int num, den, m, n, remainder;
  printf("Enter a fraction: ");
  scanf("%d/%d", &num, &den);
  m = num;
  n = den;
  while (n != 0) {
    remainder = m % n;
    m = n;
    n = remainder;
  }
  printf("In lowest terms: %d/%d\n", num / m, den / m);
  return 0;
}
