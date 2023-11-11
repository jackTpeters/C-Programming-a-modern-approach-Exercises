#include <stdio.h>

int main(void) {
  float num_1, num_2;
  char ch;
  printf("Enter an expression (evaluated left to right): ");
  scanf("%f", &num_1);
  while ((ch = getchar()) != '\n') {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
      scanf("%f", &num_2);
      if (ch == '+') {
        num_1 = num_1 + num_2;
      }
      else if (ch == '-') {
        num_1 = num_1 - num_2;
      }
      else if (ch == '*') {
        num_1 = num_1 * num_2;
      }
      else {
        num_1 = num_1 / num_2;
      }
    }
  }
  printf("Value of expression: %.2f\n", num_1);
  return 0;
}
