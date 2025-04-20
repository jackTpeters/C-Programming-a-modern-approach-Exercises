#include <stdio.h>

int main(void) {

  char ch, sen[200], *p, period;
  int len_sen;

  printf("Enter a sentence: ");
  for (p = sen; (ch = getchar()) != '.' && ch != '?' && ch != '!' && p < sen + 200; p++) {
    *p = ch;
  }
  len_sen = p - sen;
  if (ch == '.' || ch == '?' || ch == '!') {
    period = ch;
  }

  printf("Reversal of sentence: ");
  for (p--; p >= sen - 1 ; p--) {
    if (p == sen - 1 || *p == ' ') {
      for (char *q = p + 1; q < sen + len_sen && *q != ' '; q++) {
        putchar(*q);
      }
      if (p != sen - 1) {
        putchar(' ');
      }
    }
  }
  printf("%c\n", period);

  return 0;
}

