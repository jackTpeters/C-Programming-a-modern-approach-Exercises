#include <stdio.h>

int main(void) {

  int hour, min;

  printf("Enter a 24-hour time: ");
  scanf("%d:%d", &hour, &min);

  printf("Equivalent 12-hour time: %d:", hour % 12 ? hour % 12 : 12);

  if (min < 10) {
    printf("0");
  }
  printf("%d ", min);

  if (hour < 12) {
    printf("AM\n");
  }
  else {
    printf("PM\n");
  }

  return 0;
}

