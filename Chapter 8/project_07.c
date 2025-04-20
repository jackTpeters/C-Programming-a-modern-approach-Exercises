#include <stdio.h>

int main(void) {

  int row_totals[5] = {0}, column_totals[5] = {0}, input;

  for (int i = 0; i < (int) (sizeof(row_totals) / sizeof(row_totals[0])); i++) {
    printf("Enter row %d: ", i + 1);
    for (int j = 0; j < (int) (sizeof(column_totals) / sizeof(column_totals[0])); j++) {
      scanf("%d", &input);
      row_totals[i] += input;
      column_totals[j] += input;
    }
  }

  printf("\nRow totals:");
  for (int i = 0; i < (int) (sizeof(row_totals) / sizeof(row_totals[0])); i++) {
    printf("%3d", row_totals[i]);
  }
  printf("\nColumn totals:");
  for (int i = 0; i < (int) (sizeof(column_totals) / sizeof(column_totals[0])); i++) {
    printf("%3d", column_totals[i]);
  }
  printf("\n");


  return 0;
}

