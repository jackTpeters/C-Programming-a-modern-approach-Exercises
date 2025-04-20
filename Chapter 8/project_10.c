#include <stdio.h>
#include <math.h>

int main(void) {

  int hour, min, time_mins, diff, dep_mins, arrival_mins;
  int departures[] = {60*8, 60*9+43, 60*11+19, 60*12+47, 60*14, 60*15+45, 60*19, 60*21+45};
  int arrivals[] = {60*10+16, 60*11+52, 60*13+31, 60*15, 60*16+8, 60*17+55, 60*21+20, 60*23+58};

  printf("Enter a 24-hour time: ");
  scanf("%d:%d", &hour, &min);

  time_mins = 60 * hour + min;

  for (int i = 0; i < (int) (sizeof(departures) / sizeof(departures[0])); i++) {
    if (i == 0 || fabs(departures[i] - time_mins) < diff) {
      diff = fabs(departures[i] - time_mins);
      dep_mins = departures[i];
      arrival_mins = arrivals[i];
    }
  }

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

