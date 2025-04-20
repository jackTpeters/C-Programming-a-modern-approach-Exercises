#include <stdio.h>

int main(void) {

  float shares, price, value, com, com_rival;

  printf("Enter the number of shares: ");
  scanf("%f", &shares);
  printf("Enter the price per share: ");
  scanf("%f", &price);
  value = shares * price;

  // broker's commission
  if (value == 0) {
    com = 0.00f;
  }
  else if (value < 2500.00f) {
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

  // rival broker's commision
  if (shares == 0) {
    com_rival = 0.00f;
  }
  else if (shares < 2000) {
    com_rival = 33.00f + 0.03f * shares;
  }
  else {
    com_rival = 33.00f + 0.02 * shares;
  }

  printf("Commission: $%.2f\n", com);
  printf("Rival's commission: $%.2f\n", com_rival);

  return 0;
}

