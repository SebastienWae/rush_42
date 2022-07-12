#include "dict.h"
#include "utils.h"
#include <stdlib.h>

t_dict *dict_new(unsigned int key, char *value) {
  t_dict *new;

  new = ft_calloc(1, sizeof(t_dict));
  if (new) {
    new->key = key;
    new->value = value;
    new->next = NULL;
  }
  return new;
}

void dict_append(t_dict **dict, t_dict *elem) {
  t_dict *tmp;

  if (dict) {
    tmp = *dict;
    if (tmp) {
      while (tmp->next) {
        tmp = tmp->next;
      }
      tmp->next = elem;
    }
  }
}

char *dict_find(t_dict **dict, unsigned int key) {
  t_dict *tmp;

  if (dict) {
    tmp = *dict;
    while (tmp) {
      if (tmp->key == key) {
        return tmp->value;
      }
      tmp = tmp->next;
    }
  }
  return NULL;
}

void dict_destroy(t_dict **dict) {
  t_dict *tmp;

  if (dict) {
    while (*dict) {
      tmp = (*dict)->next;
      free((*dict)->value);
      free(*dict);
      *dict = tmp;
    }
  }
}

// debug function
#include <stdio.h>
void dict_print(t_dict **dict) {
  t_dict *tmp;

  printf("## DICT ##\n");
  if (dict) {
    tmp = *dict;
    while (tmp) {
      printf("key: %u\n value: %s\n\n", tmp->key, tmp->value);
      tmp = tmp->next;
    }
  }
  printf("## END DICT ##\n\n");
}
