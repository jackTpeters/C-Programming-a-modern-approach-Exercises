#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(void) {
  return rand() % 6 + 1;
}

int play_game(void) {

  int result = -1, sum = roll_dice() + roll_dice(), point;

  printf("You rolled: %d\n", sum);

  if (sum == 7 || sum == 11) {
    result = 1;
  } else if (sum == 2 || sum == 3 || sum == 12) {
    result = 0;
  } else {
    printf("Your point is %d\n", point = sum);
    do {
      printf("You rolled: %d\n", sum = roll_dice() + roll_dice());
      if (sum == point) {
        result = 1;
      } else if (sum == 7) {
        result = 0;
      }
    } while (result == -1);
  }

  return result;
}

int main(void) {

  int wins = 0, losses = 0;
  char again;

  // set random seed
  srand((unsigned) time(NULL));

  // play games
  do {
    printf("\n");
    if (play_game()) {
      wins++;
      printf("You win!\n");
    } else {
      losses++;
      printf("You lose!\n");
    }
    printf("\nPlay again? ");
    scanf(" %c", &again);
  } while (toupper(again) == 'Y');

  printf("\nWins: %d  Losses: %d\n", wins, losses);

  return 0;
}

