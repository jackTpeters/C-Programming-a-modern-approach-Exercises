#ifndef STACKADT_H

#define STACKADT_H

typedef int Item;

typedef struct stack_type *Stack;

Stack create(void);
void destroy(Stack s);
void make_empty(Stack s);
int is_empty(Stack s);
int length(Stack s);
int is_full(Stack s);
void push(Stack s, Item i);
Item pop(Stack s);

#endif

