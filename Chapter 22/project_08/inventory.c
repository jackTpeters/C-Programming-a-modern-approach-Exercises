#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
  int number;
  char name[NAME_LEN+1];
  int on_hand;
} inventory[MAX_PARTS];

int num_parts = 0;

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

int find_part(int part_number) {
  int i;
  for (i = 0; i < num_parts && inventory[i].number != part_number; i++)
    ;
  return i < num_parts ? i : -1;
}

int main(void) {

  int i, part_number, change, num_parts_read;
  char code;
  char filename[51];
  FILE *fp;

  do {

    printf("Enter operation code: ");
    scanf(" %c", &code);
    code = toupper(code);

    while (getchar() != '\n')
      ;

    switch (code) {

      case 'I':

        if (num_parts == MAX_PARTS) {
          printf("Database is full; can't add more parts.\n");
        } else {
          printf("Enter part number: ");
          scanf("%d", &part_number);
          if (find_part(part_number) >= 0) {
            printf("Part already exists.\n");
          } else {
            inventory[num_parts].number = part_number;
            printf("Enter part name: ");
            read_line(inventory[num_parts].name, NAME_LEN);
            printf("Enter quantity on hand: ");
            scanf("%d", &inventory[num_parts].on_hand);
            num_parts++;
          }
        }

        break;

      case 'S':

        printf("Enter part number: ");
        scanf("%d", &part_number);
        i = find_part(part_number);
        if (i >= 0) {
          printf("Part name: %s\n", inventory[i].name);
          printf("Quantity on hand: %d\n", inventory[i].on_hand);
        } else {
          printf("Part not found.\n");
        }

        break;

      case 'U':

        printf("Enter part number: ");
        scanf("%d", &part_number);
        i = find_part(part_number);
        if (i >= 0) {
          printf("Enter change in quantity on hand: ");
          scanf("%d", &change);
          inventory[i].on_hand += change;
        } else {
          printf("Part not found.\n");
        }

        break;

      case 'P':

        printf("Part Number   Part Name                  Quantity on Hand\n");
        for (i = 0; i < num_parts; i++) {
          printf("%7d       %-25s%11d\n", inventory[i].number, inventory[i].name, inventory[i].on_hand);
        }

        break;

      case 'D':

        printf("Enter name of ouput file: ");
        scanf("%s", &filename);
        if (fp = fopen(filename, "wb")) {
          if (fwrite(inventory, sizeof(struct part), num_parts, fp) < num_parts) {
            printf("Error writing to file %s\n", filename);
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
          if ((num_parts_read = fread(inventory, sizeof(struct part), MAX_PARTS, fp)) < num_parts) {
            printf("Error reading from file %s, only %d parts read\n", filename, num_parts_read);
          }
          num_parts = num_parts_read;
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

