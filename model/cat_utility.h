#ifndef CAT_UTILITY_MODEL_CAT_UTILITY_H_
#define CAT_UTILITY_MODEL_CAT_UTILITY_H_

#include <ctype.h>
#include <errno.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OPT_DEFAULT 0
#define OPT_NUM_NONBLANK 1 << 0
#define OPT_END_OF_LINE 1 << 1
#define OPT_NUM_ALL_LINE 1 << 2
#define OPT_SQUEEZE 1 << 3
#define OPT_TABS 1 << 4
#define OPT_NONPRINTING 1 << 5

typedef struct {
  unsigned int mutual : 8;
  const char* const s_opt;
  const struct option l_opt[5];
} c_opt;

void check_cat_options(int* argc, char*** argv, c_opt* opt);
void cat_print_with_opt(const int argc, char** const argv, c_opt* opt);
void print_without_opt(FILE* fp);
void print_with_opt(FILE* fp, c_opt* opt);

#endif  // CAT_UTILITY_MODEL_CAT_UTILITY_H_
