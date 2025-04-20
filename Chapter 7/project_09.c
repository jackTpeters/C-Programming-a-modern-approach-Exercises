#include <stdio.h>
#include <ctype.h>

int main(void) {

  int hour, min;
  char meridiem;

  printf("Enter a 12-hour time: ");
  scanf("%d:%d", &hour, &min);
  scanf(" %c", &meridiem);

  if (toupper(meridiem) == 'P' && hour != 12) {
    hour += 12;
  }

  printf("Equivelent 24-hour time: %d:", hour);
  if (min < 10) {
    printf("0");
  }
  printf("%d\n", min);

  return 0;
}

