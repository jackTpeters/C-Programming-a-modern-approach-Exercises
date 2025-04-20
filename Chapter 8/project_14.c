#include <stdio.h>

int main(void) {

  char ch, sen[200], period;
  int len_sen;

  printf("Enter a sentence: ");
  for (int i = 0; (ch = getchar()) != '.' && ch != '?' && ch != '!' && i < (int) (sizeof(sen) / sizeof(sen[0])); i++, len_sen = i) {
    sen[i] = ch;
  }
  if (ch == '.' || ch == '?' || ch == '!') {
    period = ch;
  }

  printf("Reversal of sentence: ");
  for (int i = len_sen - 1; i >= -1; i--) {
    if (i == -1 || sen[i] == ' ') {
      for (int j = i + 1; j != len_sen && sen[j] != ' '; j++) {
        putchar(sen[j]);
      }
      if (i != -1) {
        putchar(' ');
      }
    }
  }
  printf("%c\n", period);

  return 0;

}

