#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE (int) 10

int main(void) {

  char elem, array[SIZE * SIZE] = {'A'};
  int valid_moves[4] = {0};
  int cur_pos = 0, old_pos = -1, move;

  // set rand() function's seed
  srand((unsigned) time(NULL));

  for (char ch = 'B'; ch <= 'Z' && cur_pos != old_pos; ch++) {

    old_pos = cur_pos;

    // check if upward movement is valid
    if (cur_pos >= SIZE && !array[cur_pos - SIZE]) {
      valid_moves[0] = 1;
    }
    else {
      valid_moves[0] = 0;
    }
    // check if rightward movement is valid
    if (cur_pos % SIZE != SIZE - 1 && !array[cur_pos + 1]) {
      valid_moves[1] = 1;
    }
    else {
      valid_moves[1] = 0;
    }
    // check if downward movement is valid
    if (cur_pos < SIZE*(SIZE - 1) && !array[cur_pos + SIZE]) {
      valid_moves[2] = 1;
    }
    else {
      valid_moves[2] = 0;
    }
    // check if leftward movement is valid
    if (cur_pos % SIZE != 0 && !array[cur_pos - 1]) {
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
            cur_pos -= SIZE;
            break;
          case 1:
            cur_pos += 1;
            break;
          case 2:
            cur_pos += SIZE;
            break;
          case 3:
            cur_pos -= 1;
            break;
        }
        array[cur_pos] = ch;
      }
      else {
        move = (move + 1) % 4;
      }
    }

  }

  // print out array
  for (int i = 0; i < SIZE*SIZE; i++) {
    if (array[i]) {
      elem = array[i];
    }
    else {
      elem = '.';
    }
    printf("%c ", elem);
    if (i % SIZE == SIZE - 1) {
      printf("\n");
    }
  }

  return 0;
}

