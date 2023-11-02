#include <stdio.h>

int main(void) {
  int m, n, remainder, gcd;
  printf("Enter two integers: ");
  scanf("%d %d", &m, &n);
  while (n != 0) {
    remainder = m % n;
    m = n;
    n = remainder;
  }
  printf("Greatest common divisor: %d\n", m);
  return 0;
}
