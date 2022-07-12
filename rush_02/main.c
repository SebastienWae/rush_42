#include "dict.h"
#include "utils.h"
#include "convert.h"
#include "parse.h"
#include "error.h"
#include <stdlib.h>

static void convert_input(t_dict **dict, char *input) {
  unsigned int value;
  char *output;

  value = parse_input(input);
  if (!error(GET_ERROR)) {
    output = NULL;
    convert_value(dict, value, 0, &output);
    if (output) {
      ft_putstr_fd(output, 1);
      ft_putchar_fd('\n', 1);
      free(output);
    }
  } else {
    error(FLUSH_ERROR);
  }
}

static void read_input(t_dict **dict) {
  char *output;
  char *line;
  char *input;
  unsigned int value;

  line = get_next_line(STDIN_FILENO);
  while (line) {
    input = ft_strtrim(line, "\n");
    free(line);
    if (input) {
      convert_input(dict, input);
      free(input);
    }
    line = get_next_line(STDIN_FILENO);
  }
}

int main(int argc, char **argv) {
  t_dict *dict;
  char *input;
  char *dict_path;

  dict = NULL;
  if (argc > 0 && argc <= 3) {
    if (argc == 3) {
      input = argv[2];
      dict_path = argv[1];
    } else {
      input = argv[1];
      dict_path = "numbers.dict";
    }
    parse_dict(&dict, dict_path);
    if (!error(GET_ERROR) && dict) {
      if (argc == 1) {
        read_input(&dict);
      } else {
        convert_input(&dict, input);
      }
      dict_destroy(&dict);
    } else {
      error(FLUSH_ERROR);
    }
  } else {
    ft_putstr_fd("Error\n", 2);
  }
}
