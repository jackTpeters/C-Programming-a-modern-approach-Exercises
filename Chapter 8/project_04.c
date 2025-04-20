#include <stdio.h>

#define N (int) (sizeof(a) / sizeof(a[0]))

int main(void) {

  int a[15];

  printf("Enter %d numbers: ", N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &a[i]);
  }

  printf("In reverse order:");
  for (int i = N - 1; i >= 0; i--) {
    printf(" %d", a[i]);
  }
  printf("\n");

  return 0;
}

