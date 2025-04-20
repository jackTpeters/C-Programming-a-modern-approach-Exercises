#include <stdio.h>
#include <math.h>

int main(void) {

  double r, theta, b;

  printf("Enter polar coordinates (r theta): ");
  scanf("%lf %lf", &r, &theta);

  printf("In Cartesian coordiantes: %lf ", r * cos(theta));
  if ((b = r * sin(theta)) < 0) {
    printf("- %lfi\n", b * -1.0);
  } else {
    printf("+ %lfi\n", b);
  }

  return 0;
}

