#include <stdio.h>
#include <ctype.h>

#define NAME_LEN (int) 50

void reverse_name(char *name) {

  char *p = name, first = '\0';
  int past_first = 0;

  while (*p) {
    if (*p != ' ') {

      if (! first) {
        first = *p;
      } else if (past_first) {
        *name++ = *p;
      }

    } else if (first) {
      past_first = 1;
    }

    p++;
  }

  if (p - name < 5) {
    *name = '\0';
  } else {
    *name++ = ',';
    *name++ = ' ';
    *name++ = first;
    *name++ = '.';
    *name = '\0';
  }

  return;
}

int main(void) {

  int i;
  char ch, name[NAME_LEN + 1];

  printf("Enter a first and last name: ");
  for (i = 0; i < NAME_LEN && (ch = getchar()) != '\n'; i++) {
    name[i] = ch;
  }
  name[i] = '\0';

  reverse_name(name);

  printf("%s\n", name);

  return 0;
}

