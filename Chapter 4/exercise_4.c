# include <stdio.h>
# include <math.h>

int main(void) {
  int num, remainder, octal;
  printf("Enter a number between 0 and 32767: ");
  scanf("%d", &num);
  if (num > 32767) {
    printf("Entered number too large!\n");
  }
  else if (num < 0) {
    printf("Entered number too small!\n");
  }
  else {
    for (int i = 0; i < 5; i++) {
      remainder = num % 8;
      num = num / 8;
      octal += remainder * pow(10, i);
      if (num == 0) {
        break;
      }
    }
    if (octal < 10) {
      printf("In octal, your number is: %d%d%d%d%d\n", 0, 0, 0, 0, octal);
    }
    else if (octal < 100) {
      printf("In octal, your number is: %d%d%d%d\n", 0, 0, 0, octal);
    }
    else if (octal < 1000) {
      printf("In octal, your number is: %d%d%d\n", 0, 0, octal);
    }
    else if (octal < 10000) {
      printf("In octal, your number is: %d%d\n", 0, octal);
    }
    else {
      printf("In octal, your number is: %d\n", octal);
    }
  }
  return 0;
}
