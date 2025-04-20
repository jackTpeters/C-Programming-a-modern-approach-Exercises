#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void) {
  int in_hand[4][13] = {0}, num_cards, rank, suit;
  const char *rank_code[] = {"Two",
                             "Three",
                             "Four",
                             "Five",
                             "Six",
                             "Seven",
                             "Eight",
                             "Nine",
                             "Ten",
                             "Jack",
                             "Queen",
                             "King",
                             "Ace"};
  const char *suit_code[] = {"clubs",
                            "diamonds",
                            "hearts",
                            "spades"};

  srand((unsigned) time(NULL));

  printf("Enter number of cards in hand: ");
  scanf("%d", &num_cards);

  printf("Your hand: \n");
  while (num_cards > 0) {
    suit = rand() % 4;
    rank = rand() % 13;
    if (!in_hand[suit][rank]) {
      in_hand[suit][rank] = 1;
      num_cards--;
      printf("%s of %s\n", rank_code[rank], suit_code[suit]);
    }
  }
  printf("\n");

  return 0;
}

