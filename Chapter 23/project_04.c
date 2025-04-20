#include <stdio.h>
#include <string.h>

int main(void) {

  char input[1000], *p;
  char *words[50] = {input};
  int i;

  printf("Enter a list of single spaced words (word1 word2 ...): ");
  scanf("%99[^\n]", &input);

  strtok(input, " ");
  for (i = 1; i < 50 && (p = strtok(NULL, " ")); i++) {
    words[i] = p;
  }

  for (--i; i >= 0; i--) {
    printf("%s ", words[i]);
  }
  printf("\n");

  return 0;
}
