#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

#define STACK_SIZE ((int) 100)

struct stack_type {
  float contents[STACK_SIZE];
  int top;
};

static void terminate(const char *message) {
  printf("%s\n", message);
  exit(EXIT_FAILURE);

  return;
}

Stack create(void) {
  Stack s = malloc(sizeof(struct stack_type));
  if (!s) {
    terminate("Error in create: stack could not be created.");
  }
  s->top = 0;

  return s;
}

void destroy(Stack s) {
  free(s);

  return;
}

void make_empty(Stack s) {
  s->top = 0;

  return;
}

int is_empty(Stack s) {
  return s->top == 0;
}

int is_full(Stack s) {
  return s->top == STACK_SIZE;
}

void push(Stack s, float x) {

  if (is_full(s)) {
    terminate("Error in push; stack is full.");
  }
  s->contents[s->top++] = x;

  return;
}

float pop(Stack s) {

  if (is_empty(s)) {
    terminate("Error in pop; stack is empty");
  }

  return s->contents[--s->top];
}

