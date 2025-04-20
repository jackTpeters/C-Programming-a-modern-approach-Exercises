#include <stdio.h>

int mod(int a, int b) {
  int r = a % b;
  return r < 0 ? b + r : r;
}

void create_magic_square(int n, int magic_square[n][n]) {
  for (int i = 0; i < n*n; i++) {
    magic_square[mod(mod(n - i, n) + 2*(i/n), n)][mod(i + (n-1)/2 - i/n, n)] = i+1;
  }
  return;
}

void print_magic_square (int n, int magic_square[n][n]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%5d", magic_square[i][j]);
    }
    putchar('\n');
  }
  return;
}

int main(void) {

  int n;

  printf("This program creates a magic square of a specified size.\n");
  printf("Enter size of magic square (odd integer): ");
  scanf("%d", &n);

  int square[n][n];

  create_magic_square(n, square);

  print_magic_square(n, square);

  return 0;
}

