#include <stdio.h>

int main(void) {

  int int_1, int_2, int_3, int_4, max_1, min_1, min_2, max_2;

  printf("Enter four integers: ");
  scanf("%d %d %d %d", &int_1, &int_2, &int_3, &int_4);


  if (int_1 > int_2) {
    max_1 = int_1;
    min_1 = int_2;

  }
  else {
    max_1 = int_2;
    min_1 = int_1;
  }

  if (int_3 > int_4) {
    max_2 = int_3;
    min_2 = int_4;
  }
  else {
    max_2 = int_4;
    min_2 = int_3;
  }

  printf("Largest: %d\n", max_1 > max_2 ? max_1 : max_2);
  printf("Smallest: %d\n", min_1 < min_2 ? min_1 : min_2);

  return 0;
}

