#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

struct node {
  Item data;
  struct node *next;
};

struct stack_type {
  struct node *top;
  int len;
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
  s->top = NULL;
  s->len = 0;

  return s;
}

void destroy(Stack s) {
  make_empty(s);
  free(s);

  return;
}

void make_empty(Stack s) {
  while (!is_empty(s)) {
    pop(s);
  }

  return;
}

int is_empty(Stack s) {
  return s->top == NULL;
}

int length(Stack s) {
  return s->len;
}

int is_full(Stack s) {
  return 0;
}

void push(Stack s, Item i) {

  struct node *new_node = malloc(sizeof(struct node));
  if (!new_node) {
    terminate("Error in push: stack is full.");
  }

  new_node->data = i;
  new_node->next = s->top;

  s->top = new_node;
  s->len++;

  return;
}

Item pop(Stack s) {
  struct node *old_top;
  Item i;

  if (is_empty(s)) {
    terminate("Error in pop; stack is empty");
  }

  old_top = s->top;
  i = old_top->data;
  s->top = old_top->next;
  s->len--;

  free(old_top);

  return i;
}

