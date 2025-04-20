#include <stdio.h>

#define NUM_WORDS (int) 30
#define WORD_LEN (int) 20

int main(void) {

  char ch, sen[NUM_WORDS][WORD_LEN + 1], period;
  int i, word = 0;

  printf("Enter a sentence: ");
  for (i = 0; i < WORD_LEN && (ch = getchar()) != '.' && ch != '?' && ch != '!';) {
    if (ch == ' ') {
      sen[word][i] = '\0';
      word++;
      i = 0;
    } else {
      sen[word][i] = ch;
      i++;
    }
  }
  sen[word][i] = '\0';
  if (ch == '.' || ch == '?' || ch == '!') {
    period = ch;
  }

  printf("Reversal of sentence: ");
  for (; word >= 0; word--) {
    printf("%s", sen[word]);
    if (word > 0) {
      putchar(' ');
    }
  }
  printf("%c\n", period);

  return 0;
}

