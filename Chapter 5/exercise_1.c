# include <stdio.h>

int main(void) {
  int num, digits;
  printf("Enter a number: ");
  scanf("%d", &num);
  if (num > -10 && num < 10) {
    digits = 1;
  }
  else if (num > -100 && num < 100) {
    digits = 2;
  }
  else if (num > -1000 && num < 1000) {
    digits = 3;
  }
  else if (num > -10000 && num < 10000) {
    digits = 4;
  }
  else {
    printf("The number %d has more than 4 digits\n", num);
    return 0;
  }
  printf("The number %d has %d digits\n", num, digits);
  return 0;
}
