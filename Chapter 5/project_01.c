#include <stdio.h>

int main(void) {

  int num;

  printf("Enter a number: ");
  scanf("%d", &num);

  printf("The number %d has ", num);
  if (num < 10) {
    printf("1");
  }
  else if (num < 100) {
    printf("2");
  }
  else if (num < 1000) {
    printf("3");
  }
  else {
    printf("4");
  }
  printf(" digits\n");

  return 0;
}

