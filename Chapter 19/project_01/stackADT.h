#ifndef STACKADT_H

#define STACKADT_H

typedef struct stack_type *Stack;

Stack create(void);
void destroy(Stack s);
void make_empty(Stack s);
int is_empty(Stack s);
int is_full(Stack s);
void push(Stack s, char ch);
char pop(Stack s);

#endif

