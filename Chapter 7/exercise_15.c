#include <stdio.h>

int main(void) {
  long double n, fac = 1.0L;
  printf("Enter a positive integer: ");
  scanf("%Lf", &n);
  for (long double i = 1.0L; i <= n; i++) {
    fac *= i;
  }
  printf("Factorial of %Lf: %Lf\n", n, fac);
  return 0;
}
