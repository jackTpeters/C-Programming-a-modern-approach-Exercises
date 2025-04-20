#include <stdio.h>
#include <ctype.h>

int main(void) {

  char ch, prev_ch = '\0';
  int count = 0;

  while ((ch = getchar()) != EOF) {
    if ((prev_ch == '.' || prev_ch == '?' || prev_ch == '!') && 
        isspace(ch)) {
      count++;
    }
    prev_ch = ch;
  }

  printf("The number of sentences is %d\n", count);

  return 0;
}

