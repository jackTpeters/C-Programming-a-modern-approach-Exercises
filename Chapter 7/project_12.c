#include <stdio.h>

int main(void) {

  long double lvalue, rvalue;
  char operator;

  printf("Enter an expression: ");
  scanf(" %Lf", &lvalue);

  while ( (operator = getchar()) != '\n' ){
    if (operator == '+' || operator == '-' || operator == '*' || operator == '/') {
      scanf(" %Lf", &rvalue);
      switch (operator) {
        case '+':
          lvalue += rvalue;
          break;
        case '-':
          lvalue -= rvalue;
          break;
        case '*':
          lvalue *= rvalue;
          break;
        case '/':
          lvalue /= rvalue;
          break;
      }
    }
  }

  printf("Value of expression: %Lf\n", lvalue);

  return 0;
}

