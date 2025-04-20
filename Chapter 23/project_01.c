#include <stdio.h>
#include <math.h>

int main(void) {

  double a, b, c, discr, root;

  printf("Enter values for a, b, and c (a b c): ");
  scanf("%lf %lf %lf", &a, &b, &c);

  discr = (b*b) - (4.0D*a*c);
  if (discr < 0) {
    printf("Roots are complex!\n");
  } else {
    root = sqrt(discr);
    printf("Root 1: %lf\n", (-1.0*b + root)/(2.0*a));
    printf("Root 2: %lf\n", (-1.0*b - root)/(2.0*a));
  }

  return 0;
}

