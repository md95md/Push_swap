NAME = fdf
CC = cc
LIBFT_DIR = ./libft
PRINTF_DIR = ./ft_printf
CFLAGS = -I. -I$(LIBFT_DIR) -I$(PRINTF_DIR) -Iinclude
LFLAGS = -Wall -Wextra -Werror -g
LDFLAGS = -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf
SRC = ./src/init_a_to_b.c \
		./src/main.c \
		./src/rotate.c \
		./src/sort_stacks.c \
		./src/sort_three.c \
		./src/stack_init.c \
		./src/stack_sorted.c \
		./ft_printf/ft_printf.c \
		./ft_printf/ft_put.c \
		./ft_printf/ft_print.c \

OBJ = $(SRC:%.c=%.o)
HEADER = ./inc/push_swap.h  $(LIBFT_DIR)/libft.h $(PRINTF_DIR)/ft_printf.h 

all: $(NAME)

$(NAME): $(OBJ) $(MLX) $(LIBFT_DIR)/libft.a $(PRINTF_DIR)/libftprintf.a 
	$(CC) $(CFLAGS) $(OBJ) $(MLX) $(LFLAGS) $(LDFLAGS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ -g3
 
$(LIBFT_DIR)/libft.a:
	make -C $(LIBFT_DIR)

$(PRINTF_DIR)/libftprintf.a:
	make -C $(PRINTF_DIR)

clean:
	rm -f $(OBJ)
	rm -rf $(MLX_DIR)/build
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re