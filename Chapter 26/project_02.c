#include <stdlib.h>
#include <stdio.h>

void thats_all(void) {
  printf("That's all, ");
  return;
}

void folks(void) {
  printf("folks!\n");
  return;
}

int main(void) {

  atexit(folks);
  atexit(thats_all);

  return 0;
}

