#include <stdio.h>

int main(void) {

  float r;

  printf("Enter radius: ");
  scanf("%f", &r);
  printf("Volume of sphere: %f\n", 4.0f / 3.0f * 3.141596 * r * r * r);

  return 0;
}

