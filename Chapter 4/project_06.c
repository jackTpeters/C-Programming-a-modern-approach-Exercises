#include <stdio.h>

int main(void) {

  int n_1, n_2, n_3, n_4, n_5, n_6, n_7, n_8, n_9, n_10, n_11, n_12, check;

  printf("Enter the first 12 digits of a UPC: ");
  scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &n_1, &n_2, &n_3, &n_4, &n_5, &n_6, &n_7, &n_8, &n_9, &n_10, &n_11, &n_12);

  printf("Check digit: %d\n", 9 - (n_1 + 3*n_2 + n_3 + 3*n_4 + n_5 + 3*n_6 + n_7 + 3*n_8 + n_9 + 3*n_10 + n_11 + 3*n_12 - 1) % 10);

  return 0;
}

