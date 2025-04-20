#include <stdio.h>

float tax_due(float income) {

  float due;

  if (income < 750) {
    due = 0.01 * income;
  }
  else if (income < 2250) {
    due = 7.50f + 0.02f * (income - 750);
  }
  else if (income < 3750) {
    due = 37.50f + 0.03f * (income - 2250);
  }
  else if (income < 5250) {
    due = 82.50f + 0.04f * (income - 3750);
  }
  else if (income < 7000) {
    due = 142.50f + 0.05f * (income - 5250);
  }
  else {
    due = 230.00f + 0.06f * (income - 7000);
  }

  return due;
}

int main(void) {

  float income, due;

  printf("Enter the taxable income: ");
  scanf("%f", &income);

  due = tax_due(income);

  printf("Tax due: %.2f\n", due);

  return 0;
}

