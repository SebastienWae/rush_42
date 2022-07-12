#include "table.h"

int check_pos(t_table *table, int x, int y, int val) {
  int i;

  i = 0;
  while (i < x) {
    if (table->map[i][y] == val)
      return 0;
    i++;
  }
  i = 0;
  while (i < y) {
    if (table->map[x][i] == val)
      return 0;
    i++;
  }
  return 1;
}

int check_up(t_table *table) {
  int x;
  int y;
  int last;
  int n;

    y = 0;
    while (y < 4) {
      x = 0;
      last = 0;
      n = 0;
      while (x < 4) {
        if (table->map[x][y] > last) {
          last = table->map[x][y];
          n++;
        }
        x++;
      }
      if (n != table->rules.up[y]) {
        return 0;
      }
      y++;
    }
    return 1;
}

int check_down(t_table *table) {
  int x;
  int y;
  int last;
  int n;

  y = 3;
  while (y >= 0) {
    x = 3;
    last = 0;
    n = 0;
    while (x >= 0) {
      if (table->map[x][y] > last) {
        last = table->map[x][y];
        n++;
      }
      x--;
    }
    if (n != table->rules.down[y]) {
      return 0;
    }
    y--;
  }
  return 1;
}

int check_left(t_table *table) {
  int x;
  int y;
  int last;
  int n;

  x = 0;
  while (x < 4) {
    y = 0;
    last = 0;
    n = 0;
    while (y < 4) {
      if (table->map[x][y] > last) {
        last = table->map[x][y];
        n++;
      }
      y++;
    }
    if (n != table->rules.left[x]) {
      return 0;
    }
    x++;
  }
  return 1;
}

int check_right(t_table *table) {
  int x;
  int y;
  int last;
  int n;

  x = 3;
  while (x >= 0) {
    y = 3;
    last = 0;
    n = 0;
    while (y >= 0) {
      if (table->map[x][y] > last) {
        last = table->map[x][y];
        n++;
      }
      y--;
    }
    if (n != table->rules.right[x]) {
      return 0;
    }
    x--;
  }
  return 1;
}
