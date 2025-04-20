#include <stdio.h>

int main(void) {

  float speed;

  printf("Enter a wind speed in knots: ");
  scanf("%f", &speed);

  if (speed < 1) {
    printf("Calm\n");
  }
  else if (speed < 4) {
    printf("Light Air\n");
  }
  else if (speed < 28) {
    printf("Breeze\n");
  }
  else if (speed < 48) {
    printf("Gale\n");
  }
  else if (speed < 63) {
    printf("Storm\n");
  }
  else {
    printf("Hurricane\n");
  }

  return 0;
}

