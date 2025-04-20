#include <stdio.h>
#include <ctype.h>

#define WORD_LEN (int) 50

int are_anagrams(const char *word1, const char *word2) {

  int result = 1, letter_count[26] = {0};

  while (*word1) {
    if (isalpha(*word1)) {
      letter_count[toupper(*word1) - 'A']++;
    }
    word1++;
  }

  while (*word2) {
    if (isalpha(*word2)) {
      letter_count[toupper(*word2) - 'A']--;
    }
    word2++;
  }

  for (int i = 0; i < 26 && result; i++) {
    if (letter_count[i] != 0) {
      result = 0;
    }
  }

  return result;
}

int main(void) {

  char ch, word1[WORD_LEN + 1], word2[WORD_LEN + 2];
  int i;

  printf("Enter first word: ");
  for (i = 0; (ch = getchar()) != '\n'; i++) {
    word1[i] = ch;
  }
  word1[i] = '\0';

  printf("Enter second word: ");
  for (i = 0; (ch = getchar()) != '\n'; i++) {
    word2[i] = ch;
  }
  word2[i] = '\0';

  if (are_anagrams(word1, word2)) {
    printf("The words are anagrams.\n");
  } else {
    printf("The words are not anagrams.\n");
  }

  return 0;
}

