#include <stdio.h>
#include <ctype.h>

int main(void) {

  int hour, min, time_mins, diff, dep_mins, arrival_mins;
  char meridiem;

  printf("Enter a 12-hour time: ");
  scanf("%d:%d", &hour, &min);
  scanf(" %c", &meridiem);

  // convert 12-hour to 24-hour
  if (toupper(meridiem) == 'P' && hour != 12) {
    hour += 12;
  }

  time_mins = 60 * hour + min;

  diff = (60*8) > time_mins ? (60*8) - time_mins: time_mins - (60*8);
  dep_mins = 60 * 8;
  arrival_mins = 60 * 10 + 16;

  if (diff > ((60*9+43) > time_mins ? (60*9+43) - time_mins : time_mins - (60*9+43))) {

    diff = (60*9+43) > time_mins ? (60*9+43) - time_mins : time_mins - (60*9+43);
    dep_mins = 60 * 9 + 43;
    arrival_mins = 60 * 11 + 52;

    if (diff > ((60*11+19) > time_mins ? (60*11+19) - time_mins : time_mins - (60*11+19))) {

      diff = (60*11+19) > time_mins ? (60*11+19) - time_mins : time_mins - (60*11+19);
      dep_mins = 60 * 11 + 19;
      arrival_mins = 60 * 13 + 31;

      if (diff > ((60*12+47) > time_mins ? (60*12+47) - time_mins : time_mins - (60*12+47))) {

        diff = (60*12+47) > time_mins ? (60*12+47) - time_mins : time_mins - (60*12+47);
        dep_mins = 60 * 12 + 47;
        arrival_mins = 60 * 15;

        if (diff > ((60*14) > time_mins ? (60*14) - time_mins : time_mins - (60*14))) {

          diff = (60*14) > time_mins ? (60*14) - time_mins : time_mins - (60*14);
          dep_mins = 60 * 14;
          arrival_mins = 60 * 16 + 8;

          if (diff > ((60*15+45) > time_mins ? (60*15+45) - time_mins : time_mins - (60*15+45))) {

            diff = (60*15+45) > time_mins ? (60*15+45) - time_mins : time_mins - (60*15+45);
            dep_mins = 60 * 15 + 45;
            arrival_mins = 60 * 17 + 55;

            if (diff > ((60*19) > time_mins ? (60*19) - time_mins : time_mins - (60*19))) {

              diff = (60*19) > time_mins ? (60*19) - time_mins : time_mins - (60*19);
              dep_mins = 60 * 19;
              arrival_mins = 60 * 21 + 20;

              if (diff > ((60*21+45) > time_mins ? (60*21+45) - time_mins : time_mins - (60*21+45))) {

                dep_mins = 60 * 21 + 45;
                arrival_mins = 60 * 23 + 58;

              }
            }
          }
        }
      }
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

