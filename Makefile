NAME = push_swap
CC = gcc
LIBFT_DIR = ./libft
PRINTF_DIR = ./ft_printf
CFLAGS = -I. -I$(LIBFT_DIR) -I$(PRINTF_DIR)
LFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf
SRC = ./push_swap/main.c \
	./push_swap/stack_init.c\
	./push_swap/stack_sorted.c \
	./push_swap/stack_utils.c \
	./push_swap/init_a_to_b.c \
	./push_swap/sort_three.c \
	./push_swap/sort_stacks.c \
	./push_swap/rotate.c \
	./push_swap/swap.c \
	./push_swap/ft_split2.c \

OBJ = $(SRC:%.c=%.o)
HEADER = ./push_swap/push_swap.h $(LIBFT_DIR)/libft.h ./includes/ft_printf.h

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