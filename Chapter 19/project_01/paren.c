#include <stdio.h>
#include "stackADT.h"

int main(void) {

  Stack stack;
  char ch;
  int result = 0;

  stack = create();

  printf("Enter parentheses and/or braces: ");

  while ((ch = getchar()) != '\n' && !result) {

    if (ch == '{' || ch == '[' || ch == '(') {

      push(stack, ch);

    } else if (ch == '}' || ch == ']' || ch == ')') {

      char elem = pop(stack);

      if ((ch == '}' && elem != '{') || 
          (ch == ']' && elem != '[') || 
          (ch == ')' && elem != '(')) {
        result = 1;
      }

    }
  }

  if (result || !is_empty(stack)) {
    printf("Parentheses/braces are not nested properly\n");
  } else {
    printf("Parentheses/braces are nested properly\n");
  }

  return 0;
}

