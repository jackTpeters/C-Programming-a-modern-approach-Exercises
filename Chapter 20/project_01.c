#include <stdio.h>
#include <stdint.h>

union float_struct {
  float f;
  struct {
    uint32_t frac: 23, exp: 8, l_bit: 1;
  } parts;
};

int main(void) {

  union float_struct fs;

  fs.parts.l_bit = 1;
  fs.parts.exp = 128;
  fs.parts.frac = 0;

  printf("Value stored is %.2f\n", fs.f);

  return 0;
}

