#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_REMIND (int) 50
#define MAX_MSG_LEN (int) 60

struct vstring {
  int len;
  char chars[];
};

int main(void) {

  struct vstring *reminders[MAX_REMIND];
  char ch, day_str[3], msg_str[MAX_MSG_LEN+1];
  int i, j, day, num_remind = 0, msg_len;

  do {
    if (num_remind >= MAX_REMIND) {
      printf("-- No space left --\n");

    } else {
      printf("Enter day and reminder: ");
      scanf("%2d", &day);

      if (day) {
        sprintf(day_str, "%2d", day);

        // read in message
        while ((ch = getchar()) == ' ')
          ;
        for (i = 0; i < MAX_MSG_LEN && ch != '\n'; i++, ch = getchar()) {
          msg_str[i] = ch;
        }
        msg_str[i] = '\0';
        msg_len = i + 1;

        // adjust list based on date
        for (i = 0; i < num_remind && strcmp(day_str, reminders[i]->chars) >= 0; i++)
          ;
        for (j = num_remind; j > i; j--) {
          reminders[j] = reminders[j - 1];
        }

        reminders[i] = malloc(sizeof(struct vstring) + 2 + msg_len);
        if (!reminders[i]) {
          printf("-- No space left --\n");
          break;
        }

        reminders[i]->len = 2 + msg_len;
        strcpy(reminders[i]->chars, day_str);
        strcat(reminders[i]->chars, msg_str);

        num_remind++;
      }
    }
  } while (num_remind < MAX_REMIND && day);

  printf("\nDay Reminder\n");
  for (i = 0; i < num_remind; i++) {
    printf(" %s\n", reminders[i]->chars);
  }

  return 0;
}
