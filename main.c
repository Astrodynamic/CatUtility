#include "cat_utility.h"

int main(int argc, char **argv) {
  c_opt opt = {OPT_DEFAULT,
               "benstvET",
               {{"number-nonblank", no_argument, NULL, 'b'},
                {"number", no_argument, NULL, 'n'},
                {"squeeze-blank", no_argument, NULL, 's'},
                {"show-nonprinting", no_argument, NULL, 'v'},
                {NULL, 0, NULL, 0}}};

  check_cat_options(&argc, &argv, &opt);
  cat_print_with_opt(argc, argv, &opt);
  return EXIT_SUCCESS;
}
