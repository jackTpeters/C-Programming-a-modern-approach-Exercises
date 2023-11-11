#include <stdio.h>
#include <math.h>

int main(void) {
  long double x, y = 1.0L;
  printf("Enter a positive number: ");
  scanf("%Lf", &x);
  while ( fabs(y - (x/y + y)/2) >= (y * 0.00001) ) {
    y = (x/y + y)/2;
  }
  printf("Square root: %.5Lf\n", y);
  return 0;
}
