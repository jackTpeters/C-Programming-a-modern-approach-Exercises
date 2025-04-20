#include <stdio.h>

int main(void) {

  int n_1, n_2, n_3, n_4, n_5, n_6, n_7, n_8, n_9, n_10, n_11, n_12, check;

  printf("Enter a UPC (12 digits): ");
  scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &n_1, &n_2, &n_3, &n_4, &n_5, &n_6, &n_7, &n_8, &n_9, &n_10, &n_11, &n_12);
  check = 9 - (3*n_1 + n_2 + 3*n_3 + n_4 + 3*n_5 + n_6 + 3*n_7 + n_8 + 3*n_9 + n_10 + 3*n_11 - 1) % 10;

  if (n_12 == check) {
    printf("VALID\n");
  }
  else {
    printf("NOT VALID\n");
  }

  return 0;
}

