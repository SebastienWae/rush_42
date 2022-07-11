#include "checker.h"
#include "parse.h"
#include "table.h"
#include "utils.h"

static void print_table(t_table *table) {
  int x;
  int y;

  ft_putstr_fd("─────────────────────────\n", 1);
  x = 0;
  while (x < 6) {
    y = 0;
    ft_putstr_fd("│ ", 1);
    while (y < 6) {
      if ((x == 0 || x == 5) && (y == 0 || y == 5)) {
        ft_putchar_fd(' ', 1);
        ft_putstr_fd(" │ ", 1);
      } else if (x == 0) {
        ft_putchar_fd(table->rules.up[y - 1] + '0', 1);
        ft_putstr_fd(" │ ", 1);
      } else if (x == 5) {
        ft_putchar_fd(table->rules.down[y - 1] + '0', 1);
        ft_putstr_fd(" │ ", 1);
      } else if (y == 0) {
        ft_putchar_fd(table->rules.left[x - 1] + '0', 1);
        ft_putstr_fd(" │ ", 1);
      } else if (y == 5) {
        ft_putchar_fd(table->rules.right[x - 1] + '0', 1);
        ft_putstr_fd(" │ ", 1);
      } else {
        ft_putstr_fd("\033[31m", 1);
        if (table->map[x - 1][y - 1] == -1)
          ft_putstr_fd("■", 1);
        else
          ft_putchar_fd(table->map[x - 1][y - 1] + '0', 1);
        ft_putstr_fd("\033[0m", 1);
        ft_putstr_fd(" │ ", 1);
      }
      y++;
    }
    ft_putstr_fd("\n─────────────────────────\n", 1);
    x++;
  }
}

static int solve(t_table *table, int x, int y) {
  int val;

  val = 1;
  while (val <= 4) {
    if (check_pos(table, x, y, val)) {
      table->map[x][y] = val;
      if (x == 3 && y == 3) {
        if (check_up(table) && check_down(table) && check_left(table) &&
            check_right(table)) {
          return 1;
        } else if (val == 4)
          return 0;
      } else {
        if (y == 3) {
          if (solve(table, x + 1, 0))
            return 1;
        } else {
          if (solve(table, x, y + 1))
            return 1;
        }
      }
    }
    val++;
  }
  return 0;
}

int main(int argc, char **argv) {
  t_table table;

  if (argc == 2) {
    if (parse_input(argv[1], &table.rules)) {
      if (solve(&table, 0, 0) == 1) {
        print_table(&table);
        return 0;
      }
    }
  }
  ft_putstr_fd("Error\n", 2);
}
