#include <stdio.h>

int main(void) {

  int amount, twentys = 0, tens = 0, fives = 0, ones = 0;

  printf("Enter a dollar amount: ");
  scanf("%d", &amount);

  twentys = amount / 20;
  tens = (amount - 20 * twentys) / 10;
  fives = (amount - 20 * twentys - 10 * tens) / 5;
  ones = amount - 20 * twentys - 10 * tens - 5 * fives;

  printf("\n$20 bills: %d\n$10 bills: %d\n $5 bills: %d\n $1 bills: %d\n", twentys, tens, fives, ones);

  return 0;
}
