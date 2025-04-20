#include <stdio.h>

#define ABS(x, y) (((x) < (y)) ? ((y) - (x)) : ((x) - (y)))

struct flight_time {
  int departure;
  int arrival;
};

int main(void) {

  struct flight_time schedule[] = {
    {60*8, 60*10+16},
    {60*9+43,60*11+52},
    {60*11+19, 60*13+31},
    {60*12+47, 60*15},
    {60*14, 60*16+8},
    {60*15+45, 60*17+55},
    {60*19, 60*21+20},
    {60*21+45, 60*23+58}
  };
  int i, hour, min, diff = 60*24, time_mins, dep_mins, arrival_mins;

  printf("Enter a 24-hour time: ");
  scanf("%d:%d", &hour, &min);

  time_mins = 60 * hour + min;

  for (i = 0; i < (int) (sizeof(schedule) / sizeof(schedule[0])) && ABS(schedule[i].departure, time_mins) < diff; i++) {
    diff = ABS(schedule[i].departure, time_mins);
  }
  dep_mins = schedule[i - 1].departure;
  arrival_mins = schedule[i - 1].arrival;

  printf("Closest departure time is %d:", (dep_mins/60)%12 == 0 ? 12 : (dep_mins/60)%12);
  if (dep_mins%60 < 10) {
    printf("0");
  }
  printf("%d ", dep_mins%60);
  if (dep_mins/60 < 12) {
    printf("a.m.");
  }
  else {
    printf("p.m.");
  }
  printf(", arriving at %d:", (arrival_mins/60)%12 == 0 ? 12 : (arrival_mins/60)%12);
  if (arrival_mins%60 < 10) {
    printf("0");
  }
  printf("%d ", arrival_mins%60);
  if (arrival_mins/60 < 12) {
    printf("a.m.\n");
  }
  else {
    printf("p.m.\n");
  }

  return 0;
}

