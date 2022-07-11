void ft_putchar(char c);

void print_char(int col_i, int line_i, int col_n, int line_n) {
  if (col_i == 1 || col_i == col_n) {
    if (line_i == 1 || line_i == line_n) {
      ft_putchar('o');
    } else {
      ft_putchar('|');
    }
  } else {
    if (line_i == 1 || line_i == line_n) {
      ft_putchar('-');
    } else {
      ft_putchar(' ');
    }
  }
}

void rush(int col_n, int line_n) {
  int col_i;
  int line_i;

  if (col_n > 0 && line_n > 0) {
    line_i = 1;
    while (line_i <= line_n) {
      col_i = 1;
      while (col_i <= col_n) {
        print_char(col_i, line_i, col_n, line_n);
        col_i++;
      }
      line_i++;
      ft_putchar('\n');
    }
  }
}
