#ifndef UTILS_H
#define UTILS_H

#define BUFFER_SIZE 100
#include <unistd.h>

size_t ft_strlen(const char *s);
void ft_putchar_fd(char c, int fd);
void ft_putstr_fd(char *s, int fd);
char *ft_strdup(const char *s);
char *ft_strchr(const char *s, int c);
char *ft_substr(char const *s, unsigned int start, size_t len);
char *ft_strjoin(char const *s1, char const *s2);
char *get_next_line(int fd);
void ft_bzero(void *s, size_t n);
size_t ft_strlcpy(char *dst, const char *src, size_t dstsize);
char **ft_split(char const *s, char c);
char *ft_strtrim(char const *s1, char const *set);
void *ft_calloc(size_t count, size_t size);
int ft_atoi(const char *str);
int ft_isdigit(int c);
int array_size(char **array);
void array_free(char **array);

#endif
