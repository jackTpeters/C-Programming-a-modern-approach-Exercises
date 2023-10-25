# include <stdio.h>

int main(void) {
  int first_month, first_day, first_year, second_month, second_day, second_year;
  int early_month, early_day, early_year, later_month, later_day, later_year;
  printf("Enter first date (mm/dd/yyyy): ");
  scanf("%d/%d/%d", &first_month, &first_day, &first_year);
  printf("Enter second date (mm/dd/yyyy): ");
  scanf("%d/%d/%d", &second_month, &second_day, &second_year);
  if (first_month > 12 || second_month > 12 || first_month < 1 || second_month < 1) {
    printf("Invalid month!\n");
    return 0;
  }
  if (first_day > 31 || second_day > 31 || first_day < 1 || second_day < 1) {
    printf("Invalid day!\n");
    return 0;
  }
  if (first_year < 0 || second_year < 0) {
    printf("Invalid year!\n");
    return 0;
  }
  int second_less_than_first(void) {
    early_month = second_month; 
    early_day = second_day;
    early_year = second_year;
    later_month = first_month;
    later_day = first_day;
    later_year = first_year;
    return 0;
  }
  int first_less_than_second(void) {
    early_month = first_month;
    early_day = first_day;
    early_year = first_year;
    later_month = second_month;
    later_day = second_day;
    later_year = second_year;
    return 0;
  }
  if (second_year < first_year) {
    second_less_than_first();
  }
  else if (second_year == first_year) {
    if (second_month < first_month) {
      second_less_than_first();
    }
    else if (second_month == first_month) {
      if (second_day < first_day) {
        second_less_than_first();
      }
      else if (second_day == first_day) {
        printf("%d/%d/%d and %d/%d/%d are the same date\n", first_month, first_day, first_year, second_month, second_day, second_year);
        return 0;
      }
      else {
        first_less_than_second();
      }
    }
    else {
      first_less_than_second();
    }
  }
  else {
    first_less_than_second();
  }
  printf("%d/%d/%d is earlier than %d/%d/%d\n", early_month, early_day, early_year, later_month, later_day, later_year);
  return 0;
}
