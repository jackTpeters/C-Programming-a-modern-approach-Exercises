#include <stdio.h>

double func(double x) {
  return 3*x*x*x*x*x + 2*x*x*x*x - 5*x*x*x - x*x + 7*x - 6;
}

int main(void) {

  double x;

  printf("Enter a double value: ");
  scanf("%lf", &x);

  printf("The result of the function: %.2f\n", func(x));

  return 0;
}

