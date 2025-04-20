#include <stdio.h>
#include <ctype.h>

int main(void) {

  char ch, numeric_form[20], num_len;

  printf("Enter phone number: ");

  for (int i = 0; (ch = getchar()) != '\n' && i < (int) (sizeof(numeric_form) / sizeof(numeric_form[0])); i++, num_len = i) {

    switch (toupper(ch)) {
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

    numeric_form[i] = ch;

  }

  printf("In numeric form: ");
  for (int i = 0; i < num_len; i++) {
    putchar(numeric_form[i]);
  }
  printf("\n");

  return 0;
}

