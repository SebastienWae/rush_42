#ifndef UTILS_H
#define UTILS_H

void print_error(void);
void ft_putchar_fd(char c, int fd);
void ft_putstr_fd(char *s, int fd);
char **ft_split(char const *s, char c);
int ft_atoi(const char *str);
void array_free(char **array);
int array_size(char **array);

#endif
