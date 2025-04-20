#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

int main(void) {

  char *c_locale_info, *native_locale_info, *temp;

  // get C locale info
  temp = setlocale(LC_ALL, NULL);
  if (temp) {
    c_locale_info = malloc(strlen(temp) + 1);
    if (c_locale_info) {
      for (int i = 0; i < strlen(temp); i++) {
        c_locale_info[i] = toupper(temp[i]);
      }
      c_locale_info[strlen(temp)] = '\0';
    }
  }

  // get native locale info
  temp = setlocale(LC_ALL, "");
  if (temp) {
    native_locale_info = malloc(strlen(temp) + 1);
    if (native_locale_info) {
      for (int i = 0; i < strlen(temp); i++) {
        native_locale_info[i] = toupper(temp[i]);
      }
      native_locale_info[strlen(temp)] = '\0';

    }
  }

  // compare locales
  if (c_locale_info && native_locale_info) {
    printf("C locale and native locale are %s\n", strcmp(c_locale_info, native_locale_info) == 0 ? "EQUAL" : "NOT EQUAL");
  }

  return 0;
}

