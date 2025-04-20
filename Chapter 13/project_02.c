#include <stdio.h>
#include <string.h>

#define MAX_REMIND (int) 50
#define MSG_LEN (int) 60

int read_line(char str[], int n) {

  int ch, i = 0;

  while ((ch = getchar()) != '\n') {
    if (i < n) {
      str[i++] = ch;
    }
  }
  str[i] = '\0';

  return i;
}

int main(void) {

  char reminders[MAX_REMIND][MSG_LEN + 12];
  char month_str[3], day_str[3], hour_str[3], min_str[3], date_str[12], msg_str[MSG_LEN + 1];
  int month, day, hour, min, i, j, num_remind = 0;

  do {
    printf("Enter day (m/d), time (hh:mm), and reminder: ");
    scanf("%2d/%2d", &month, &day);
    scanf("%2d:%2d", &hour, &min);

    if (day < 0 || 31 < day || month < 0 || 12 < month) {
      printf("Error: date outside of allowed range\n");
    } else if (day != 0 && month != 0) {
      day_str[0] = '\0';
      if (month < 10) {
        sprintf(month_str, "0%d", month);
      } else {
        sprintf(month_str, "%d", month);
      }
      if (day < 10) {
        sprintf(day_str, "0%d", day);
      } else {
        sprintf(day_str, "%d", day);
      }
      if (hour < 10) {
        sprintf(hour_str, "0%d", hour);
      } else {
        sprintf(hour_str, "%d", hour);
      }
      if (min < 10) {
        sprintf(min_str, "0%d", min);
      } else {
        sprintf(min_str, "%d", min);
      }
      date_str[0] = '\0';
      strcat(date_str, month_str);
      strcat(date_str, "/");
      strcat(date_str, day_str);
      strcat(date_str, " ");
      strcat(date_str, hour_str);
      strcat(date_str, ":");
      strcat(date_str, min_str);

      read_line(msg_str, MSG_LEN);

      for (i = 0; i < num_remind && strcmp(date_str, reminders[i]) >= 0; i++)
        ;
      for (j = num_remind; j > i; j--) {
        strcpy(reminders[j], reminders[j-1]);
      }

      strcpy(reminders[i], date_str);
      strcat(reminders[i], msg_str);

      num_remind++;
    }

  } while (day != 0 && month != 0 && num_remind < MAX_REMIND);

  printf("\nDay   Time  Reminder\n");
  for (i = 0; i < num_remind; i++) {
    printf("%s\n", reminders[i]);
  }

  return 0;
}

