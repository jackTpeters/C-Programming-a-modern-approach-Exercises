#include <stdio.h>

int main(void) {

  int digit, digit_occurences[10] = {0};
  long n;

  printf("Enter a number: ");
  scanf("%ld", &n);

  while (n > 0) {
    digit = n % 10;
    digit_occurences[digit]++;
    n /= 10;
  }

  printf("Digit:       0  1  2  3  4  5  6  7  8  9\nOccurences:");
  for (int i = 0; i < (int) (sizeof(digit_occurences) / sizeof(digit_occurences[0])); i++) {
    printf("%3d", digit_occurences[i]);
  }
  printf("\n");

  return 0;
}

