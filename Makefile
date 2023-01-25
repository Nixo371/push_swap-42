NAME = push_swap

SRCS = push_swap.c push.c swap.c rotate.c reverse.c print.c ft_atoi.c \
		pick_sort.c push_swap_min_max.c small_stack.c big_stack.c
OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all $(NAME) clean fclean re