#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void) {

  time_t current_time = time(NULL);
  char date_time[35], am_or_pm;

  strftime(date_time, sizeof(date_time), "%A, %B %d, %Y  %I:%M", localtime(&current_time));
  if (localtime(&current_time)->tm_hour <= 11) {
    am_or_pm = 'a';
  } else {
    am_or_pm = 'p';
  }
  printf("%s%c\n", date_time, am_or_pm);

  strftime(date_time, sizeof(date_time), "%a, %d %b %y  %H:%M", localtime(&current_time));
  printf("%s\n", date_time);

  strftime(date_time, sizeof(date_time), "%x  %r", localtime(&current_time));
  printf("%s\n", date_time);

  return 0;
}

