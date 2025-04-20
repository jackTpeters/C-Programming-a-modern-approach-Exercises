#include <stdio.h>
#include <ctype.h>

#define SEN_LEN (int) 100

double compute_average_word_length(const char *sentence) {

  int num_letters, num_words;
  char last_ch = ' ';

  while (*sentence) {
    if (isalpha(*sentence)) {
      num_letters++;
      if (last_ch == ' ') {
        num_words++;
      }
    }
    last_ch = *sentence++;
  }

  return (double) num_letters / num_words;
}

int main(void) {

  int i;
  char ch, sentence[SEN_LEN + 1];

  printf("Enter a sentence: ");
  for (i = 0; i < SEN_LEN && (ch = getchar()) != '\n'; i++) {
    sentence[i] = ch;
  }
  sentence[i] = '\0';

  printf("Average word length: %.1f\n", (float) compute_average_word_length(sentence));

  return 0;
}

