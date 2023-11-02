#include <stdio.h>

int factorial(int n) {
  int fact;
  for (int i = 0; i <= n; i++) {
    if (i == 0) {
      fact = 1;
    }
    else {
      fact *= i;
    }
  }
  return fact;
}

int main(void) {
  int n = -1;
  long double e = 0.00L;
  while (n < 0) {
    printf("Enter a non-negative integer: ");
    scanf("%d", &n);
  }
  for (int i = 0; i <= n; i++) {
    e += 1.0L / factorial(i);
  }
  printf("The %d-th partial sum of the infinite series for e = %.25Lf\n", n, e);
  return 0;
}
