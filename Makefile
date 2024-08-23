NAME = push_swap
CC = cc
LIBFT_DIR = ./libft
PRINTF_DIR = ./ft_printf
CFLAGS = -I. -I$(LIBFT_DIR) -I$(PRINTF_DIR)
LFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf
SRC = ./src/main.c \
	./src/stack_init.c\
	./src/stack_sorted.c \
	./src/stack_utils.c \
	./src/init_a_to_b.c \
	./src/sort_three.c \
	./src/rotate.c \
	./src/swap.c \
	./src/push.c \
	./src/ft_split2.c \
	./src/handle_errors.c \
	./src/reverse_rotate.c \
	./src/init_b_to_a.c \
	./src/sort_stacks.c

OBJ = $(SRC:%.c=%.o)
HEADER = ./src/push_swap.h $(LIBFT_DIR)/libft.h ./includes/ft_printf.h

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_DIR)/libft.a $(PRINTF_DIR)/libftprintf.a
	$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) $(LDFLAGS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ -g3

$(LIBFT_DIR)/libft.a:
	make -C $(LIBFT_DIR)

$(PRINTF_DIR)/libftprintf.a:
	make -C $(PRINTF_DIR)

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re