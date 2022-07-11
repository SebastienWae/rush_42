#ifndef CHECKER_H
#define CHECKER_H

#include "table.h"

int check_pos(t_table *table, int x, int y, int val);

int check_up(t_table *table);
int check_down(t_table *table);
int check_left(t_table *table);
int check_right(t_table *table);

#endif
