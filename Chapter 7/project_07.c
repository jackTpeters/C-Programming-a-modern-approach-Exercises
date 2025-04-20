#include <stdio.h>

int main(void) {

  int num_1, denom_1, num_2, denom_2;
  long int num_result, denom_result;
  char operator;

  printf("Enter two fractions seperated by an operator (+, -, *, /): ");
  scanf("%d/%d%c%d/%d", &num_1, &denom_1, &operator, &num_2, &denom_2);

  switch (operator) {
    case '+':
      num_result = num_1 * denom_2 + num_2 * denom_1;
      denom_result = denom_1 * denom_2;
      break;
    case '-':
      num_result = num_1 * denom_2 - num_2 * denom_1;
      denom_result = denom_1 * denom_2;
      break;
    case '*':
      num_result = num_1 * num_2;
      denom_result = denom_1 * denom_2;
      break;
    case '/':
      num_result = num_1 * denom_2;
      denom_result = denom_1 * num_2;
      break;
    default:
      num_result = 0;
      denom_result = 0;
      break;
  }

  printf("The result is %d/%d\n", num_result, denom_result);

  return 0;

}

