#include <stdio.h>
#include <ctype.h>

int main(void) {
  
  char ch, msg[100];
  int i, msg_len;

  printf("Enter a message: ");
  for (i = 0; (ch = getchar()) != '\n'; i++) {
    msg[i] = toupper(ch);
  }
  msg_len = i;

  printf("In B1FF-speak: ");
  for (i = 0; i < msg_len; i++) {
    switch (msg[i]) {
      case 'A':
        putchar('4');
        break;
      case 'B':
        putchar('8');
        break;
      case 'E':
        putchar('3');
        break;
      case 'I':
        putchar('1');
        break;
      case 'O':
        putchar('0');
        break;
      case 'S':
        putchar('5');
        break;
      default:
        putchar(msg[i]);
        break;
    }
  }
  printf("!!!!!!!!!!\n");

  return 0;
}

