# include <stdio.h>

int main(void) {
  int num, ones, tens, new_num;
  printf("Enter a two-digit or three-digit number: ");
  scanf("%d", &num);
  if (num < 100) {
    // two-digit number
    ones = num / 10;
    tens = (num % 10) * 10;
    new_num = tens + ones;
  }
  else if (num < 1000) {
    ones = num / 100;
    tens = ((num / 10) % 10) * 10;
    int hundereds = (num % 10) * 100;
    new_num = hundereds + tens + ones;
  }
  else {
    printf("Number too large!\n");
    return 0;
  }
  printf("The reversal is: %d\n", new_num);
  return 0;
}
