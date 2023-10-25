# include <stdio.h>

int main(void) {
  int num_grade;
  char grade;
  printf("Enter numerical grade: ");
  scanf("%d", &num_grade);
  if (num_grade < 0 || num_grade > 100) {
    printf("Numerical grade invalid!\n");
    return 0;
  }
  switch (num_grade / 10) {
    default:
      grade = 'F';
      break;
    case 6:
      grade = 'D';
      break;
    case 7:
      grade = 'C';
      break;
    case 8:
      grade = 'B';
      break;
    case 9: case 10:
      grade = 'A';
      break;
  }
  printf("Letter grade: %c\n", grade);
  return 0;
}
