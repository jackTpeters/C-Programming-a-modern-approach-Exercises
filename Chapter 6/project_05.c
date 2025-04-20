#include <stdio.h>

int main(void) {

  int num, result = 0;

  printf("Enter an integer: ");
  scanf("%d", &num);

  do {
    result = result*10 + num%10;
    num /= 10;
  } while (num > 0);

  printf("The reversal is: %d\n", result);

  return 0;
}

