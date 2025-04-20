#include <stdio.h>

int main(void) {

  int month_earliest = 0, day_earliest = 0, year_earliest = 0, month, day, year;

  printf("Enter a date: (mm/dd/yy): ");
  scanf("%d/%d/%d", &month, &day, &year);

  year_earliest = year;
  month_earliest = month;
  day_earliest = day;

  while (month != 0 || day != 0 || year != 0) {

    if (year == year_earliest) {
      if (month == month_earliest) {
        if (day < day_earliest) {
          goto SET_EARLIEST;
        }
      }
      else if (month < month_earliest) {
        goto SET_EARLIEST;
      }
    }
    else if (year < year_earliest) {
      goto SET_EARLIEST;
    }
    goto GET_INPUT;

    SET_EARLIEST : {
      year_earliest = year;
      month_earliest = month;
      day_earliest = day;
    }

    GET_INPUT: {
      printf("Enter a date: (mm/dd/yy): ");
      scanf("%d/%d/%d", &month, &day, &year);
    }

  }

  if (month_earliest != 0 || day_earliest != 0 || year_earliest != 0) {
    printf("%d/%d/%d is the earliest date\n", month_earliest, day_earliest, year_earliest);
  }

  return 0;
}

