#include <stdio.h>

int main(void) {

  int num;
  float amount, rate, monthly_payment, monthly_rate;

  printf("Enter amount of loan: ");
  scanf("%f", &amount);
  printf("Enter interest rate: ");
  scanf("%f", &rate);
  printf("Enter monthly payment: ");
  scanf("%f", &monthly_payment);
  printf("Enter number of payments: ");
  scanf("%d", &num);

  monthly_rate = 1.0f + rate / 1200.0f;

  for (int i = 1; i <= num; i++) {
    amount = amount * monthly_rate - monthly_payment;
    printf("Balance remaining after %d payment: $%.2f\n", i, amount);
  }

  return 0;
}

