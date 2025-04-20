#include <stdio.h>
#include <ctype.h>

int main(void) {

  char ch, msg[80];
  int len_msg, shift;

  printf("Enter message to be encrypted: ");
  for (int i = 0; (ch = getchar()) != '\n' && i < (int) (sizeof(msg) / sizeof(msg[0])); i++, len_msg = i) {
    msg[i] = ch;
  }

  printf("Enter shift amount (1 - 25): ");
  scanf("%d", &shift);

  printf("Encrypted message: ");
  for (int i = 0; i < len_msg; i++) {
    if ('A' <= toupper(msg[i]) && toupper(msg[i]) <= 'Z') {
      ch = ((toupper(msg[i]) - 'A') + shift) % 26 + 'A';
      if (msg[i] > 'Z') {
        ch = tolower(ch);
      }
    } else {
      ch = msg[i];
    }
    putchar(ch);
  }
  putchar('\n');

  return 0;
}

