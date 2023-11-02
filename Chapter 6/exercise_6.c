#include <stdio.h>

int main(void) {
  float n;
  printf("Enter a number: ");
  scanf("%f", &n);
  for (int i = 2; i * i <= n; i += 2) {
    printf("%d\n", i * i);
  }
  return 0;
}
