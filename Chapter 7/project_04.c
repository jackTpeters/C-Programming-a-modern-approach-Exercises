#include <stdio.h>

int main(void) {

  char ch;

  printf("Enter phone number: ");

  while ((ch = getchar()) != '\n') {

    switch (ch) {

      case 'A': case 'B': case 'C':
        ch = '2';
        break;
      case 'D': case 'E': case 'F':
        ch = '3';
        break;
      case 'G': case 'H': case 'I':
        ch = '4';
        break;
      case 'J': case 'K': case 'L':
        ch = '5';
        break;
      case 'M': case 'N': case 'O':
        ch = '6';
        break;
      case 'P': case 'Q': case 'R': case 'S':
        ch = '7';
        break;
      case 'T': case 'U': case 'V':
        ch = '8';
        break;
      case 'W': case 'X': case 'Y': case 'Z':
        ch = '9';
        break;
    }

    putchar(ch);

  }

  putchar('\n');

  return 0;
}

