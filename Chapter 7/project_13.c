#include <stdio.h>

int main(void) {

  int num_letters = 0, num_words = 1;
  char ch;

  printf("Enter a sentence: ");

  while ((ch = getchar()) != '\n') {
    if (ch == ' ') {
      num_words++;
    }
    else {
      num_letters++;
    }
  }

  printf("Average word length: %.1f\n", (float) num_letters / num_words);

  return 0;
}

