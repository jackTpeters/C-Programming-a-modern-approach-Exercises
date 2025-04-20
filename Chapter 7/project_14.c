#include <stdio.h>
#include <math.h>

int main(void) {

  double x, y = 1.0, y_old;

  printf("Enter a positive number: ");
  scanf("%lf", &x);

  do {
    y_old = y;
    y = (y + x/y) / 2;
  } while (fabs(y_old - y) >= 0.00001 * y);

  printf("Square root: %f\n", y);

  return 0;
}

