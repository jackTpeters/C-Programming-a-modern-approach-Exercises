#include <stdio.h>
#include <ctype.h>

int main(void) {

  char ch;
  int count = 0;

  printf("Enter a sentence: ");

  while ((ch = getchar()) != '\n') {
    switch (toupper(ch)) {
      case 'A': case 'E': case 'I': case 'O': case 'U':
        count++;
        break;
    }
  }

  printf("Your sentence contains %d vowels.\n", count);

  return 0;
}

