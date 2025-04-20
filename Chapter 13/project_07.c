#include <stdio.h>

int main(void) {

  char *ones[] = {"zero",
                  "one",
                  "two",
                  "three",
                  "four",
                  "five",
                  "six",
                  "seven",
                  "eight",
                  "nine"};
  char *teens[] = {"eleven",
                   "twelve",
                   "thirteen",
                   "fourteen",
                   "fifteen",
                   "sixteen",
                   "seventeen",
                   "eighteen",
                   "nineteen"};
  char *tens[] = {"ten",
                  "twenty",
                  "thirty",
                  "forty",
                  "fifty",
                  "sixty",
                  "seventy",
                  "eighty",
                  "ninety"};
  int num;

  printf("Enter a two-digit number: ");
  scanf("%d", &num);

  if (num < -99 || 99 < num) {
    printf("ERROR: not a two digit number");
  }
  else {

    printf("You entered the number ");

    if (num < 0) {
      printf("negative ");
      num = -num;
    }

    if (10 < num && num < 20) {
      printf(teens[(num % 10) - 1]);
    } else {
      int ones_digit = num % 10;

      if (num > 9) {
        printf(tens[num / 10 - 1]);
        if (ones_digit) {
          printf("-%s", ones[ones_digit]);
        }
      } else {
        printf(ones[ones_digit]);
      }
    }
  }

  printf(".\n");

  return 0;
}

