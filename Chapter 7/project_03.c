#include <stdio.h>

int main(void) {

  double n;
  long double sum = 0;

  printf("This program sums a series of doubles.\n");
  printf("Enter doubles (0 to terminate): ");

  do {
    scanf("%lf", &n);
    sum += n;
  } while (n != 0.0);

  printf("The sum is: %Lf\n", sum);

  return 0;
}

