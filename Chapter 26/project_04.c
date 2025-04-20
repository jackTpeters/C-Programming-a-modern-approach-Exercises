#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void) {

  struct tm t;
  char date_time[11];

  int month, day, year, n;

  printf("Enter a date (month, day, year): ");
  scanf("%d, %d, %d", &month, &day, &year);
  while (getchar() != '\n')
    ;
  printf("Enter an integer: ");
  scanf("%d", &n);

  t.tm_mday = day + n;
  t.tm_mon = month - 1;
  t.tm_year = year - 1900;
  t.tm_sec = 0;
  t.tm_min = 0;
  t.tm_hour = 0;
  t.tm_isdst = -1;

  mktime(&t);

  strftime(date_time, sizeof(date_time), "%m-%d-%Y", &t);
  printf("%s\n", date_time);

  return 0;
}

