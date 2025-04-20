#include <stdio.h>

#define STACK_SIZE 100

int contents[STACK_SIZE];
int top = 0;

void make_empty(void) {
  top = 0;

  return;
}

int is_empty(void) {
  return top == 0;
}

int is_full(void) {
  return top == STACK_SIZE;
}

int push(char ch) {
  int result = 0;

  if (is_full()) {
    // stack overflow
    result = 1;
  } else {
    contents[top++] = ch;
  }

  return result;
}

int pop(void) {
  int result;

  if (is_empty()) {
    // stack underflow
    result = -1;
  } else {
    result = contents[--top];
  }

  return result;
}

int main(void) {

  char ch;
  int result = 0;

  printf("Enter parentheses and/or braces: ");
  while ((ch = getchar()) != '\n' && !result) {
    if (ch == '{' || ch == '[' || ch == '(') {
      if (push(ch)) {
        printf("Stack overflow!\n");
        result = 1;
      }
    } else if (ch == '}' || ch == ']' || ch == ')') {

      int elem = pop();

      if (elem == -1) {
        printf("Stack underflow!\n");
        result = 1;
      } else if ((ch == '}' && elem != '{') || 
                 (ch == ']' && elem != '[') || 
                 (ch == ')' && elem != '(')) {
        result = 1;
      }

    }
  }

  if (result) {
    printf("Parentheses/braces are not nested properly\n");
  } else {
    printf("Parentheses/braces are nested properly\n");
  }

  return 0;
}

