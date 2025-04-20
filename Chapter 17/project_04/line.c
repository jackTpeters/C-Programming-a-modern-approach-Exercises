#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "line.h"

#define MAX_LINE_LEN (int) 60
#define MAX_WORD_LEN (int) 30

#define MAX(x, y) (((x) < (y)) ? (y) : (x))

struct word {
  char word[MAX_WORD_LEN];
  struct word *next;
};

struct word *line = NULL;

int line_len = 0;
int num_words = 0;

void clear_line(void) {

  struct word *p;

  while (line) {
    p = line;
    line = line->next;
    free(p);
  }

  line_len = 0;
  num_words = 0;

  return;
}

void add_word(const char *word) {

  struct word **p = &line;

  // get end of list
  while (*p) {
    p = &(*p)->next;
  }

  // add word to list
  if (*p = malloc(sizeof(*line))) {
    strcpy((*p)->word, word);
    (*p)->next = NULL;

    line_len += strlen(word);
    num_words++;
  }

  return;
}

int space_remaining(void) {
  return MAX_LINE_LEN - line_len - MAX(0, (num_words - 1));
}

void write_line(void) {

  int spaces_to_insert, extra_spaces = space_remaining();
  struct word **word = &line;

  while (*word) {
    printf("%s", (*word)->word);
    word = &(*word)->next;
    if (*word) {
      spaces_to_insert = extra_spaces / (num_words - 1);
      for (int i = 0; i <= spaces_to_insert; i++) {
        putchar(' ');
      }
      extra_spaces -= spaces_to_insert;
    }
    num_words--;
  }
  putchar('\n');

  return;
}

void flush_line(void) {

  struct word **word = &line;

  while (*word) {
    printf("%s", (*word)->word);
    word = &(*word)->next;
    if (*word) {
      putchar(' ');
    }
  }
  putchar('\n');

  return;
}

