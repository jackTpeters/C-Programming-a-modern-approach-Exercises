#include <stdio.h>
#include <ctype.h>

void read_word(int counts[26]) {

  char ch;

  while ((ch = getchar()) != '\n') {
    if (isalpha(ch)) {
      counts[toupper(ch) - 'A']++;
    }
  }

  return;
}

int equal_array(int counts_1[26], int counts_2[26]) {

  int result = 1;

  for (int i = 0; i < 26 && result != 0; i++) {
    if (counts_1[i] != counts_2[i]) {
      result = 0;
    }
  }

  return result;
}

int main(void) {

  int counts_1[26] = {0}, counts_2[26] = {0};

  printf("Enter first word: ");
  read_word(counts_1);

  printf("Enter second word: ");
  read_word(counts_2);

  if (equal_array(counts_1, counts_2)) {
    printf("The words are anagrams.\n");
  } else {
    printf("The words are not anagrams.\n");
  }

  return 0;
}

