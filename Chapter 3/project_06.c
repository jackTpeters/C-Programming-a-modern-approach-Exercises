#include <stdio.h>

int main(void) {

  int num_1, denom_1, num_2, denom_2;

  printf("Enter two fractions seperated by a plus sign: ");
  scanf("%d/%d+%d/%d", &num_1, &denom_1, &num_2, &denom_2);

  printf("The sum is %d/%d\n", num_1 * denom_2 + num_2 * denom_1, denom_1 * denom_2);

  return 0;

}

