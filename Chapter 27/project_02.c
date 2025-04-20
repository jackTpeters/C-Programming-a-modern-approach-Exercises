#include <stdio.h>
#include <math.h>

int main(void) {

  double a, b;

  printf("Enter a complex number (a b): ");
  scanf("%lf %lf", &a, &b);

  printf("In polar coordinates: r = %lf, theta = %lf\n", sqrt(a*a + b*b), atan2(b, a));

  return 0;
}

