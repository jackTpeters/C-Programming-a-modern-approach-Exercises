#include <stdio.h>

int main(void) {

  int num_1, num_2, num_3, num_4, num_5, num_6, num_7, num_8, num_9, num_10, num_11, num_12, num_13, num_14, num_15, num_16;

  printf("Enter the numbers from 1 to 16 in any order: \n");
  scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &num_1, &num_2, &num_3, &num_4, &num_5, &num_6, &num_7, 
        &num_8, &num_9, &num_10, &num_11, &num_12, &num_13, &num_14, &num_15, &num_16);

  printf("%2d %2d %2d %2d\n%2d %2d %2d %2d\n%2d %2d %2d %2d\n%2d %2d %2d %2d\n\n", num_1, num_2, num_3, num_4, num_5,
         num_6, num_7, num_8, num_9, num_10, num_11, num_12, num_13, num_14, num_15, num_16);
  printf("Row sums: %2d %2d %2d %2d\n", num_1 + num_2 + num_3 + num_4, num_5 + num_6 + num_7 + num_8,
         num_9 + num_10 + num_11 + num_12, num_13 + num_14 + num_15 + num_16);
  printf("Column sums: %2d %2d %2d %2d\n", num_1 + num_5 + num_9 + num_13, num_2 + num_6 + num_10 + num_14,
         num_3 + num_7 + num_11 + num_15, num_4 + num_8 + num_12 + num_16);
  printf("Diagonal sums: %d %d\n", num_1 + num_6 + num_11 + num_16, num_4 + num_7 + num_10 + num_13);

  return 0;

}

