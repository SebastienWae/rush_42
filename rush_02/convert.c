#include "dict.h"
#include "utils.h"
#include <stdlib.h>

static void convert_hundreds(t_dict **dict, unsigned int hundreds,
                             char **result) {
  char *tmp;

  if (*result) {
    tmp = *result;
    *result = ft_strjoin(*result, " ");
    free(tmp);
    tmp = *result;
    *result = ft_strjoin(*result, dict_find(dict, hundreds));
    free(tmp);
  } else {
    *result = ft_strdup(dict_find(dict, hundreds));
  }
  tmp = *result;
  *result = ft_strjoin(*result, " hundred");
  free(tmp);
}

static void convert_tens_composed(t_dict **dict, unsigned int tens,
                                  char **result) {
  char *tmp;
  unsigned int ones;

  ones = tens % 10;
  tens = tens / 10 * 10;
  if (*result) {
    tmp = *result;
    *result = ft_strjoin(*result, dict_find(dict, tens));
    free(tmp);
  } else {
    *result = ft_strdup(dict_find(dict, tens));
  }
  if (ones) {
    tmp = *result;
    *result = ft_strjoin(*result, "-");
    free(tmp);
    tmp = *result;
    *result = ft_strjoin(*result, dict_find(dict, ones));
    free(tmp);
  }
}

static void convert_tens(t_dict **dict, unsigned int tens, char **result) {
  char *tmp;

  if (tens) {
    if (*result) {
      tmp = *result;
      *result = ft_strjoin(*result, " and ");
      free(tmp);
    }
    if (tens <= 19) {
      if (*result) {
        tmp = *result;
        *result = ft_strjoin(*result, dict_find(dict, tens));
        free(tmp);
      } else {
        *result = ft_strdup(dict_find(dict, tens));
      }
    } else {
      convert_tens_composed(dict, tens, result);
    }
  } else if (!*result) {
    *result = ft_strdup(dict_find(dict, tens));
  }
}

static int ft_pow(int n, int p) {
  while (--p) {
    n *= n;
  }
  return n;
}

static void convert_power(t_dict **dict, int p, char **result) {
  char *tmp;

  p = ft_pow(1000, p);
  if (*result) {
    tmp = *result;
    *result = ft_strjoin(*result, " ");
    free(tmp);
    tmp = *result;
    *result = ft_strjoin(*result, dict_find(dict, p));
    free(tmp);
  } else {
    *result = ft_strdup(dict_find(dict, p));
  }
}

void convert_value(t_dict **dict, unsigned int value, int p, char **result) {
  unsigned int remainder;
  unsigned int thousands;
  unsigned int hundreds;
  unsigned int tens;

  thousands = value / 1000;
  if (thousands) {
    convert_value(dict, thousands, p + 1, result);
  }
  remainder = value % 1000;
  hundreds = remainder / 100;
  tens = remainder % 100;
  if (hundreds) {
    convert_hundreds(dict, hundreds, result);
  }
  convert_tens(dict, tens, result);
  if (p && (tens || hundreds)) {
    convert_power(dict, p, result);
  }
}
