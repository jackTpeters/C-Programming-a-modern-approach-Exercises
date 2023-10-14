# include <stdio.h>

int main(void) {
  int num;
  printf("Enter a two-digit number: ");
  scanf("%d", &num);
  int ones = num / 10;
  int tens = (num % 10) * 10;
  int new_num = tens + ones;
  printf("The reversal is: %d\n", new_num);
  return 0;
}
