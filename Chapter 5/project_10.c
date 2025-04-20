#include <stdio.h>

int main(void) {

  int grade;

  printf("Enter numerical grade: ");
  scanf("%d", &grade);

  if (grade < 0 || grade > 100) {
    printf("ERROR: numerical grade invalid\n");
  }
  else {
    printf("Letter grade: ");
    switch (grade / 10) {
      case 0: case 1: case 2: case 3: case 4: case 5:
        printf("F\n");
        break;
      case 6:
        printf("D\n");
        break;
      case 7:
        printf("C\n");
        break;
      case 8:
        printf("B\n");
        break;
      case 9: case 10:
        printf("A\n");
        break;
    }
  }

  return 0;
}

