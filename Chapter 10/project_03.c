#include <stdio.h>

void quicksort(int a[], int lo, int hi) {

  if (lo >= 0 && hi >= 0 && lo < hi) {

    int p = -1;

    // partition array
    int pivot = a[lo];
    int i = lo - 1, j = hi + 1;
    while (p == -1) {

      do {
        i++;
      } while(a[i] < pivot);

      do {
        j--;
      } while(a[j] > pivot);

      if (i >= j) {
        p = j;
      } else {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }

    }

    quicksort(a, lo, p);
    quicksort(a, p + 1, hi);
  }

  return;
}

int main(void) {

  int exit = 0;

  while (!exit) {

    // initialize hand variables
    int hand[5][2] = {0}, cards_in_hand = 0;
    int flush = 0, straight = 0, four_pair = 0, three_pair = 0, num_two_pairs = 0;

    // read in hand
    for (int i = 0; i < 5 && !exit; ) {
      char rank, suit;

      // get card
      printf("Enter a card: ");
      rank = getchar();
      suit = getchar();
      while (getchar() != '\n')
        ;

      // check if card is valid
      if (rank != '0') {
        if ((suit != 'c' && suit != 'd' && suit != 'h' && suit != 's') || 
            (rank != '2' && rank != '3' && rank != '4' && rank != '5' && rank != '6' && rank != '7' && 
            rank != '8' && rank != '9' && rank != 't' && rank != 'j' && rank != 'q' && rank != 'k' && rank != 'a')) {

          printf("Bad card; ignored.\n");

        } else {

          // make sure card is not duplicate
          int duplicate = 0;
          for (int j = 0; j < i; j++) {
            if (hand[j][0] == rank && hand[j][1] == suit) {
              duplicate = 1;
              j = i;
            }
          }
          if (duplicate) {
            printf("Duplicate card; ignored.\n");
          } else {
            hand[i][0] = rank;
            hand[i][1] = suit;
            i++;
          }

        }
      } else {
        exit = 1;
      }
    }

    // analyze hand
    if (!exit) {

      // check for flush
      if (hand[0][1] == hand[1][1] && hand[1][1] == hand[2][1] && hand[2][1] == hand[3][1] && hand[3][1] == hand[4][1]) {
        flush = 1;
      }

      // analyze ranks
      for (int i = 0; i < 5; i++) {
        int rank_count = 0;

        for (int j = 0; j < 5; j++) {
          if (hand[i][0] == hand[j][0]) {
            rank_count++;
          }
        }

        if (rank_count == 4) {
          four_pair = 1;
          i = 5;
        } else if (rank_count == 3) {
          three_pair = 1;
          i = 5;
        } else if (rank_count == 2) {
          num_two_pairs++;
        }
      }

      // two pairs were counted twice
      num_two_pairs /= 2;

      // check for straight
      int ranks[5] = {0};
      for (int i = 0; i < 5; i++) {
        int rank_int;
        switch (hand[i][0]) {
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
        ranks[i] = rank_int;
      }
      quicksort(ranks, 0, 4);
      if (ranks[0] + 1 == ranks[1] && 
          ranks[0] + 2 == ranks[2] && 
          ranks[0] + 3 == ranks[3] && 
          ranks[0] + 4 == ranks[4]) {
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

