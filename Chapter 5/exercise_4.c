# include <stdio.h>

int main(void) {
  float speed;
  char const *description;
  printf("Enter a wind speed (in knots): ");
  scanf("%f", &speed);
  if (speed < 0.00f) {
    printf("Entered speed invalid!\n");
    return 0;
  }
  else if (speed < 1.00f) {
    description = "Calm";
  }
  else if (speed <= 3.00f) {
    description = "Light Air";
  }
  else if (speed <= 27.00f) {
    description = "Breeze";
  }
  else if (speed <= 47.00f) {
    description = "Gale";
  }
  else if (speed <= 63.00f) {
    description = "Storm";
  }
  else {
    description = "Hurricane";
  }
  printf("Corresponding wind force: %s\n", description);
  return 0;
}
