#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

int main(void) {

  int exit = 0;

  while (!exit) {

    char ch;
    Stack stack = create();
    int evaluate = 0;

    printf("Enter an RPN expression: ");

    do {
      scanf(" %c", &ch);
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

        push(stack, (float) ch_int);

      } else if (ch == '=') {
        printf("Value of expression: %.2f\n", pop(stack));
        evaluate = 1;
      } else {
        exit = 1;
      }

    } while (!evaluate && !exit);

    destroy(stack);

  }

  return 0;
}

