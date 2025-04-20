#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {

  int ok = 1, month, day, year;

  if (argc != 2) {
    printf("usage: todate <m-d-y or m/d/y>\n");
    ok = 0;
  } else {
    if ((sscanf(argv[1], "%d-%d-%d", &month, &day, &year) == 3 ||
        sscanf(argv[1], "%d/%d/%d", &month, &day, &year) == 3) &&
        0 < month && month < 13) {
      switch (month) {
        case 1:
          printf("January");
          break;
        case 2:
          printf("February");
          break;
        case 3:
          printf("March");
          break;
        case 4:
          printf("April");
          break;
        case 5:
          printf("May");
          break;
        case 6:
          printf("June");
          break;
        case 7:
          printf("July");
          break;
        case 8:
          printf("August");
          break;
        case 9:
          printf("September");
          break;
        case 10:
          printf("October");
          break;
        case 11:
          printf("November");
          break;
        case 12:
          printf("December");
          break;
      }
      printf(" %d, %d\n", day, year);
    } else {
      printf("error: date string not in proper format (m-d-y or m/d/y)\n");
      ok = 0;
    }
  }

  return ok ? EXIT_SUCCESS : EXIT_FAILURE;
}

