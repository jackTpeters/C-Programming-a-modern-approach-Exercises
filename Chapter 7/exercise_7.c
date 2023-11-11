#include <stdio.h>

int main(void) {
  int num1, denom1, num2, denom2, result_num, result_denom;
  char op;
  printf("Enter two fractiions seperated by an operation: ");
  scanf("%d/%d%c%d/%d", &num1, &denom1, &op, &num2, &denom2);
  if (op == '+') {
    result_num = num1 * denom2 + num2 * denom1;
    result_denom = denom1 * denom2;
  }
  else if (op == '-') {
    result_num = num1 * denom2 - num2 * denom1;
    result_denom = denom1 * denom2;
  }
  else if (op == '*') {
    result_num = num1 * num2;
    result_denom = denom1 * denom2;
  }
  else if (op == '/') {
    result_num = num1 * denom2;
    result_denom = denom1 * num2;
  }
  printf("The result is %d/%d\n", result_num, result_denom);
  return 0;
}
