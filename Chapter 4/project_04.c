#include <stdio.h>

int main(void) {

  int num, digit_1, digit_2, digit_3, digit_4, digit_5;;

  printf("Enter a number between 0 and 32767: ");
  scanf("%d", &num);

  digit_1 = num % 8;
  num /= 8;
  digit_2 = num % 8;
  num /= 8;
  digit_3 = num % 8;
  num /= 8;
  digit_4 = num % 8;
  num /= 8;
  digit_5 = num % 8;


  printf("In octal, your number is: %d%d%d%d%d\n", digit_5, digit_4, digit_3, digit_2, digit_1);

  return 0;
}

