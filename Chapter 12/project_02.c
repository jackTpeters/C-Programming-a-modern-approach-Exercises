#include <stdio.h>
#include <ctype.h>

int main(void) {

  int a[100], *p, *q;
  char ch;

  printf("Enter a message: ");
  for (p = a; (ch = getchar()) != '\n' && p < a + 100; ) {
    if (isalpha(ch)) {
      *p++ = toupper(ch);
    }
  }

  for (q = a, p--; q <= p && *q == *p; q++, p--) ;

  if (q > p) {
    printf("Palindrome\n");
  } else {
    printf("Not a palindrome\n");
  }

  return 0;
}

