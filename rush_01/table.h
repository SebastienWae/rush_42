#ifndef RUSH_H
#define RUSH_H

typedef struct s_rules {
  int up[4];
  int down[4];
  int left[4];
  int right[4];
} t_rules;

typedef struct s_table {
  t_rules rules;
  int map[4][4];
} t_table;

#endif
