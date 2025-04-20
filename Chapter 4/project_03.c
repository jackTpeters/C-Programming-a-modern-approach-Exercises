#include <stdio.h>

int main(void) {

  int num_1, num_2, num_3;

  printf("Enter a three-digit number: ");
  scanf("%1d%1d%1d", &num_1, &num_2, &num_3);
  printf("The reversal is: %d%d%d\n", num_3, num_2, num_1);

  return 0;
}

