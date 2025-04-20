#include <stdlib.h>
#include <stdio.h>
#include <sys/random.h>

int main(void) {

  int buf[1];

  printf("Numbers from C's rand(): ");
  for (int i = 0; i < 1000; i++) {
    printf("%d ", rand() & 1);
  }
  printf("\n\n");

  printf("Numbers from Linux: ");
  for (int i = 0; i < 1000; i++) {
    if (getentropy(buf, 1) == 0) {
      printf("%d ", buf[0] & 1);
    }
  }
  printf("\n");

  return 0;
}

