#include <stdio.h>
#include "stack.h"

#define STACK_SIZE (int) 100

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

void push(int i) {

  if (is_full()) {
    printf("Stack overflow: not pushing to stack\n");
  } else {
    contents[top++] = i;
  }

  return;
}

int pop(void) {

  int result = 0;

  if (is_empty()) {
    printf("Stack underflow: not popping from stack\n");
  } else {
    result = contents[--top];
  }

  return result;
}

