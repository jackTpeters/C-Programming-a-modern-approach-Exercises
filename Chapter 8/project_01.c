#include <stdio.h>

int main(void) {

  int digit, digit_seen[10] = {0}, repeated_digits[10] = {0};
  long n;

  printf("Enter a number: ");
  scanf("%ld", &n);

  printf("Repeated digit(s):");

  while (n > 0) {

    digit = n % 10;

    if (digit_seen[digit]) {
      if (! repeated_digits[digit]) {
        repeated_digits[digit] = 1;
        printf(" %d", digit);
      }
    }
    else {
      digit_seen[digit] = 1;
    }

    n /= 10;

  }

  printf("\n");

  return 0;
}

