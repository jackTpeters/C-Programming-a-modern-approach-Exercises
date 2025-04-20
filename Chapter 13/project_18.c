#include <stdio.h>

int main(void) {

  int month, day, year;
  char *month_names[] = {"January",
                         "February",
                         "March",
                         "April",
                         "May",
                         "June",
                         "July",
                         "August",
                         "September",
                         "October",
                         "November",
                         "December"};

  printf("Enter a date (mm/dd/yyyy): ");
  scanf("%d/%d/%d", &month, &day, &year);

  if (1 <= month && month <= 12 &&
      1 <= day && day <= 31 &&
      0 <= year) {
    printf("You entered the date %s %d, %d\n", month_names[month - 1], day, year);
  } else {
    printf("Invalid date entered\n");
  }

  return 0;
}

