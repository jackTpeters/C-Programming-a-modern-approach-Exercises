#include <stdio.h>

int main(void) {

  int n;
  float sum = 1, product = 1;

  printf("Enter positive integer: ");
  scanf("%d", &n);

  for (int i = 1; i <= n; i++, product = 1) {
    for (int j = 2; j <= i; j++) {
      product *= j;
    }
    sum += 1.0f / product;
  }

  printf("e = %.2f\n", sum);

  return 0;
}

