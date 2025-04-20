#include <stdio.h>

#define N (int) 10

void max_min(int a[], int n, int *max, int *min) {

  *max = *min = a[0];

  for (int *p = a + 1; p < a + n; p++) {
    if (*p > *max) {
      *max = *p;
    } else if (*p < *min) {
      *min = *p;
    }
  }

  return;
}

int main(void) {
  int b[N], big, small;

  printf("Enter %d numbers: ", N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &b[i]);
  }

  max_min(b, N, &big, &small);

  printf("Largest: %d\n", big);
  printf("Smallest: %d\n", small);

  return 0;
}

