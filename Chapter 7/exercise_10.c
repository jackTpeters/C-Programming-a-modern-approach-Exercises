#include <stdio.h>
#include <ctype.h>

int main(void) {
  int vowel_count = 0;
  char ch;
  printf("Enter a sentence: ");
  ch = toupper(getchar());
  while(ch != '\n') {
    if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
      vowel_count += 1;
    }
    ch = toupper(getchar());
  }
  printf("Your sentence contains %d vowels.\n", vowel_count);
  return 0;
}
