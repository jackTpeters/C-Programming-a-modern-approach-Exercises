#include <stdio.h>

double power(double x, int n) {

  double result, sub_result;

  if (n == 0) {
    result = 1;
  } else if (n % 2) {
    result = x * power(x, n - 1);
  } else {
    sub_result = power(x, n / 2);
    result = sub_result * sub_result;
  }

  return result;
}

int main(void) {

  double x;
  int n;

  printf("Enter a number: ");
  scanf("%lf", &x);
  printf("Enter an integer to raise the number to: ");
  scanf("%d", &n);

  printf("%f ** %d = %f\n", x, n, power(x, n));

  return 0;
}

