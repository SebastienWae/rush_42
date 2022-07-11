#include "table.h"
#include "utils.h"

static int parse_rules(char **inputs, t_rules *rules) {
  int i;
  int n;

  i = 0;
  while (inputs[i]) {
    n = ft_atoi(inputs[i]);
    if (n >= 1 && n <= 4) {
      if (i < 4)
        rules->up[i] = n;
      else if (i < 8)
        rules->down[i - 4] = n;
      else if (i < 12)
        rules->left[i - 8] = n;
      else if (i < 16)
        rules->right[i - 12] = n;
    } else
      return 0;
    i++;
  }
  return 1;
}

int parse_input(char *input, t_rules *rules) {
  char **inputs;

  inputs = ft_split(input, ' ');
  if (array_size(inputs) == 16) {
    if (parse_rules(inputs, rules)) {
      array_free(inputs);
      return 1;
    }
  }
  array_free(inputs);
  return 0;
}
