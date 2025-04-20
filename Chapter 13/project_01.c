#include <stdio.h>
#include <string.h>

#define WORD_LEN (int) 20

int main(void) {

  char ch, smallest_word[WORD_LEN] = "", largest_word[WORD_LEN] = "", new_word[WORD_LEN] = "";
  int count;

  do {
    printf("Enter word: ");

    // read in word
    for (count = 0; count < WORD_LEN && (ch = getchar()) != '\n'; count++) {
      if ('A' <= ch && ch <= 'Z') {
        ch = ch - 'A' + 'a';
      }
      new_word[count] = ch;
    }
    new_word[count] = '\0';

    if (! *smallest_word || strcmp(new_word, smallest_word) < 0) {
      strncpy(smallest_word, new_word, sizeof(smallest_word));
    }
    if (! *largest_word || strcmp(largest_word, new_word) < 0) {
      strncpy(largest_word, new_word, sizeof(largest_word));
    }

  } while (count != 4);

  printf("Smallest word: %s\n", smallest_word);
  printf("Largest word: %s\n", largest_word);

  return 0;
}

