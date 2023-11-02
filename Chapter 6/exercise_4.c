#include <stdio.h>

int main(void) {
  float n, commission;
  printf("Enter value of trade: $");
  scanf("%f", &n);
  while (n > 0.00f) {
    if (n < 2500.00f) {
      commission = 30.00f + 0.017f * n;
    }
    else if (n < 6250.00f) {
      commission = 56.00f + 0.0066f * n;
    }
    else if (n < 20000.00f) {
      commission = 76.00f + 0.0034f * n;
    }
    else if (n < 50000.00f) {
      commission = 100.00f + 0.0022f * n;
    }
    else if (n < 500000.00f) {
      commission = 155.00f + 0.0011f * n;
    }
    else {
      commission = 255.00f + 0.0009f * n;
    }
    if (commission < 39.00f) {
      commission = 39.00f;
    }
    printf("Commission: $%.2f\n\n", commission);
    printf("Enter value of trade: $");
    scanf("%f", &n);
  }
  return 0;
}
