#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define NAME_LEN (int) 25
#define MAX_PARTS (int) 100

struct part {
  int number;
  char name[NAME_LEN + 1];
  int on_hand;
};

int read_line(char str[], int n) {

  int ch, i = 0;

  while (isspace(ch = getchar()))
    ;
  for(; ch != '\n' && ch != EOF; ch = getchar()) {
    if (i < n) {
      str[i++] = ch;
    }
  }
  str[i] = '\0';

  return i;
}

int find_part(struct part *inventory, int num_parts, int number) {

  int result = -1;

  for (int i = 0; i < num_parts && result == -1; i++) {
    if (inventory[i].number == number) {
      result = i;
    }
  }

  return result;
}

int compare_parts(const void *p, const void *q) {
  return ((struct part *) p)->number - ((struct part *) q)->number;
}

int main(void) {

  char code;
  int i, number, change, num_parts = 0, max_parts = 10;
  struct part temp;
  struct part *inventory;

  if (!(inventory = malloc(max_parts * sizeof(*inventory)))) {
    printf("Error allocating memory for inventory\n");
    exit(1);
  }

  do {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    code = toupper(code);
    while (getchar() != '\n')
      ;

    switch (code) {

      case 'I':

        if (num_parts < MAX_PARTS) {
          printf("Enter part number: ");
          scanf("%d", &temp.number);

          if (find_part(inventory, num_parts, temp.number) < 0) {

            printf("Enter part name: ");
            read_line(temp.name, NAME_LEN);
            printf("Enter quantity on hand: ");
            scanf("%d", &temp.on_hand);

            // ensure inventory has enough space to hold new part
            if (num_parts >= max_parts - 1) {
              max_parts *= 2;
              if (!(inventory = realloc(inventory, max_parts * sizeof(*inventory)))) {
                printf("Error reallocating memory for inventory!\n");
                exit(1);
              }
            }

            inventory[num_parts] = temp;
            num_parts++;

          } else {
            printf("Part already exists.\n");
          }
        } else {
          printf("Database is full; can't add more parts.\n");
        }

        break;

      case 'S':

        printf("Enter part number: ");
        scanf("%d", &number);
        if ((i = find_part(inventory, num_parts, number)) >= 0) {
          printf("Part name: %s\n", inventory[i].name);
          printf("Quantity on hand: %d\n", inventory[i].on_hand);
        } else {
          printf("Part not found.\n");
        }

        break;

      case 'U':

        printf("Enter part number: ");
        scanf("%d", &number);
        if ((i = find_part(inventory, num_parts, number)) >= 0) {
          printf("Enter change in qunatity on hand: ");
          scanf("%d", &change);
          inventory[i].on_hand += change;
        } else {
          printf("Part not found.\n");
        }

        break;

      case 'P':

        // sort parts by part number before printing
        qsort(inventory, num_parts, sizeof(*inventory), compare_parts);

        printf("Part Number   Part Name                  Quantity on Hand\n");
        for (i = 0; i < num_parts; i++) {
          printf("%7d       %-25s%11d\n", inventory[i].number, inventory[i].name, inventory[i].on_hand);
        }
        break;

      case 'Q':
        break;

      default:
        printf("Illegal code\n");
        break;
    }
    printf("\n");

  } while (code != 'Q');

  return 0;
}

