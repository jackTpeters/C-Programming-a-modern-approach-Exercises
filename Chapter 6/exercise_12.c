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
  float n = -1.0f;
  float term;
  long double e = 0.00L;
  while (n <= 0.0f) {
    printf("Enter a small, positive floating-point number: ");
    scanf("%f", &n);
  }
  for (int i = 0; ; i++) {
    term = 1.0L / factorial(i);
    if (term < n) {
      break;
    }
    else {
      e += term;
    }
  }
  printf("e = %.25Lf\n", e);
  return 0;
}
