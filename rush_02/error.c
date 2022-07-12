#include "error.h"
#include "utils.h"

char *error(enum e_err error) {
  static char *msg;

  if (error == UINT_ERROR) {
    msg = "Error\n";
  } else if (error == DICT_ERROR) {
    msg = "Dict Error\n";
  } else if (error == GET_ERROR) {
    return msg;
  } else if (error == FLUSH_ERROR) {
    ft_putstr_fd(msg, 2);
    msg = NULL;
  }
  return NULL;
}
