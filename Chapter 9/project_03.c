#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_random_walk(char walk[10][10]) {

  int valid_moves[4] = {0};
  int cur_pos = 0, old_pos = -1, move;

  // set rand() function's seed 
  srand((unsigned) time(NULL));

  // initialize array
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      walk[i][j] = '.';
    }
  }
  walk[0][0] = 'A';

  // perform walk
  for (char ch = 'B'; ch <= 'Z' && cur_pos != old_pos; ch++) {

    old_pos = cur_pos;

    // check if upward movement is valid
    if (cur_pos >= 10 && walk[cur_pos/10 - 1][cur_pos % 10] == '.') {
      valid_moves[0] = 1;
    }
    else {
      valid_moves[0] = 0;
    }
    // check if rightward movement is valid
    if (cur_pos % 10 != 9 && walk[cur_pos/10][cur_pos % 10 + 1] == '.') {
      valid_moves[1] = 1;
    }
    else {
      valid_moves[1] = 0;
    }
    // check if downward movement is valid
    if (cur_pos < 90 && walk[cur_pos/10 + 1][cur_pos % 10] == '.') {
      valid_moves[2] = 1;
    }
    else {
      valid_moves[2] = 0;
    }
    // check if leftward movement is valid
    if (cur_pos % 10 != 0 && walk[cur_pos/10][cur_pos % 10 - 1] == '.') {
      valid_moves[3] = 1;
    }
    else {
      valid_moves[3] = 0;
    }

    // try to make move
    move = rand() % 4;
    for (int i = 0; i < 4 && cur_pos == old_pos; i++) {
      if (valid_moves[move]) {
        switch (move) {
          case 0:
            cur_pos -= 10;
            break;
          case 1:
            cur_pos += 1;
            break;
          case 2:
            cur_pos += 10;
            break;
          case 3:
            cur_pos -= 1;
            break;
        }
        walk[cur_pos/10][cur_pos%10] = ch;
      }
      else {
        move = (move + 1) % 4;
      }
    }

  }

  return;
}

void print_array(char walk[10][10]) {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      printf("%c ", walk[i][j]);
    }
    printf("\n");
  }

  return;
}

int main(void) {

  char walk[10][10];

  generate_random_walk(walk);
  print_array(walk);

  return 0;
}

