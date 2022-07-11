#include <stdlib.h>
#include <unistd.h>

int array_size(char **array) {
  int n;

  n = 0;
  while (array[n]) {
    n++;
  }
  return n;
}

void array_free(char **array) {
  int n;

  n = 0;
  while (array[n]) {
    free(array[n]);
    n++;
  }
  free(array);
}

static size_t ft_strlen(const char *s) {
  int i;

  i = 0;
  while (*s++)
    i++;
  return (i);
}

void ft_putchar_fd(char c, int fd) { write(fd, &c, 1); }

void ft_putstr_fd(char *s, int fd) {
  while (s && *s)
    ft_putchar_fd(*s++, fd);
}

static void ft_bzero(void *s, size_t n) {
  while (n--)
    ((char *)s)[n] = 0;
}

static void *ft_calloc(size_t count, size_t size) {
  void *ptr;

  ptr = malloc(size * count);
  if (!ptr)
    return (NULL);
  ft_bzero(ptr, size * count);
  return (ptr);
}

static size_t ft_strlcpy(char *dst, const char *src, size_t dstsize) {
  size_t i;

  if (dstsize) {
    i = 0;
    while (i < (dstsize - 1) && src[i]) {
      dst[i] = src[i];
      i++;
    }
    dst[i] = 0;
  }
  return (ft_strlen(src));
}

static int ft_isdigit(int c) { return (c >= '0' && c <= '9'); }

static int ft_isspace(char c) {
  if (c == ' ' || c == '\t' || c == '\v' || c == '\r' || c == '\f' || c == '\n')
    return (1);
  return (0);
}

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

static size_t get_split_n(const char *s, char c) {
  size_t n;

  n = 0;
  while (*s) {
    if (*s == c)
      s++;
    else {
      while (*s != c && *s)
        s++;
      n++;
    }
  }
  return (n);
}

char **ft_split(char const *s, char c) {
  size_t i;
  size_t strs_i;
  char **strs;

  if (!s)
    return (NULL);
  strs = ft_calloc(get_split_n(s, c) + 1, sizeof(char *));
  if (!strs)
    return (NULL);
  strs_i = 0;
  while (*s) {
    if (*s == c)
      s++;
    else {
      i = 0;
      while (*s != c && *s && ++i)
        s++;
      strs[strs_i] = ft_calloc(i + 1, sizeof(char));
      ft_strlcpy(strs[strs_i++], s - i, i + 1);
    }
  }
  strs[strs_i] = NULL;
  return (strs);
}
