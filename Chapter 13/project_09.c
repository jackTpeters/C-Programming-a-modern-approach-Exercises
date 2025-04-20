#include <stdio.h>
#include <ctype.h>

int compute_vowel_count(const char *sentence) {
  int count = 0;

  for (; *sentence; sentence++) {
    switch (toupper(*sentence)) {
      case 'A': case 'E': case 'I': case 'O': case 'U':
        count++;
        break;
    }
  }

  return count;
}

int main(void) {

  char ch, sentence[100];
  int i = 0;

  printf("Enter a sentence: ");

  do {
    ch = getchar();

    if (ch == '\n') {
      sentence[i] = '\0';
    } else {
      sentence[i] = ch;
    }

    i++;
  } while (ch != '\n');

  printf("Your sentence contains %d vowels.\n", compute_vowel_count(sentence));

  return 0;
}

