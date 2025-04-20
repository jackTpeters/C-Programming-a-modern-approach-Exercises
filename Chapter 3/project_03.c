#include <stdio.h>

int main(void) {

  int gs1, group_id, pub_code, item_num, check;

  printf("Enter ISBN: ");
  scanf("%d-%d-%d-%d-%d", &gs1, &group_id, &pub_code, &item_num, &check);

  printf("GS1 prefix: %d\nGroup identifier: %d\nPublisher code: %d\nItem number: %d\nCheck digit: %d\n", gs1, group_id, pub_code, item_num, check);

  return 0;

}

