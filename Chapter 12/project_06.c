#include <stdio.h>

void quicksort(int *low, int *high) {

  if (low < high) {

    // split array
    int *low_s = low, *high_s = high;
    int part_element = *low_s;
    while (low_s < high_s) {
      while (low_s < high_s && part_element <= *high_s) {
        high_s--;
      }
      if (low_s < high_s) {

        *low_s++ = *high_s;

        while (low_s < high_s && *low_s <= part_element) {
          low_s++;
        }
        if (low_s < high_s) {
          *high_s-- = *low_s;
        }

      }
    }
    *high_s = part_element;
    int *middle = high_s;

    quicksort(low, middle - 1);
    quicksort(middle + 1, high);
  }

  return;
}

int main(void) {

  int a[10];

  printf("Enter 10 numbers to be sorted: ");
  for (int i = 0; i < 10; i++) {
    scanf("%d", &a[i]);
  }

  quicksort(a, a + 9);

  printf("In sorted order: ");
  for (int *p = a; p < a + 10; p++) {
    printf("%d", *p);
  }
  printf("\n");

  return 0;
}

