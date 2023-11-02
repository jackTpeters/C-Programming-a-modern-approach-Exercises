# include <stdio.h>

int main(void) {
  int month, day, year, early_month, early_day, early_year;
  early_month = 99;
  early_day = 99;
  early_year = 9999;
  for (;;) {
    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &month, &day, &year);
    if (month > 12 || month < 0) {
      printf("Invalid month!\n");
      return 0;
    }
    if (day > 31 || day < 0) {
      printf("Invalid day!\n");
      return 0;
    }
    if (year < 0) {
      printf("Invalid year!\n");
      return 0;
    }
    if (month == 0 && day == 0 && year == 0) {
      break;
    }
    if (year < early_year) {
      early_month = month;
      early_day = day;
      early_year = year;
    }
    else if (year == early_year) {
      if (month < early_month) {
        early_month = month;
        early_day = day;
        early_year = year;
      }
      else if (month == early_month) {
        if (day < early_day) {
          early_month = month;
          early_day = day;
          early_year = year;
        }
      }
    }
  }
  printf("%d/%d/%d is the earliest date\n", early_month, early_day, early_year);
  return 0;
}
