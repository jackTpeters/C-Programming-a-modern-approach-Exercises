#include <stdio.h>

void reduce(int numerator,
            int denominator,
            int *reduced_numerator,
            int *reduced_denominator) {

  int temp;

  // compute GCD
  *reduced_numerator = numerator;
  *reduced_denominator = denominator;
  while (denominator != 0) {
    temp = numerator % denominator;
    numerator = denominator;
    denominator = temp;
  }

  *reduced_numerator /= numerator;
  *reduced_denominator /= numerator;

  return;
}

int main(void) {

  int num, denom;

  printf("Enter a fraction: ");
  scanf("%d/%d", &num, &denom);

  reduce(num, denom, &num, &denom);

  printf("In lowest terms: %d/%d\n", num, denom);

  return 0;
}

