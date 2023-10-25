# include <stdio.h>

int main(void) {
  float income, due;
  printf("Enter your taxable income: $");
  scanf("%f", &income);
  if (income < 0.00f) {
    printf("Income can't be negative!\n");
    return 0;
  }
  else if (income <= 750.00f) {
    due = 0.01f * income;
  }
  else if (income <= 2250.00f) {
    due = 7.50f + 0.02f * (income - 750.00f);
  }
  else if (income <= 3750.00f) {
    due = 37.50f + 0.03f * (income - 2250.00f);
  }
  else if (income <= 5250.00f) {
    due = 82.50f + 0.04f * (income - 3750.00f);
  }
  else if (income <= 7000.00f) {
    due = 142.50f + 0.05f * (income - 5250.00f);
  }
  else {
    due = 230.00f + 0.06f * (income - 7000.00f);
  }
  printf("Tax due: $%.2f\n", due);
  return 0;
}
