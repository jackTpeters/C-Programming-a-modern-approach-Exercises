#include <stdio.h>

int main(void) {

  int num, denom, m, n, temp;

  printf("Enter a fraction: ");
  scanf("%d/%d", &num, &denom);

  // compute GCD
  m = num;
  n = denom;
  while (n != 0) {
    temp = m % n;
    m = n;
    n = temp;
  }

  num /= m;
  denom /= m;

  printf("In lowest terms: %d/%d\n", num, denom);

  return 0;
}

