#include <stdio.h>

int main(void) {
  int chars = 1, words = 1;
  char curr_ch, prev_ch = ' ';
  printf("Enter a sentence: ");
  scanf(" %c", &prev_ch);
  while((curr_ch = getchar()) != '\n') {
    if (curr_ch != ' ') {
      chars += 1;
      if (prev_ch == ' ') {
        words += 1;
      }
    }
    prev_ch = curr_ch;
  }
  printf("Average word length: %.1f\n", (float) chars / words);
  return 0;
}
