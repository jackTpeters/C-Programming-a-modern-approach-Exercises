#include <stdio.h>
#include <ctype.h>

int main(void) {
  const char one_value[] = {'A','E','I','L','N','O','R','S','T','U'};
  const char two_value[] = {'D','G'};
  const char three_value[] = {'B','C','M','P'};
  const char four_value[] = {'F','H','V','W','Y'};
  const char five_value[] = {'K'};
  const char eight_value[] = {'J','X'};
  const char ten_value[] = {'Q','Z'};
  char ch;
  int value = 0;
  printf("Enter a word: ");
  ch = getchar();
  while(ch != '\n') {
    for (int i = 0; i < sizeof(one_value); i++) {
      if (toupper(ch) == one_value[i]) {
        value += 1;
      }
    }
    for (int i = 0; i < sizeof(two_value); i++) {
      if (toupper(ch) == two_value[i]) {
        value += 2;
      }
    }
    for (int i = 0; i < sizeof(three_value); i++) {
      if (toupper(ch) == three_value[i]) {
        value += 3;
      }
    }
    for (int i = 0; i < sizeof(four_value); i++) {
      if (toupper(ch) == four_value[i]) {
        value += 4;
      }
    }
    for (int i = 0; i < sizeof(five_value); i++) {
      if (toupper(ch) == five_value[i]) {
        value += 5;
      }
    }
    for (int i = 0; i < sizeof(eight_value); i++) {
      if (toupper(ch) == eight_value[i]) {
        value += 8;
      }
    }
    for (int i = 0; i < sizeof(ten_value); i++) {
      if (toupper(ch) == ten_value[i]) {
        value += 10;
      }
    }
    ch = getchar();
  }
  printf("Scrabble value: %d\n", value);
  return 0;
}
