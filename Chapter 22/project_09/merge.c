#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
  int number;
  char name[NAME_LEN+1];
  int on_hand;
};

int main(int argc, char **argv) {

  int ok = 1, num_parts = 0, num_parts_read;
  FILE *fp_output, *fp_input;
  struct part parts[MAX_PARTS], parts_buffer[MAX_PARTS];

  if (argc == 1) {
    printf("usage: merge filename1 filename2 ...\n");
    ok = 0;
  } else {
    if (fp_output = fopen("combined_parts.dat", "wb")) {
      for (int i = 1; i < argc; i++) {
        if (fp_input = fopen(argv[i], "rb")) {
          num_parts_read = fread(parts_buffer, sizeof(struct part), MAX_PARTS, fp_input);
          for (int j = 0, part_index = 0; j < num_parts_read; j++) {
            while (part_index < num_parts && parts_buffer[j].number > parts[part_index].number) {
              part_index++;
            }
            if (num_parts == MAX_PARTS) {
              printf("can't add part %s to list, reached limit\n", parts_buffer[j].name);
            } else if (part_index == num_parts) {
              parts[part_index] = parts_buffer[j];
              num_parts++;
            } else {
              if (parts_buffer[j].number == parts[part_index].number) {
                parts[part_index].on_hand += parts_buffer[j].on_hand;
                if (parts_buffer[j].name != parts[part_index].name) {
                  printf("part names %s and %s do not match, keeping %s\n", parts[part_index].name, parts_buffer[j].name, parts[part_index].name);
                }
              } else {
                for (int k = num_parts; k >= part_index; k--) {
                  parts[k + 1] = parts[k];
                }
                parts[part_index] = parts_buffer[j];
                num_parts++;
              }
            }
          }
          fclose(fp_input);
        } else {
          printf("unable to open file %s, skipping\n", argv[i]);
        }
      }
      fwrite(parts, sizeof(struct part), num_parts, fp_output);
      fclose(fp_output);
    } else {
      printf("unable to open file for writing, aboirting\n");
      ok = 0;
    }
  }

  return 0;
}

