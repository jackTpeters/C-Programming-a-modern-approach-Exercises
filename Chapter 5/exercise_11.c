# include <stdio.h>

int main(void) {
  int num;
  _Bool negative;
  char const *first_part, *second_part;
  printf("Enter a two-digit number: ");
  scanf("%d", &num);
  if (num < -99 || num > 99) {
    printf("Number invalid!\n");
    return 0;
  }
  if (num < 0) {
    negative = 1;
    num *= -1;
  }
  if (num < 10) {
    switch (num) {
      case 0:
        first_part = "zero";
        break;
      case 1:
        first_part = "one";
        break;
      case 2:
        first_part = "two";
        break;
      case 3:
        first_part = "three";
        break;
      case 4:
        first_part = "four";
        break;
      case 5:
        first_part = "five";
        break;
      case 6:
        first_part = "six";
        break;
      case 7:
        first_part = "seven";
        break;
      case 8:
        first_part = "eight";
        break;
      case 9:
        first_part = "nine";
        break;
    }
    second_part = "";
  }
  else if (num < 20) {
    switch (num % 10) {
      case 0:
        first_part = "ten";
        break;
      case 1:
        first_part = "eleven";
        break;
      case 2:
        first_part = "twelve";
        break;
      case 3:
        first_part = "thirteen";
        break;
      case 4:
        first_part = "fourteen";
        break;
      case 5:
        first_part = "fifteen";
        break;
      case 6:
        first_part = "sixteen";
        break;
      case 7:
        first_part = "seventeen";
        break;
      case 8:
        first_part = "eighteen";
        break;
      case 9:
        first_part = "nineteen";
        break;
    }
    second_part = "";
  }
  else {
    switch (num / 10) {
      case 2:
        first_part = "twenty";
        break;
      case 3:
        first_part = "thirty";
        break;
      case 4:
        first_part = "forty";
        break;
      case 5:
        first_part = "fifty";
        break;
      case 6:
        first_part = "sixty";
        break;
      case 7:
        first_part = "seventy";
        break;
      case 8:
        first_part = "eighty";
        break;
      case 9:
        first_part = "ninety";
        break;
    }
    switch (num % 10) {
      default:
        second_part = "";
        break;
      case 1:
        second_part = "-one";
        break;
      case 2:
        second_part = "-two";
        break;
      case 3:
        second_part = "-three";
        break;
      case 4:
        second_part = "-fourth";
        break;
      case 5:
        second_part = "-five";
        break;
      case 6:
        second_part = "-six";
        break;
      case 7:
        second_part = "-seven";
        break;
      case 8:
        second_part = "-eight";
        break;
      case 9:
        second_part = "-nine";
        break;
    }
  }
  if (negative) {
    printf("You entered the number negative %s%s\n", first_part, second_part);
  }
  else {
    printf("You entered the number %s%s\n", first_part, second_part);
  }
  return 0;
}
