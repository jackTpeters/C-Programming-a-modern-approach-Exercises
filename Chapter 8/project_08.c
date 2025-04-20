#include <stdio.h>

#define NUM_STUDENTS (int) 5
#define NUM_QUIZES (int) 5

int main(void) {

  int input, student_totals[NUM_STUDENTS] = {0}, quiz_totals[NUM_QUIZES] = {0}, quiz_high[NUM_QUIZES] = {0}, quiz_low[NUM_QUIZES];

  // initialize quiz_low
  for (int i = 0; i < NUM_QUIZES; i++) {
    quiz_low[i] = 100;
  }

  // collect input
  for (int i = 0; i < NUM_STUDENTS; i++) {
    printf("Enter student %d's grades: ", i + 1);
    for (int j = 0; j < NUM_QUIZES; j++) {
      scanf("%d", &input);
      student_totals[i] += input;
      quiz_totals[j] += input;
      if (input > quiz_high[j]) {
        quiz_high[j] = input;
      }
      if (input < quiz_low[j]) {
        quiz_low[j] = input;
      }
    }
  }

  printf("\nStudent total scores:");
  for (int i = 0; i < NUM_STUDENTS; i++) {
    printf("%4d", student_totals[i]);
  }
  printf("\nStudent average scores:");
  for (int i = 0; i < NUM_STUDENTS; i++) {
    printf("%4d", student_totals[i] / NUM_STUDENTS);
  }
  printf("\nQuiz average scores:");
  for (int i = 0; i < NUM_QUIZES; i++) {
    printf("%4d", quiz_totals[i] / NUM_QUIZES);
  }
  printf("\nQuiz high scores:");
  for (int i = 0; i < NUM_QUIZES; i++) {
    printf("%4d", quiz_high[i]);
  }
  printf("\nQuiz low scores:");
  for (int i = 0; i < NUM_QUIZES; i++) {
    printf("%4d", quiz_low[i]);
  }
  printf("\n");

  return 0;
}

