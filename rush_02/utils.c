#include "utils.h"
#include <stdlib.h>
#include <unistd.h>

size_t ft_strlen(const char *s) {
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

char *ft_strdup(const char *s) {
  char *str;
  size_t i;

  str = malloc(ft_strlen(s) + 1);
  if (!str)
    return (NULL);
  i = 0;
  while (s[i]) {
    str[i] = s[i];
    i++;
  }
  str[i] = 0;
  return (str);
}

char *ft_strchr(const char *s, int c) {
  while (*s) {
    if (*s == (char)c)
      return ((char *)s);
    s++;
  }
  if (*s == (char)c)
    return ((char *)s);
  return (NULL);
}

char *ft_substr(char const *s, unsigned int start, size_t len) {
  size_t i;
  size_t j;
  char *final;

  if (s) {
    if (start >= ft_strlen(s) || len == 0 || ft_strlen(s) == 0)
      return (ft_strdup(""));
    i = 0;
    while (i < len && s[i + start])
      i++;
    final = (char *)malloc((sizeof(char) * i) + 1);
    if (!(final))
      return (NULL);
    j = 0;
    while (j < i) {
      final[j] = s[start + j];
      j++;
    }
    final[j] = 0;
    return (final);
  }
  return (NULL);
}

char *ft_strjoin(char const *s1, char const *s2) {
  char *str;
  int s1_len;
  int s2_len;
  int i;

  i = 0;
  if (!s1 || !s2)
    return (0);
  s1_len = ft_strlen(s1);
  s2_len = ft_strlen(s2);
  str = malloc(sizeof(char) * (s1_len + s2_len + 1));
  if (!str)
    return (NULL);
  while (s1[i]) {
    str[i] = s1[i];
    i++;
  }
  i = 0;
  while (s2[i])
    str[s1_len++] = s2[i++];
  str[s1_len] = 0;
  return (str);
}

char *get_first_line(char **line_buf) {
  char *line;
  char *tmp_buf;
  char *end_ptr;

  if (!line_buf)
    return (NULL);
  end_ptr = ft_strchr(*line_buf, (int)'\n');
  if (end_ptr) {
    line = ft_substr(*line_buf, 0, (end_ptr - *line_buf) + 1);
    tmp_buf = ft_strdup(end_ptr + 1);
    free(*line_buf);
    *line_buf = tmp_buf;
  } else {
    line = ft_strdup(*line_buf);
    free(*line_buf);
    *line_buf = 0;
  }
  return (line);
}

void read_file(int fd, char **line_buf) {
  int b;
  char buf[BUFFER_SIZE + 1];
  char *line;

  b = 1;
  while (b && !ft_strchr(*line_buf, (int)'\n')) {
    b = read(fd, buf, BUFFER_SIZE);
    if (b < 0)
      break;
    buf[b] = 0;
    line = ft_strjoin(*line_buf, (char *)buf);
    free(*line_buf);
    *line_buf = line;
  }
}

char *get_next_line(int fd) {
  static char *line_buf;

  if (!line_buf) {
    line_buf = malloc(sizeof(char));
    if (!line_buf)
      return (NULL);
    *line_buf = 0;
  }
  read_file(fd, &line_buf);
  if (line_buf && !*line_buf) {
    free(line_buf);
    line_buf = 0;
    return (NULL);
  }
  return (get_first_line(&line_buf));
}

void ft_bzero(void *s, size_t n) {
  while (n--)
    ((char *)s)[n] = 0;
}

void *ft_calloc(size_t count, size_t size) {
  void *ptr;

  ptr = malloc(size * count);
  if (!ptr)
    return (NULL);
  ft_bzero(ptr, size * count);
  return (ptr);
}

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize) {
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

static int ft_checkset(char c, char const *set) {
  size_t index;

  index = 0;
  while (set[index]) {
    if (set[index++] == c)
      return (1);
  }
  return (0);
}

char *ft_strtrim(char const *s1, char const *set) {
  char *str;
  size_t start;
  size_t end;
  size_t index;

  if (!s1 || !set)
    return (NULL);
  start = 0;
  end = ft_strlen(s1);
  while (s1[start] && ft_checkset(s1[start], set))
    start++;
  while (end > start && ft_checkset(s1[end - 1], set))
    end--;
  str = (char *)malloc(sizeof(char) * (end - start) + 1);
  if (!str)
    return (NULL);
  index = 0;
  while (start < end)
    str[index++] = s1[start++];
  str[index] = 0;
  return (str);
}

static int ft_isspace(char c) {
  if (c == ' ' || c == '\t' || c == '\v' || c == '\r' || c == '\f' || c == '\n')
    return (1);
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
      return (-1);
    if (r > 0x7fffffffffffffffLL && sig == 1)
      return (-1);
  }
  return (r * sig);
}

int array_size(char **array) {
  int i;

  i = 0;
  if (array) {
    while (array[i]) {
      i++;
    }
  }
  return i;
}

void array_free(char **array) {
  int n;

  n = 0;
  if (array) {
    while (array[n]) {
      free(array[n]);
      n++;
    }
    free(array);
  }
}
