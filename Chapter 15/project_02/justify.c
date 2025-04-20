#include <stdio.h>
#include <string.h>
#include "line.h"
#include "word.h"

#define MAX_WORD_LEN (int) 10

int main(void) {

  char word[MAX_WORD_LEN + 1];
  int word_len;

  clear_line();
  for (; (word_len = read_word(word, MAX_WORD_LEN)) > 0;) {
    if (word_len + 1 > space_remaining()) {
      write_line();
      clear_line();
    }
    add_word(word);
  }
  flush_line();

  return 0;
}

