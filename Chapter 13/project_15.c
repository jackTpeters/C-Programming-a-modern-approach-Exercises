#include <stdio.h>
#include <stdlib.h>

#define EXPR_LEN (int) 100
#define STACK_SIZE (int) 100

int stack_i = 0;

int push(float stack[], float elem) {
  int result = 0;
  if (stack_i == STACK_SIZE) {
    // stack overflow
    result = 1;
  } else {
    stack[stack_i++] = elem;
  }
  return result;
}

float pop(float stack[]) {
  float result;
  if (stack_i == 0) {
    // stack underflow
    printf("Not enough operands in expression\n");
    exit(0);
  } else {
    result = stack[--stack_i];
  }
  return result;
}

float evaluate_RPN_expression(const char *expression) {

  int exit = 0;
  char ch;
  float result = 0.0, stack[STACK_SIZE];

  while ((ch = *expression) && !exit) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
      float rvalue = pop(stack), lvalue = pop(stack);

      switch (ch) {
        case '+':
          push(stack, lvalue + rvalue);
          break;
        case '-':
          push(stack, lvalue - rvalue);
          break;
        case '*':
          push(stack, lvalue * rvalue);
          break;
        case '/':
          push(stack, (float) lvalue / rvalue);
          break;
      }

    } else if (ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' ||
                ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9') {

      int ch_int;
      switch (ch) {
        case '0':
          ch_int = 0;
          break;
        case '1':
          ch_int = 1;
          break;
        case '2':
          ch_int = 2;
          break;
        case '3':
          ch_int = 3;
          break;
        case '4':
          ch_int = 4;
          break;
        case '5':
          ch_int = 5;
          break;
        case '6':
          ch_int = 6;
          break;
        case '7':
          ch_int = 7;
          break;
        case '8':
          ch_int = 8;
          break;
        case '9':
          ch_int = 9;
          break;
      }

      if (push(stack, (float) ch_int)) {
        printf("Stack is too complex\n");
        exit = 1;
      }

    } else if (ch == '=') {
      result = pop(stack);
    }

    expression++;
  }

  return result;
}

int main(void) {

  char ch, expression[EXPR_LEN + 1];
  int i;

  printf("Enter an RPN expression: ");
  for (i = 0; i < EXPR_LEN && (ch = getchar()) != '\n'; i++) {
    expression[i] = ch;
  }
  expression[i] = '\0';

  printf("Value of expression: %.2f\n", evaluate_RPN_expression(expression));

  return 0;
}

