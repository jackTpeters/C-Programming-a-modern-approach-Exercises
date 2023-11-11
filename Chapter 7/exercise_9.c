#include <stdio.h>
#include <ctype.h>

int main(void) {
  int hour, min;
  char meridiem;
  printf("Enter a 12-hour time: ");
  scanf("%d:%d", &hour, &min);
  meridiem = toupper(getchar());
  while (meridiem != 'A' && meridiem != 'P') {
    meridiem = toupper(getchar());
  }
  if (hour > 12 || hour < 1 || min > 59 || min < 0) {
    printf("Invalid time!\n");
    return 0;
  }
  
  hour %= 12;
  if (meridiem == 'P') {
    hour += 12;
  }
  
  printf("Equivelent 24-hour time: ");
  if (hour == 0) {
    printf("0");
  }
  printf("%d:", hour);
  if (min < 10) {
    printf("0");
  }
  printf("%d\n", min);
  return 0;
}
