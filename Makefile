NAME = push_swap

SRCS = push_swap.c push.c swap.c rotate.c reverse.c \
        pick_sort.c push_swap_min_max.c small_stack.c big_stack.c \
        repeat_functions.c
OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
MAKEFLAGS = --no-print-directory

RM = rm -f

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a -o $(NAME)
	@echo "linked successfully"

$(OBJS):
	@$(CC) $(CFLAGS) -c $(SRCS)
	@echo "compiled successfully"

$(LIBFT):
	@if [ ! -d "libft" ]; then git clone https://github.com/Nixo371/libft-42; echo "cloned libft repository"; fi
	@$(MAKE) -C libft all >/dev/null 2>&1
	@echo "libft compiled correctly"

clean:
	@$(RM) $(OBJS)
	@$(MAKE) -C libft clean
	@echo "removed object files from push_swap"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C libft fclean
	@echo "removed $(NAME)"

re: fclean all

.PHONY: all clean fclean re