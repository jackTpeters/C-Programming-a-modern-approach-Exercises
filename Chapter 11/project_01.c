#include <stdio.h>

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones) {

  *twenties = dollars / 20;
  *tens = (dollars - 20 * *twenties) / 10;
  *fives = (dollars - 20 * *twenties - 10 * *tens) / 5;
  *ones = dollars - 20 * *twenties - 10 * *tens - 5 * *fives;

  return;
}

int main(void) {

  int amount, twenties = 0, tens = 0, fives = 0, ones = 0;

  printf("Enter a dollar amount: ");
  scanf("%d", &amount);

  pay_amount(amount, &twenties, &tens, &fives, &ones);

  printf("\n$20 bills: %d\n$10 bills: %d\n $5 bills: %d\n $1 bills: %d\n", twenties, tens, fives, ones);

  return 0;
}
