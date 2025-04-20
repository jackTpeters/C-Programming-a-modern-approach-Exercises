#include <string.h>
#include "line.h"
#include "word.h"

#define MAX_WORD_LEN (int) 20

int main(void) {

  char word[MAX_WORD_LEN + 2];
  int word_len, bias = 0;

  clear_line();
  for (; (word_len = read_word(word, MAX_WORD_LEN + 1)) > 0;) {
    if (word_len > MAX_WORD_LEN) {
      word[MAX_WORD_LEN] = '*';
    }
    if (word_len + 1 > space_remaining()) {
      write_line(bias);
      clear_line();
      bias = (bias + 1) % 2;
    }
    add_word(word);
  }
  flush_line();

  return 0;
}

