#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void) {

  struct tm t1, t2;
  int month_1, day_1, year_1, month_2, day_2, year_2, diff;

  printf("Enter a date (month, day, year): ");
  scanf("%d, %d, %d", &month_1, &day_1, &year_1);
  while (getchar() != '\n')
    ;
  printf("Enter another date (month, day, year): ");
  scanf("%d, %d, %d", &month_2, &day_2, &year_2);

  t1.tm_mday = day_1;
  t1.tm_mon = month_1 - 1;
  t1.tm_year = year_1 - 1900;
  t1.tm_sec = 0;
  t1.tm_min = 0;
  t1.tm_hour = 0;
  t1.tm_isdst = -1;

  t2.tm_mday = day_2;
  t2.tm_mon = month_2 - 1;
  t2.tm_year = year_2 - 1900;
  t2.tm_sec = 0;
  t2.tm_min = 0;
  t2.tm_hour = 0;
  t2.tm_isdst = -1;

  diff = (int) difftime(mktime(&t1), mktime(&t2)) / 60 / 60 / 24;

  printf("The difference in days is %d\n", (diff < 0) ? -1*diff : diff);

  return 0;
}

