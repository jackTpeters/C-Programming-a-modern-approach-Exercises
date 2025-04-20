#include <stdio.h>
#include <ctype.h>

int main(void) {

  char ch;
  int j = 0, letter_count[26] = {0};

  printf("Enter first word: ");
  while ((ch = getchar()) != '\n') {
    if (isalpha(ch)) {
      letter_count[toupper(ch) - 'A']++;
    }
  }

  printf("Enter second word: ");
  while ((ch = getchar()) != '\n') {
    if (isalpha(ch)) {
      letter_count[toupper(ch) - 'A']--;
    }
  }

  for (int i = 0; i < (int) (sizeof(letter_count) / sizeof(letter_count[0])) && letter_count[i] == 0; i++, j = i)
    ;

  if (j == (int) (sizeof(letter_count) / sizeof(letter_count[0]))) {
    printf("The words are anagrams.\n");
  } else {
    printf("The words are not anagrams.\n");
  }

  return 0;
}

