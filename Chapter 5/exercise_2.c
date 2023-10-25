# include <stdio.h>

int main(void) {
  int hour, minute, new_hour;
  char const *meridiem;
  printf("Enter a 24-hour time: ");
  scanf("%d:%d", &hour, &minute);
  new_hour = hour % 12;
  if (new_hour == 0) {
    new_hour = 12;
  }
  if (hour / 12) {
    meridiem = "PM";
  }
  else {
    meridiem = "AM";
  }
  if (minute < 10) {
    printf("Equivelent 12-hour time: %d:0%d %s\n", new_hour, minute, meridiem);
  }
  else {
    printf("Equivelent 12-hour time: %d:%d %s\n", new_hour, minute, meridiem);
  }
  return 0;
}
