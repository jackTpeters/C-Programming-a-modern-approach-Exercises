#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>
#include <complex.h>

int main(void) {

  uint64_t n;
  long double complex root;

  printf("Enter an integer: ");
  scanf("%"SCNu64, &n);

  for (int k = 0; k < n; k++) {
    root = cexpl((long double complex) (2*k*M_PI*I / n));
    printf("%Lf ", creall(root));
    cimagl(root) < 0 ? printf("- %Lfi\n", cimagl(root) * -1.0) : printf("+ %Lfi\n", cimagl(root));
  }

  return 0;
}

