#include <stdio.h>

int main(void) {

  float epsilon, term = 1, sum = 1, product = 1;

  printf("Enter an epsilon (small float): ");
  scanf("%f", &epsilon);

  for (int i = 1; term >= epsilon; i++, product = 1) {
    for (int j = 2; j <= i; j++) {
      product *= j;
    }
    term = 1.0f / product;
    sum += term;
  }

  printf("e = %.2f\n", sum);

  return 0;
}

