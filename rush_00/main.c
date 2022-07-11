void rush(int a, int b);

int ft_isspace(char c) {
  if (c == ' ' || c == '\t' || c == '\v' || c == '\r' || c == '\f' ||
      c == '\n') {
    return (1);
  }
  return (0);
}

int ft_isdigit(int c) { return (c >= '0' && c <= '9'); }

int ft_atoi(const char *str) {
  unsigned long long r;
  int sig;
  int i;

  r = 0;
  sig = 1;
  i = 0;
  while (ft_isspace(str[i]))
    i++;
  if (str[i] == '-') {
    sig = -1;
    i++;
  } else if (str[i] == '+')
    i++;
  while (ft_isdigit(str[i])) {
    r = (r * 10) + (str[i++] - '0');
    if (r > (unsigned long long)(0x7fffffffffffffffLL) + 1 && sig == -1)
      return (0);
    if (r > 0x7fffffffffffffffLL && sig == 1)
      return (-1);
  }
  return (r * sig);
}

int main(int argc, char **argv) {
  if (argc == 3) {
    rush(ft_atoi(argv[1]), ft_atoi(argv[2]));
  }
  return (0);
}
