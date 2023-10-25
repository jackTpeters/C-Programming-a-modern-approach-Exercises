# include <stdio.h>
# include <stdlib.h>

int main(void) {
  int hour, min, time_in_mins, departure_time, arrival_time;
  printf("Enter a 24-hour time: ");
  scanf("%d:%d", &hour, &min);
  if (hour > 23 || hour < 0 || min > 59 || min < 0) {
    printf("Invalid time!\n");
    return 0;
  }
  time_in_mins = hour * 60 + min;
  departure_time = 8 * 60;
  arrival_time = 10 * 60 + 16;
  if (abs((9 * 60 + 43) - time_in_mins) < abs(departure_time - time_in_mins)) {
    departure_time = 9 * 60 + 43;
    arrival_time = 11 * 60 + 52;
  }
  if (abs((11 * 60 + 19) - time_in_mins) < abs(departure_time - time_in_mins)) {
    departure_time = 11 * 60 + 19;
    arrival_time = 13 * 60 + 31;
  }
  if (abs((12 * 60 + 47) - time_in_mins) < abs(departure_time - time_in_mins)) {
    departure_time = 12 * 60 + 47;
    arrival_time = 15 * 60;
  }
  if (abs((14 * 60) - time_in_mins) < abs(departure_time - time_in_mins)) {
    departure_time = 14 * 60;
    arrival_time = 16 * 60 + 8;
  }
  if (abs((15 * 60 + 45) - time_in_mins) < abs(departure_time - time_in_mins)) {
    departure_time = 15 * 60 + 45;
    arrival_time = 17 * 60 + 55;
  }
  if (abs((19 * 60) - time_in_mins) < abs(departure_time - time_in_mins)) {
    departure_time = 19 * 60;
    arrival_time = 21 * 60 + 20;
  }
  if (abs((21 * 60 + 45) - time_in_mins) < abs(departure_time - time_in_mins)) {
    departure_time = 21 * 60 + 45;
    arrival_time = 23 * 60 + 58;
  }
  printf("Closest departure time is ");
  if ((departure_time / 60) % 12 == 0) {
    printf("12:");
  }
  else {
    printf("%d:", (departure_time / 60) % 12);
  }
  if (departure_time % 60 < 10) {
    printf("0");
  }
  printf("%d ", departure_time % 60);
  if (departure_time < 720) {
    printf("a.m.");
  }
  else {
    printf("p.m.");
  }
  printf(", arriving at %d:", (arrival_time / 60) % 12);
  if (arrival_time % 60 < 10) {
    printf("0");
  }
  printf("%d ", arrival_time % 60);
  if (arrival_time < 720) {
    printf("a.m.\n");
  }
  else {
    printf("p.m.\n");
  }
  return 0;
}
