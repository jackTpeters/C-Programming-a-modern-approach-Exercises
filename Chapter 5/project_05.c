#include <stdio.h>

int main(void) {

  float income, tax_due;

  printf("Enter the taxable income: ");
  scanf("%f", &income);

  if (income < 750) {
    tax_due = 0.01 * income;
  }
  else if (income < 2250) {
    tax_due = 7.50f + 0.02f * (income - 750);
  }
  else if (income < 3750) {
    tax_due = 37.50f + 0.03f * (income - 2250);
  }
  else if (income < 5250) {
    tax_due = 82.50f + 0.04f * (income - 3750);
  }
  else if (income < 7000) {
    tax_due = 142.50f + 0.05f * (income - 5250);
  }
  else {
    tax_due = 230.00f + 0.06f * (income - 7000);
  }

  printf("Tax due: %.2f\n", tax_due);

  return 0;
}

