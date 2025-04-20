#include <stdio.h>

int main(void) {

  int m_1, d_1, y_1, m_2, d_2, y_2;

  printf("Enter first date: (mm/dd/yy): ");
  scanf("%d/%d/%d", &m_1, &d_1, &y_1);
  printf("Enter second date: (mm/dd/yy): ");
  scanf("%d/%d/%d", &m_2, &d_2, &y_2);

  if (y_1 == y_2) {
    if (m_1 == m_2) {
      if (d_1 == d_2) {
        printf("The two dates are equal\n");
      }
      else if (d_1 < d_2) {
        printf("%d/%d/%d is earlier than %d/%d/%d\n", m_1, d_1, y_1, m_2, d_2, y_2);
      }
      else {
        printf("%d/%d/%d is earlier than %d/%d/%d\n", m_2, d_2, y_2, m_1, d_1, y_1);
      }
    }
    else if (m_1 < m_2) {
      printf("%d/%d/%d is earlier than %d/%d/%d\n", m_1, d_1, y_1, m_2, d_2, y_2);
    }
    else {
      printf("%d/%d/%d is earlier than %d/%d/%d\n", m_2, d_2, y_2, m_1, d_1, y_1);
    }
  }
  else if (y_1 < y_2) {
    printf("%d/%d/%d is earlier than %d/%d/%d\n", m_1, d_1, y_1, m_2, d_2, y_2);
  }
  else {
    printf("%d/%d/%d is earlier than %d/%d/%d\n", m_2, d_2, y_2, m_1, d_1, y_1);
  }

  return 0;
}

