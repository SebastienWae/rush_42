#ifndef DICT_H
#define DICT_H

typedef struct s_dict t_dict;

struct s_dict {
  unsigned int key;
  char *value;
  t_dict *next;
};

t_dict *dict_new(unsigned int key, char *value);
void dict_append(t_dict **dict, t_dict *elem);
char *dict_find(t_dict **dict, unsigned int key);
void dict_destroy(t_dict **dict);

void dict_print(t_dict **dict);

#endif
