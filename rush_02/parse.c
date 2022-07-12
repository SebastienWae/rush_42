#include "dict.h"
#include "utils.h"
#include "error.h"
#include <fcntl.h>
#include <stdlib.h>
#include <limits.h>

unsigned int parse_input(char *input) {
  int i;
  unsigned int value;

  i = 0;
  value = 0;
  while (input[i]) {
    if (!ft_isdigit(input[i])) {
      error(UINT_ERROR);
      return 0;
    }
    if (value > UINT_MAX / 10 ||
        (value == UINT_MAX / 10 && input[i] - '0' > UINT_MAX % 10)) {
      error(UINT_ERROR);
      return 0;
    }
    value *= 10;
    value += input[i] - '0';
    i++;
  }
  if (i == 0) {
    error(UINT_ERROR);
    return 0;
  }
  return value;
}

static void parse_line(t_dict **dict, char *line) {
  t_dict *new;
  char **kv;
  int key;
  char *value;

  kv = ft_split(line, ':');
  if (kv) {
    if (array_size(kv) == 2) {
      key = ft_atoi(kv[0]);
      if (key >= 0) {
        value = ft_strtrim(kv[1], " \n");
        if (value) {
          if (ft_strlen(value)) {
            new = dict_new(key, value);
            if (new) {
              if (*dict) {
                dict_append(dict, new);
              } else {
                *dict = new;
              }
            }
          }
        }
      }
    }
    array_free(kv);
  }
}

void parse_dict(t_dict **dict, char *dict_path) {
  char *line;
  int fd;

  fd = open(dict_path, O_RDONLY);
  if (fd != -1) {
    line = get_next_line(fd);
    while (line) {
      parse_line(dict, line);
      free(line);
      line = get_next_line(fd);
    }
    close(fd);
    return;
  }
  error(DICT_ERROR);
}
