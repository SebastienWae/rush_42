NAME = rush-02

RM = rm -rf

CC = gcc
CFLAGS = -g
WARNING = -Wall -Wextra -Werror

SRCS = main.c dict.c utils.c convert.c error.c parse.c
OBJS = $(SRCS:%.c=%.o)

.PHONY: all
all: $(NAME)

%.o: %.cpp
	$(COMPILE.c) $< $(WARNING) -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

.PHONY: clean fclean re
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all
