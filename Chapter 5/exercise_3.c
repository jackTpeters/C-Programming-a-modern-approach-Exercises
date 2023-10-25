# include <stdio.h>

int main(void) {
  float shares, price, value, commission, rival_commission;
  printf("Enter the number of shares sold: ");
  scanf("%f", &shares);
  printf("Enter the price per share: $");
  scanf("%f", &price);
  if (shares < 0.0000f || price < 0.0000f){
    printf("Entered shares or price invalid!\n");
    return 0;
  }
  value = shares * price;
  if (value < 2500.00f) {
    commission = 30.00f + 0.017f * value;
  }
  else if (value < 6250.00f) {
    commission = 56.00f + 0.0066f * value;
  }
  else if (value < 20000.00f) {
    commission = 76.00f + 0.0034f * value;
  }
  else if (value < 50000.00f) {
    commission = 100.00f + 0.0022f * value;
  }
  else if (value < 500000.00f) {
    commission = 155.00f + 0.0011f * value;
  }
  else {
    commission = 255.00f + 0.0009f * value;
  }
  if (commission < 39.00f) {
    commission = 39.00f;
  }
  rival_commission = 33.00f;
  if (shares < 2000.00f) {
    rival_commission += 0.03f * shares;
  }
  else {
    rival_commission += 0.02f * shares;
  }
  printf("\n");
  printf("Original commission: $%.2f\n", commission);
  printf("Rival commission: $%.2f\n", rival_commission);
  return 0;
}
