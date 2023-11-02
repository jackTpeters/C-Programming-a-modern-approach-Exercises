#include <stdio.h>

int main(void) {
  float loan, rate, payment;
  int num_payments;
  printf("Enter amount of loan: $");
  scanf("%f", &loan);
  printf("Enter interest rate: ");
  scanf("%f", &rate);
  printf("Enter monthly payment: $");
  scanf("%f", &payment);
  printf("Enter the number of payments: ");
  scanf("%d", &num_payments);
  for (int i = 1; i <= num_payments; i++) {
    loan += (loan * (rate / 100.0f) / 12.0f) - payment;
    if (loan <= 0.00f) {
      loan = 0.00f;
    }
    printf("Balance remaining after %d payment: $%.2f\n", i, loan);
    if (loan == 0.00f) {
      break;
    }
  }
  return 0;
}
