#include <stdio.h>

#define INITIAL_BALANCE (double) 100.0

int main(void) {

  int num_years;
  double rate, value[5];

  printf("Enter monthly interest rate: ");
  scanf("%lf", &rate);
  printf("Enter number of years: ");
  scanf("%d", &num_years);

  printf("\nYears");
  for (int i = 0; i < (int) (sizeof(value) / sizeof(value[0])); i++) {
    printf("%6.1f%%", rate + i);
    value[i] = INITIAL_BALANCE;
  }
  printf("\n");

  for (int month = 1; month <= 12 * num_years; month++) {

    if (month % 12 == 0) {
      printf("%3d    ", month / 12);
    }

    for (int i = 0; i < (int) (sizeof(value) / sizeof(value[0])); i++) {

      value[i] += (rate + i) / 100.0 * value[i];

      if (month % 12 == 0) {
        printf("%7.2f", value[i]);
      }

    }

    if (month % 12 == 0) {
      printf("\n");
    }

  }

  return 0;
}

