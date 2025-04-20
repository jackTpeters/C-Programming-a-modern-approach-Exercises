#include <stdio.h>

int main(void) {

  int digit_seen[10] = {0};
  long n, m;


  do {
    printf("Enter a number: ");
    scanf("%ld", &n);

    m = n;

    for (; m > 0 && !digit_seen[m % 10]; m /= 10) {
      digit_seen[m % 10] = 1;
    }

    if (n > 0) {
      if (m > 0) {
        printf("Repeated digit\n");
      }
      else {
        printf("No repeated digit\n");
      }
      for (int i = 0; i < (int) (sizeof(digit_seen) / sizeof(digit_seen[0])); i++) {
        digit_seen[i] = 0;
      }
    }

  } while (n > 0);

  return 0;
}

