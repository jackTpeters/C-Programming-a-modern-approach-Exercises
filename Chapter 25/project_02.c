#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int main(int argc, char **argv) {

  int error = 0;
  struct lconv *lp;

  if (argc < 2) {
    printf("Usage: locale_info 'locale_name'\n");
    error = 1;
  } else {
    if (setlocale(LC_ALL, argv[1]) && (lp = localeconv())) {
      printf("decimal_point = \"%s\"\n", lp->decimal_point);
      printf("thousands_sep = \"%s\"\n", lp->thousands_sep);
      printf("grouping = \"%s\"\n", lp->grouping);
      printf("mon_decimal_point = \"%s\"\n", lp->mon_decimal_point);
      printf("mon_thousands_sep = \"%s\"\n", lp->mon_thousands_sep);
      printf("mon_grouping = \"%s\"\n", lp->mon_grouping);
      printf("positive_sign = \"%s\"\n", lp->positive_sign);
      printf("negative_sign = \"%s\"\n", lp->negative_sign);
      printf("currency_symbol = \"%s\"\n", lp->currency_symbol);
      printf("frac_digits = \"%c\"\n", lp->frac_digits);
      printf("p_cs_precedes = \"%c\"\n", lp->p_cs_precedes);
      printf("n_cs_preceses = \"%c\"\n", lp->n_cs_precedes);
      printf("p_sep_by_space = \"%c\"\n", lp->p_sep_by_space);
      printf("n_sep_by_space = \"%c\"\n", lp->n_sep_by_space);
      printf("p_sign_posn = \"%c\"\n", lp->p_sign_posn);
      printf("n_sign_posn = \"%c\"\n", lp->n_sign_posn);
      printf("int_curr_symbol = \"%s\"\n", lp->int_curr_symbol);
      printf("int_frac_digits = \"%c\"\n", lp->int_frac_digits);
      printf("int_p_cs_precedes = \"%c\"\n", lp->int_p_cs_precedes);
      printf("int_n_cs_precedes = \"%c\"\n", lp->int_n_cs_precedes);
      printf("int_p_sep_by_space = \"%c\"\n", lp->int_p_sep_by_space);
      printf("int_n_sep_by_space = \"%c\"\n", lp->int_n_sep_by_space);
      printf("int_p_sign_posn = \"%c\"\n", lp->int_p_sign_posn);
      printf("int_n_sign_posn = \"%c\"\n", lp->int_n_sign_posn);
    } else {
      printf("Locale '%s' not found\n", argv[1]);
      error = 1;
    }
  }

  return error ? EXIT_FAILURE : EXIT_SUCCESS;
}

