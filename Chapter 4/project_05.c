#include <stdio.h>

int main(void) {

  int n_1, n_2, n_3, n_4, n_5, n_6, n_7, n_8, n_9, n_10, n_11, check;

  printf("Enter the first 11 digits of a UPC: ");
  scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &n_1, &n_2, &n_3, &n_4, &n_5, &n_6, &n_7, &n_8, &n_9, &n_10, &n_11);

  printf("Check digit: %d\n", 9 - (3*n_1 + n_2 + 3*n_3 + n_4 + 3*n_5 + n_6 + 3*n_7 + n_8 + 3*n_9 + n_10 + 3*n_11 - 1) % 10);

  return 0;
}

