#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NAME_LEN 25

struct part {
  int number;
  char name[NAME_LEN + 1];
  int on_hand;
  struct part *next;
};

struct part *inventory = NULL;

void read_line(char *str, int n) {

  int i = 0;
  char ch;

  while (getchar() != '\n')
    ;
  for (i = 0; i < n && (ch = getchar()) != '\n'; i++) {
    str[i] = ch;
  }
  str[i] = '\0';

  return;
}

struct part *find_part(int number) {

  struct part *p;

  for (p = inventory; p != NULL && number > p->number; p = p->next)
    ;
  if (p != NULL && number != p->number) {
    p = NULL;
  }

  return p;
}

int main(void) {

  char code;
  int number, change;
  struct part *p, *cur, *prev;

  do {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')
      ;

    switch(toupper(code)) {

      case 'I':

        struct part *new_node;

        if (! (new_node = malloc(sizeof(*new_node)))) {
          printf("Database is full; can't add more parts.\n");
          exit(1);

        } else {
          printf("Enter part number: ");
          scanf("%d", &new_node->number);

          for (cur = inventory, prev = NULL;
               cur != NULL && new_node->number > cur->number;
               prev = cur, cur = cur->next)
            ;

          if (cur != NULL && new_node->number == cur->number) {
            printf("Part already exists.\n");
            free(new_node);
            new_node = NULL;

          } else {
            printf("Enter part name: ");
            read_line(new_node->name, NAME_LEN);
            printf("Enter quantity on hand: ");
            scanf("%d", &new_node->on_hand);

            new_node->next = cur;
            if (prev == NULL) {
              inventory = new_node;
            } else {
              prev->next = new_node;
            }
          }
        }

        break;

      case 'S':

        printf("Enter part number: ");
        scanf("%d", &number);
        p = find_part(number);
        if (p != NULL) {
          printf("Part name: %s\n", p->name);
          printf("Quantity on hand: %d\n", p->on_hand);
        } else {
          printf("Part not found.\n");
        }

        break;

      case 'U':

        printf("Enter part number: ");
        scanf("%d", &number);
        p = find_part(number);
        if (p != NULL) {
          printf("Enter change in quantity on hand: ");
          scanf("%d", change);
          p->on_hand += change;
        } else {
          printf("Part not found.\n");
        }

        break;

      case 'E':

        struct part *q;

        printf("Enter part number: ");
        scanf("%d", &number);

        for (prev = NULL, cur = inventory; 
             cur != NULL && number != cur->number;
             prev = cur, cur = cur->next)
          ;
        if (cur != NULL) {
          prev->next = cur->next;
          free(cur);
          cur = NULL;
        }

        break;

      case 'P':

        printf("Part Number   Part Name                  Quantity on Hand\n");
        for (p = inventory; p != NULL; p = p->next) {
          printf("%7d       %-25s%11d\n", p->number, p->name, p->on_hand);
        }

        break;

      case 'Q':
        break;

    }

    putchar('\n');

  } while (toupper(code) != 'Q');

  return 0;
}

