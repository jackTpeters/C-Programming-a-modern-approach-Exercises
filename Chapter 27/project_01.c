#include <stdio.h>
#include <complex.h>

int main(void) {

  double a, b, c, discriminant;
  double complex discriminant_sqrt, root1, root2;

  printf("Enter polynomial coefficents (a b c): ");
  scanf("%lf %lf %lf", &a, &b, &c);

  discriminant = b * b - 4 * a * c;
  discriminant_sqrt = csqrt(discriminant);
  root1 = (-b + discriminant_sqrt) / (2 * a);
  root2 = (-b - discriminant_sqrt) / (2 * a);

  if (discriminant < 0) {

    printf("root1 = %g ", creal(root1));
    if (cimag(root1) < 0) {
      printf("- %gi\n", cimag(root1) * -1.0);
    } else {
      printf("+ %gi\n", cimag(root1));
    }

    printf("root2 = %g ", creal(root2));
    if (cimag(root2) < 0) {
      printf("- %gi\n", cimag(root2) * -1.0);
    } else {
      printf("+ %gi\n", cimag(root2));
    }

  } else {

    printf("root1 = %g\n", creal(root1));
    printf("root2 = %g\n", creal(root2));

  }

  return 0;
}

