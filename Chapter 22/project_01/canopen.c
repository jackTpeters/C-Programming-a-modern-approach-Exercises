#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  int ret = 0;
  FILE *fp;

  if (argc < 2) {
    printf("usage: canopen filename1 filename2 ...\n");
    ret = EXIT_FAILURE;
  } else {
    for (int i = 1; i < argc && !ret; i++) {
      if (fp = fopen(argv[i], "r")) {
        printf("%s can be opened\n", argv[i]);
        fclose(fp);
      } else {
        printf("%s can't be opened\n", argv[i]);
        ret = EXIT_FAILURE;
      }
    }
  }

  return ret;
}

