#include <stdio.h>
#include <ctype.h>

#define MSG_LEN (int) 80

void encrypt(char *message, int shift) {

  while (*message) {
    if (isalpha(*message)) {
      char ch;
      if (*message > 'Z') {
        ch = 'a';
      } else {
        ch = 'A';
      }
      *message = (*message - ch + shift) % 26 + ch;
    }
    message++;
  }

  return;
}

int main(void) {

  char ch, msg[MSG_LEN + 1];
  int i, shift;

  printf("Enter message to be encrypted: ");
  for (i = 0; i < MSG_LEN && (ch = getchar()) != '\n'; i++) {
    msg[i] = ch;
  }
  msg[i] = '\0';

  printf("Enter shift amount (1 - 25): ");
  scanf("%d", &shift);

  encrypt(msg, shift);

  printf("Encrypted message: %s\n", msg);

  return 0;
}

