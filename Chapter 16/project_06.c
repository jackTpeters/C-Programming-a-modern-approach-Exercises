#include <stdio.h>

struct date {
  int month;
  int day;
  int year;
};

int compare_dates(const struct date d1, const struct date d2) {
  int result = -1;

  if (d1.year == d2.year) {
    if (d1.month == d2.month) {
      if (d1.day == d2.day) {
        result = 0;
      } else if (d1.day > d2.day) {
        result = 1;
      }
    } else if (d1.month > d2.month) {
      result = 1;
    }
  } else if (d1.year > d2.year) {
    result = 1;
  }

  return result;
}

int main(void) {

  struct date d1, d2;

  printf("Enter first date: (mm/dd/yy): ");
  scanf("%d/%d/%d", &d1.month, &d1.day, &d1.year);
  printf("Enter second date: (mm/dd/yy): ");
  scanf("%d/%d/%d", &d2.month, &d2.day, &d2.year);

  switch (compare_dates(d1, d2)) {
    case -1:
      printf("%d/%d/%d is earlier that %d/%d/%d\n", d1.month, d1.day, d1.year, d2.month, d2.day, d2.year);
      break;

    case 0:
      printf("The two dates are equal\n");
      break;

    case 1:
      printf("%d/%d/%d is earlier that %d/%d/%d\n", d2.month, d2.day, d2.year, d1.month, d1.day, d1.year);
      break;

    default:
      break;
  }

  return 0;
}

