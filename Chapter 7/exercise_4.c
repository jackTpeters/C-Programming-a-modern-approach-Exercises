#include <stdio.h>
#include <ctype.h>

int main(void) {
  char ch, num[32];
  int i = 0;
  printf("Enter phone number: ");
  while ((ch = getchar()) != '\n') {
    if (toupper(ch) == 'A' || toupper(ch) == 'B' || toupper(ch) == 'C') {
      putchar('2');
    }
    else if (toupper(ch) == 'D' || toupper(ch) == 'E' || toupper(ch) == 'F') {
     putchar('3');
    }
    else if (toupper(ch) == 'G' || toupper(ch) == 'H' || toupper(ch) == 'I') {
      putchar('4');
    }
    else if (toupper(ch) == 'J' || toupper(ch) == 'K' || toupper(ch) == 'L') {
      putchar('5');
    }
    else if (toupper(ch) == 'M' || toupper(ch) == 'N' || toupper(ch) == 'O') {
      putchar('6');
    }
    else if (toupper(ch) == 'P' || toupper(ch) == 'Q' || toupper(ch) == 'R' || toupper(ch) == 'S') {
      putchar('7');
    }
    else if (toupper(ch) == 'T' || toupper(ch) == 'U' || toupper(ch) == 'V') {
      putchar('8');
    }
    else if (toupper(ch) == 'W' || toupper(ch) == 'X' || toupper(ch) == 'Y' || toupper(ch) == 'Z') {
      putchar('9');
    }
    else {
      putchar(ch);
    }
  }
  printf("\n");
  return 0;
}
