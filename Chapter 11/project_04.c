#include <stdio.h>
#include <stdlib.h>

void read_cards(int num_in_rank[], int num_in_suit[]) {
  int card_exists[13][4] = {0}, bad_card = 0, cards_read = 0;

  // reset num_in_rank
  for (int rank = 0; rank < 13; rank++) {
    num_in_rank[rank] = 0;
  }
  // reset num_in_suit
  for (int suit = 0; suit < 4; suit++) {
    num_in_suit[suit] = 0;
  }

  while (cards_read < 5) {
    bad_card = 0;

    printf("Enter a card: ");

    int rank;
    char rank_ch = getchar();
    switch (rank_ch) {
      case '0':
        exit(EXIT_SUCCESS);
      case '2':
        rank = 0;
        break;
      case '3':
        rank = 1;
        break;
      case '4':
        rank = 2;
        break;
      case '5':
        rank = 3;
        break;
      case '6':
        rank = 4;
        break;
      case '7':
        rank = 5;
        break;
      case '8':
        rank = 6;
        break;
      case '9':
        rank = 7;
        break;
      case 't':
      case 'T':
        rank = 8;
        break;
      case 'j':
      case 'J':
        rank = 9;
        break;
      case 'q':
      case 'Q':
        rank = 10;
        break;
      case 'k':
      case 'K':
        rank = 11;
        break;
      case 'a':
      case 'A':
        rank = 12;
        break;
      default:
        bad_card = 1;
        break;
    }

    int suit;
    char suit_ch = getchar();
    switch (suit_ch) {
      case 'c':
      case 'C':
        suit = 0;
        break;
      case 'd':
      case 'D':
        suit = 1;
        break;
      case 'h':
      case 'H':
        suit = 2;
        break;
      case 's':
      case 'S':
        suit = 3;
        break;
      default:
        bad_card = 1;
        break;
    }

    char ch;
    while ((ch = getchar()) != '\n') {
      if (ch != ' ') {
        bad_card = 1;
      }
    }

    if (bad_card) {
      printf("Bad card; ignored.\n");
    } else if (card_exists[rank][suit]) {
      printf("Duplicate card; ignored.\n");
    } else {
      num_in_rank[rank]++;
      num_in_suit[suit]++;
      card_exists[rank][suit] = 1;
      cards_read++;
    }
  }

  return;
}

void analyze_hand(int num_in_rank[], int num_in_suit[], int *straight, int *flush, int *four, int *three, int *pairs) {
  int num_consec = 0, rank;

  *straight = 0;
  *flush = 0;
  *four = 0;
  *three = 0;
  *pairs = 0;

  // check for flush
  for (int suit = 0; suit < 4; suit++) {
    if (num_in_suit[suit] == 5) {
      *flush = 1;
    }
  }

  // check for straight
  for (rank = 0; num_in_rank[rank] == 0; rank++) ;
  for (; rank < 13 && num_in_rank[rank] > 0; rank++) {
    num_consec++;
  }
  if (num_consec == 5) {
    *straight = 1;
  }
  else {
    for (rank = 0; rank < 13 && ! *four; rank++) {
      switch (num_in_rank[rank]) {
        case 4:
          *four = 1;
          break;
        case 3:
          *three = 1;
          break;
        case 2:
          *pairs += 1;
          break;
        default:
          break;
      }
    }
  }

  return;
}

void print_result(int *straight, int *flush, int *four, int *three, int *pairs) {
  if (*straight && *flush) {
    printf("Straight flush");
  } else if (*four) {
    printf("Four of a kind");
  } else if (*three && *pairs) {
    printf("Full house");
  } else if (*flush) {
    printf("Flush");
  } else if (*straight) {
    printf("Straight");
  } else if (*three) {
    printf("Three of a kind");
  } else if (*pairs == 2) {
    printf("Two pairs");
  } else if (*pairs) {
    printf("Pair");
  } else {
    printf("High card");
  }

  printf("\n\n");

  return;
}

int main(void) {

  int num_in_rank[13], num_in_suit[4], straight, flush, four, three, pairs;

  for (;;) {
    read_cards(num_in_rank, num_in_suit);
    analyze_hand(num_in_rank, num_in_suit, &straight, &flush, &four, &three, &pairs);
    print_result(&straight, &flush, &four, &three, &pairs);
  }

  return 0;
}

