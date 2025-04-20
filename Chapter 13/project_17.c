#include <stdio.h>
#include <ctype.h>

#define MSG_LEN (int) 100

int is_palindrome(const char *message) {

  int result = 1;
  const char *p;

  // point to last char in message
  for (p = message; *p; p++)
    ;
  p--;

  // compare message characters
  for (; message <= p && result; message++, p--) {
    if (toupper(*message) != toupper(*p)) {
      result = 0;
    }
  }

  return result;
}

int main(void) {

  char ch, msg[MSG_LEN + 1];
  int i;

  printf("Enter a message: ");
  for (i = 0; i < MSG_LEN && (ch = getchar()) != '\n'; i++) {
    msg[i] = ch;
  }
  msg[i] = '\0';

  if (is_palindrome(msg)) {
    printf("Palindrome\n");
  } else {
    printf("Not a palindrome\n");
  }

  return 0;
}

