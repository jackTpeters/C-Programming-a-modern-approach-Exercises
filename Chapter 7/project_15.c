#include <stdio.h>

int main(void) {

  int n;
  long double product = 1;

  printf("Enter a positive integer: ");
  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {
    product *= i;
  }

  printf("Factorial of %d: %.Lf\n", n, product);

  return 0;
}

