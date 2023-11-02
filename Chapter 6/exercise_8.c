#include <stdio.h>

int main(void) {
  int days, start;
  printf("Enter number of days in month: ");
  scanf("%d", &days);
  printf("Enter starting day of the week (1=Sun, 7=Sat): ");
  scanf("%d", &start);
  printf("\n");
  for (int i = 1, day_of_week = start - 1; i <= days; i++, day_of_week = ++day_of_week % 7) {
    if (i == 1) {
      printf("%*d", (start % 8) * 3, 1);
    }
    else {
      printf("%3d", i);
    }
    if (day_of_week == 6 || i == days) {
      printf("\n");
    }
  }
  return 0;
}
