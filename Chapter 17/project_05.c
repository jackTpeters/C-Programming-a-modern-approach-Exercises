#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LEN (int) 20

int compare_words(const void *p, const void *q) {
  return strcmp(*(char **)p, *(char **)q);
}

int main(void) {

  char **words;
  char ch, word[MAX_WORD_LEN + 1];
  int i, num_words = 0;

  do {
    printf("Enter word: ");
    for (i = 0; i < MAX_WORD_LEN && (ch = getchar()) != '\n'; i++) {
      word[i] = ch;
    }
    word[i] = '\0';

    if (i > 0) {
      num_words++;

      if (words) {
        words = realloc(words, num_words * sizeof(*words));
      } else {
        words = malloc(sizeof(*words));
      }
      if (!words) {
        printf("Unable or allocate memory for words array.\n");
        exit(1);
      }
      words[num_words - 1] = malloc(i + 1);
      strcpy(words[num_words - 1], word);
    }

  } while (i > 0);

  qsort(words, num_words, sizeof(*words), compare_words);

  printf("In sorted order:");
  for (i = 0; i < num_words; i++) {
    printf(" %s", words[i]);
  }
  putchar('\n');

  return 0;
}

