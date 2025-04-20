#include <stdio.h>
#include <ctype.h>

#define NAME_LEN (int) 25
#define MAX_PARTS (int) 100

struct part {
  int number;
  char name[NAME_LEN + 1];
  int on_hand;
  float price;
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

int find_part(struct part inventory[], int num_parts, int number) {

  int result = -1;

  for (int i = 0; i < num_parts && result == -1; i++) {
    if (inventory[i].number == number) {
      result = i;
    }
  }

  return result;
}

int main(void) {

  struct part inventory[MAX_PARTS], temp;
  int num_parts = 0, i, number, change;
  char code;

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
            printf("Enter price of part: ");
            scanf("%f", &temp.price);

            for (i = 0; i < num_parts && inventory[i].number < temp.number; i++)
              ;
            for (int j = num_parts; j > i; j--) {
              inventory[j] = inventory[j - 1];
            }
            inventory[i] = temp;
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
          printf("Price: %.2f\n", inventory[i].price);
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

        printf("Part Number   Part Name                  Quantity on Hand   Price\n");
        for (i = 0; i < num_parts; i++) {
          printf("%d             %s                          %d                   %.2f\n", inventory[i].number, inventory[i].name, inventory[i].on_hand, inventory[i].price);
        }
        break;

      case 'C':

        printf("Enter part number: ");
        scanf("%d", &number);
        if ((i = find_part(inventory, num_parts, number)) >= 0) {
          printf("Enter new price: ");
          scanf("%f", &inventory[i].price);
        } else {
          printf("Part not found.\n");
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

