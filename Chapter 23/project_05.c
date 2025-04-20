#include <stdio.h>
#include <math.h>

int main(void) {

  double deposit, rate;
  int years;

  printf("Enter a deposit ($), intrest rate, and accrula years (deposit, rate, years): ");
  scanf("%lf %lf %d", &deposit, &rate, &years);

  printf("New amount: $%.2lf\n", deposit * exp(rate*years));

  return 0;
}

