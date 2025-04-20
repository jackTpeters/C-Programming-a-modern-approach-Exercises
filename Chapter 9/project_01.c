#include <stdio.h>

#define N (int) 10

int selection_sort(int len_array, int array[len_array]) {
  int largest_index = 0, temp;

  for (int i = 0; i < len_array; i++) {
    if (array[i] > array[largest_index]) {
      largest_index = i;
    }
  }

  if (largest_index != len_array - 1) {
    temp = array[len_array - 1];
    array[len_array - 1] = array[largest_index];
    array[largest_index] = temp;
  }

  if (len_array > 1) {
    selection_sort(len_array - 1, array);
  }

  return 0;

}

int main(void) {

  int n, a[N];

  printf("Enter %d integers: ", N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &a[i]);
  }

  selection_sort(N, a);

  printf("The sorted array is:");
  for (int i = 0; i < N; i++) {
    printf(" %d", a[i]);
  }
  printf("\n");

  return 0;
}

