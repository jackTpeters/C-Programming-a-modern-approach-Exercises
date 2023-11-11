#include <stdio.h>
// Smallest value of int n that causes failure on a 64-bit machine is ~sqrt(2^31) = 46341
// Smallest value of int n that causes failure on a 32-bit machine is ~sqrt(2^31) = 46341
// Smallest value of int n that causes failure on a 16-bit machine is ~sqrt(2^15) = 182
// Smallest value of short n that causes failure on a 64-bit machine is ~sqrt(2^15) = 182
// Samllest value of short n that causes failure on a 32-bit machine is ~sqrt(2^15) = 182
// Smallest value of short n that causes failure on a 16-bit machine is ~sqrt(2^15) = 182
// Smallest value of long n that causes failure on a 64-bit machine is ~sqrt(2^63) = 3037000500
// Smallest value of long n that causes failure on a 32-bit machine is ~sqrt(2^31) = 46341
// Smallest value of long n that causes failure on a 16-bit mqchine is ~sqrt(2^31) = 46341

int main(void) {
  int n;
  printf("This program prints a tables of squares.\n");
  printf("Enter number of entries in table: ");
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    printf("%10d%30d\n", i, i * i);
  }
  return 0;
}
