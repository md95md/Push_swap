NAME = push_swap
CC = gcc
LIBFT_DIR = ../libft
PRINTF_DIR = ../ft_printf
CFLAGS = -I. -I$(PRINTF_DIR) -g -O0
LFLAGS = -Wall -Wextra -Werror
LIBS = $(LIBFT_DIR)/libft.a $(PRINTF_DIR)/libftprintf.a
SRC = main.c \
	stack_init.c\
	stack_sorted.c \
	init_a_to_b.c \
	sort_three.c \
	sort_stacks.c \
	rotate.c \
	# ../ft_printf/ft_printf.c \
	# ../gft_printf/ft_print.c \
	# ../ft_printf/ft_put.c \

OBJ = $(SRC:%.c=%.o)
HEADER = push_swap.h

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) $(LFLAGS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re