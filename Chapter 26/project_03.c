#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int compar(const void *num_1, const void *num_2) {
  return *((int *) num_1) < *((int *) num_2);
}

int main(void) {

  int arr_sml[1000], arr_med[10000], arr_lrg[100000];
  clock_t start;

  for (int i = 0; i < 100000; i++) {
    if (i < 1000) {
      arr_sml[i] = 999 - i;
    }
    if (i < 10000) {
      arr_med[i] = 9999 - i;
    }
    arr_lrg[i] = 99999 - i;
  }

  start = clock();
  qsort(arr_sml, sizeof(arr_sml[0]), sizeof(arr_sml)/sizeof(arr_sml[0]), compar);
  printf("Took %g secs to sort 1000 length array\n", (clock() - start) / (double) CLOCKS_PER_SEC);

  start = clock();
  qsort(arr_med, sizeof(arr_med[0]), sizeof(arr_med)/sizeof(arr_med[0]), compar);
  printf("Took %g secs to sort 10000 length array\n", (clock() - start) / (double) CLOCKS_PER_SEC);

  start = clock();
  qsort(arr_lrg, sizeof(arr_lrg[0]), sizeof(arr_lrg)/sizeof(arr_lrg[0]), compar);
  printf("Took %g secs to sort 100000 length array\n", (clock() - start) / (double) CLOCKS_PER_SEC);

  return 0;
}

