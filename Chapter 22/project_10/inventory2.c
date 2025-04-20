#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define NAME_LEN 25

struct part {
  int number;
  char name[NAME_LEN+1];
  int on_hand;
  struct part *next;
};

int read_line(char *str, int n) {

  int ch, i = 0;

  while (isspace(ch = getchar()))
    ;

  while (ch != '\n' && ch != EOF) {
    if (i < n) {
      str[i++] = ch;
    }
    ch = getchar();
  }
  str[i] = '\0';

  return i;
}

struct part *find_part(struct part *head, int part_number) {
  while (head && head->number != part_number) {
    head = head->next;
  }
  return head;
}

int main(void) {

  int i, part_number, change, num_parts_read;
  char code;
  char filename[51];
  FILE *fp;
  struct part *inventory = NULL, *new_part, *part;

  do {

    printf("Enter operation code: ");
    scanf(" %c", &code);
    code = toupper(code);

    while (getchar() != '\n')
      ;

    switch (code) {

      case 'I':

        printf("Enter part number: ");
        scanf("%d", &part_number);
        if (find_part(inventory, part_number)) {
          printf("Part already exists.\n");
        } else {
          struct part **p = &inventory;
          while (*p) {
            p = &(*p)->next;
          }
          if (*p = malloc(sizeof(struct part))) {
            (*p)->number = part_number;
            printf("Enter part name: ");
            read_line((*p)->name, NAME_LEN);
            printf("Enter quantity on hand: ");
            scanf("%d", &(*p)->on_hand);
            (*p)->next = NULL;
            }
        }

        break;

      case 'S':

        printf("Enter part number: ");
        scanf("%d", &part_number);
        if (part = find_part(inventory, part_number)) {
          printf("Part name: %s\n", part->name);
          printf("Quantity on hand: %d\n", part->on_hand);
        } else {
          printf("Part not found.\n");
        }

        break;

      case 'U':

        printf("Enter part number: ");
        scanf("%d", &part_number);
        if (part = find_part(inventory, part_number)) {
          printf("Enter change in quantity on hand: ");
          scanf("%d", &change);
          part->on_hand += change;
        } else {
          printf("Part not found.\n");
        }

        break;

      case 'P':

        printf("Part Number   Part Name                  Quantity on Hand\n");
        for (struct part *temp = inventory; temp; temp = temp->next) {
          printf("%7d       %-25s%11d\n", temp->number, temp->name, temp->on_hand);
        }

        break;

      case 'D':

        printf("Enter name of ouput file: ");
        scanf("%s", &filename);
        if (fp = fopen(filename, "wb")) {
          for (struct part *temp = inventory; temp; temp = temp->next) {
            if (!fprintf(fp, " %d %s %d", temp->number, temp->name, temp->on_hand)) {
              printf("Error writing part %s to file %s\n", temp->name, filename);
            }
          }
          fclose(fp);
        } else {
          printf("Can't write to file %s\n", filename);
        }

        break;

      case 'R':

        printf("Enter name of input file: ");
        scanf("%s", &filename);
        if (fp = fopen(filename, "rb")) {

          // deallocate existing parts
          for (struct part *temp; inventory;) {
            temp = inventory->next;
            free(inventory);
            inventory = temp;
          }

          // read from file
          struct part **p = &inventory;
          while (!feof(fp)) {
            while (*p) {
              p = &(*p)->next;
            }
            if (*p = malloc(sizeof(struct part))) {
              (*p)->next = NULL;
              if (!fscanf(fp, " %d %s %d", &(*p)->number, &(*p)->name, &(*p)->on_hand)) {
                printf("Error reading part from file %s\n", filename);
              }
            }
          }
          fclose(fp);
        } else {
          printf("Can't open file %s\n", filename);
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

