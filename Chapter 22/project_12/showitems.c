#include <stdlib.h>
#include <stdio.h>

#define LINE_LEN 100

int main(int argc, char **argv) {

  int ok = 1, item, month, day, year;
  float price;
  FILE *fp;
  char line[LINE_LEN + 1];

  if (argc != 2) {
    printf("usage: showitems filename\n");
    ok = 0;
  } else {
    if (fp = fopen(argv[1], "rb")) {
      printf("Item%18s%18s\n", "Unit", "Purchase");
      printf("%23s%13s\n", "Price", "Date");
      while (fgets(line, sizeof(line), fp) &&
             sscanf(line, "%d,%f,%d/%d/%d", &item, &price, &month, &day, &year) == 5)
      {
        printf("%d%18s %.2f%18d/%d/%d\n", item, "$", price, month, day, year);
      }
      fclose(fp);
    } else {
      printf("unable to open file %s\n", argv[1]);
      ok = 0;
    }
  }

  //printf("Enter item number: ");
  //scanf("%d", &item);
  //printf("Enter unit price: ");
  //scanf("%f", &price);
  //printf("Enter a purchase date (mm/dd/yyyy): ");
  //scanf("%d/%d/%d", &month, &day, &year);
  //printf("Item\t\tUnit\t\tPurchase\n\t\tPrice\t\tDate\n%d\t\t$%7.2f\t%d/%d/%d\n", item, price, month, day, year);

  return ok ? EXIT_SUCCESS : EXIT_FAILURE;
}

