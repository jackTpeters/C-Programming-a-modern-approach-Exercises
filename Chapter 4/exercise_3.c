# include <stdio.h>

int main(void) {
  int i1, i2, i3, new_num;
  printf("Enter a three-digit number: ");
  scanf("%1d%1d%1d", &i1, &i2, &i3);
  new_num = i1 + i2 * 10 + i3 * 100;
  printf("The reversal is: %d\n", new_num);
  return 0;
}
