#include "cat_utility.h"

void check_cat_options(int *argc, char ***argv, c_opt *opt) {
  int opt_val = 0;
  while ((opt_val = getopt_long(*argc, *argv, opt->s_opt, opt->l_opt, NULL)) !=
         EOF) {
    switch (opt_val) {
      case 'b':
        opt->mutual |= OPT_NUM_NONBLANK;
        break;
      case 'e':
        opt->mutual |= (OPT_NONPRINTING | OPT_END_OF_LINE);
        break;
      case 'n':
        opt->mutual |= OPT_NUM_ALL_LINE;
        break;
      case 's':
        opt->mutual |= OPT_SQUEEZE;
        break;
      case 't':
        opt->mutual |= (OPT_TABS | OPT_NONPRINTING);
        break;
      case 'E':
        opt->mutual |= OPT_END_OF_LINE;
        break;
      case 'T':
        opt->mutual |= OPT_TABS;
        break;
      case 'v':
        opt->mutual |= OPT_NONPRINTING;
        break;
    }
  }

  *argc -= optind;
  *argv += optind;
}

void cat_print_with_opt(const int argc, char **const argv, c_opt *opt) {
  for (int i = 0; i < argc; ++i) {
    FILE *fp = fopen(*(argv + i), "r");
    if (fp == NULL)
      fprintf(stderr, "%s: %s: %s\n", *(argv - optind), *(argv + i),
              strerror(errno));
    else if (opt->mutual == OPT_DEFAULT)
      print_without_opt(fp);
    else
      print_with_opt(fp, opt);
    if (fp != NULL) fclose(fp);
  }
}

void print_without_opt(FILE *fp) {
  char ch;
  while ((ch = fgetc(fp)) != EOF) fputc(ch, stdout);
}

void print_with_opt(FILE *fp, c_opt *opt) {
  int ch, skip = 0, line = 0, prev_ch;
  for (prev_ch = '\n'; (ch = fgetc(fp)) != EOF; prev_ch = ch) {
    if (prev_ch == '\n') {
      if (opt->mutual & OPT_SQUEEZE) {
        if (ch == '\n') {
          if (skip) continue;
          skip = 1;
        } else {
          skip = 0;
        }
      }
      if (((opt->mutual & OPT_NUM_ALL_LINE) &&
           !(opt->mutual & OPT_NUM_NONBLANK)) ||
          ((opt->mutual & OPT_NUM_NONBLANK) && ch != '\n'))
        fprintf(stdout, "%6d\t", ++line);
    }

    if (ch == '\n' && (opt->mutual & OPT_END_OF_LINE)) {
      fprintf(stdout, "$\n");
    } else if (ch == '\t' && (opt->mutual & OPT_TABS)) {
      fprintf(stdout, "^I");
    } else if ((opt->mutual & OPT_NONPRINTING) && ch != '\n' && ch != '\t') {
      if (!isascii(ch) && !isprint(ch)) {
        fprintf(stdout, "M-");
        ch = toascii(ch);
      }
      if (iscntrl(ch))
        fprintf(stdout, "^%c", ch == '\177' ? '?' : ch | 0100);
      else
        putchar(ch);
    } else {
      putchar(ch);
    }
  }
}
