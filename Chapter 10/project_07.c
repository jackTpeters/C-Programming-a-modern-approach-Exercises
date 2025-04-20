#include <stdio.h>

#define MAX_DIGITS (int) 10

int main(void) {

  char ch, digits[10][3][3] = { {{' ','_',' '}, {'|',' ','|'}, {'|','_','|'}},
                                {{' ',' ',' '}, {' ',' ','|'}, {' ',' ','|'}},
                                {{' ','_',' '}, {' ','_','|'}, {'|','_',' '}},
                                {{' ','_',' '}, {' ','_','|'}, {' ','_','|'}},
                                {{' ',' ',' '}, {'|','_','|'}, {' ',' ','|'}},
                                {{' ','_',' '}, {'|','_',' '}, {' ','_','|'}},
                                {{' ','_',' '}, {'|','_',' '}, {'|','_','|'}},
                                {{' ','_',' '}, {' ',' ','|'}, {' ',' ','|'}},
                                {{' ','_',' '}, {'|','_','|'}, {'|','_','|'}},
                                {{' ','_',' '}, {'|','_','|'}, {' ','_','|'}}
  };
  int numbers[MAX_DIGITS], numbers_i = 0;

  // read in numbers
  printf("Enter a number: ");
  while ((ch = getchar()) != '\n' && numbers_i < MAX_DIGITS) {
    switch (ch) {
      case '0':
        numbers[numbers_i++] = 0;
        break;
      case '1':
        numbers[numbers_i++] = 1;
        break;
      case '2':
        numbers[numbers_i++] = 2;
        break;
      case '3':
        numbers[numbers_i++] = 3;
        break;
      case '4':
        numbers[numbers_i++] = 4;
        break;
      case '5':
        numbers[numbers_i++] = 5;
        break;
      case '6':
        numbers[numbers_i++] = 6;
        break;
      case '7':
        numbers[numbers_i++] = 7;
        break;
      case '8':
        numbers[numbers_i++] = 8;
        break;
      case '9':
        numbers[numbers_i++] = 9;
        break;
    }
  }

  // print seven segment numbers
  if (numbers_i > 0) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < numbers_i; j++) {
        for (int k = 0; k < 3; k++) {
          putchar(digits[numbers[j]][i][k]);
        }
        putchar(' ');
      }
      printf("\n");
    }
  }

  return 0;
}
