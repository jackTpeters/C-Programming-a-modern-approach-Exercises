#include <stdio.h>

int main(void) {

  int exit = 0;

  while (!exit) {

    // initialize hand variables
    int num_in_rank[13] = {0}, num_in_suit[4] = {0}, hand[4][13] = {0}, cards_in_hand = 0;
    int flush = 0, straight = 0, four_pair = 0, three_pair = 0, num_two_pairs = 0;

    // read in hand
    do {
      char rank, suit;
      int rank_int, suit_int;

      printf("Enter a card: ");
      rank = getchar();
      suit = getchar();
      while (getchar() != '\n')
        ;

      if (rank != '0') {
        if ((suit != 'c' && suit != 'd' && suit != 'h' && suit != 's') || 
            (rank != '2' && rank != '3' && rank != '4' && rank != '5' && rank != '6' && rank != '7' && 
            rank != '8' && rank != '9' && rank != 't' && rank != 'j' && rank != 'q' && rank != 'k' && rank != 'a')) {
          printf("Bad card; ignored.\n");
        } else {
          switch (suit) {
            case 'c':
              suit_int = 0;
              break;
            case 'd':
              suit_int = 1;
              break;
            case 'h':
              suit_int = 2;
              break;
            case 's':
              suit_int = 3;
              break;
          }

          switch (rank) {
            case '2':
              rank_int = 0;
              break;
            case '3':
              rank_int = 1;
              break;
            case '4':
              rank_int = 2;
              break;
            case '5':
              rank_int = 3;
              break;
            case '6':
              rank_int = 4;
              break;
            case '7':
              rank_int = 5;
              break;
            case '8':
              rank_int = 6;
              break;
            case '9':
              rank_int = 7;
              break;
            case 't':
              rank_int = 8;
              break;
            case 'j':
              rank_int = 9;
              break;
            case 'q':
              rank_int = 10;
              break;
            case 'k':
              rank_int = 11;
              break;
            case 'a':
              rank_int = 12;
              break;
          }

          if (hand[suit_int][rank_int]) {
            printf("Duplicate card; ignored.\n");
          } else {
            hand[suit_int][rank_int] = 1;
            cards_in_hand++;
            num_in_suit[suit_int]++;
            num_in_rank[rank_int]++;
          }
        }
      } else {
        exit = 1;
      }
    } while (cards_in_hand < 5 && !exit);

    // analyze hand
    if (!exit) {

      // check for flush
      for (int i = 0; i < 4; i++) {
        if (num_in_suit[i] == 5) {
          flush = 1;
        }
      }

      // check for rank
      int consec = 0;
      for (int i = 0; i < 13; i++) {
        switch (num_in_rank[i]) {
          case 4:
            four_pair = 1;
            i = 13;
            break;
          case 3:
            three_pair = 1;
            i = 13;
            break;
          case 2:
            num_two_pairs++;
            break;
          case 1:
            if (i > 0 && num_in_rank[i - 1]) {
              consec++;
            } else {
              consec = 0;
            }
            break;
          default:
            consec = 0;
            break;
        }
      }
      if (consec == 4) {
        straight = 1;
      }

      // print result
      if (straight && flush) {
        printf("Straight flush");
      } else if (four_pair) {
        printf("Four of a kind");
      } else if (three_pair && num_two_pairs) {
        printf("Full house");
      } else if (flush) {
        printf("Flush");
      } else if (straight) {
        printf("Straight");
      } else if (three_pair) {
        printf("Three of a kind");
      } else if (num_two_pairs == 2) {
        printf("Two pairs");
      } else if (num_two_pairs) {
        printf("Pair");
      } else {
        printf("High card");
      }
      printf("\n\n");

    }

  }

  return 0;
}

