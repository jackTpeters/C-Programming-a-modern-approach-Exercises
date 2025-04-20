#include <stdio.h>

int main(void) {

  int days, start;

  printf("Enter number of days in month: ");
  scanf("%d", &days);
  printf("Enter starting day of the week (1=Sun, 7=Sat): ");
  scanf("%d", &start);

  for (int i = 1; i < start; i++) {
    printf("   ");
  }

  for (int i = 1; i <= days; i++) {
    printf("%2d ", i);
    if (! ((i - 1 + start)%7) || i == days) {
      printf("\n");
    }
  }

  return 0;
}

