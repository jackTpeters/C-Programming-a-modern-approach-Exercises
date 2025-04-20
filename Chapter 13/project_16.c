#include <stdio.h>

#define MSG_LEN (int) 100

void reverse(char *message) {

  char *p = message;

  // have p point to last non-zero char in message
  while (*p) {
    p++;
  }
  p--;

  // reverse message
  while (message < p) {
    char temp = *message;

    *message = *p;
    *p = temp;

    message++;
    p--;
  }

  return;
}

int main(void) {

  char ch, msg[MSG_LEN + 1];
  int i;

  printf("Enter a message: ");
  for (i = 0; i < MSG_LEN && (ch = getchar()) != '\n'; i++) {
    msg[i] = ch;
  }
  msg[i] = '\0';

  reverse(msg);

  printf("Reversal is: %s\n", msg);

  return 0;
}

