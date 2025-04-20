#include <stdio.h>

int main(void) {

  float value, com;

  do {

    printf("Enter value of trade: ");
    scanf("%f", &value);

    // broker's commission
    if (value > 0) {

      if (value < 2500.00f) {
        com = 30.00f + 0.017f * value;
      }
      else if (value < 6250.00f) {
        com = 56.00f + 0.0066f * value;
      }
      else if (value < 20000.00f) {
        com = 76.00f + 0.0034f * value;
      }
      else if (value < 50000.00f) {
        com = 100.00f + 0.0022f * value;
      }
      else if (value < 500000.00f) {
        com = 155.00f + 0.0011f * value;
      }
      else {
        com = 255.00f + 0.0009f * value;
      }

      if (0.00f < com && com < 39.00f) {
        com = 39.00f;
      }

      printf("Commission: $%.2f\n", com);

    }
  } while (value > 0);

  return 0;
}

