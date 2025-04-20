#include <stddef.h>
#include <stdio.h>

int main(void) {

  struct s {
    char a;
    int b[2];
    float c;
  } s;

  printf("Size of s is %d\n\n", (int) sizeof(s));
  printf("Size of s.a is %d\n", (int) sizeof(s.a));
  printf("Offset of s.a is %d\n\n", (int) offsetof(struct s, a));
  printf("Size of s.b is %d\n", (int) sizeof(s.b));
  printf("Offset of s.b is %d\n\n", (int) offsetof(struct s, b));
  printf("Size of s.c is %d\n", (int) sizeof(s.c));
  printf("Offset of s.c is %d\n", (int) offsetof(struct s, c));

  return 0;
}

