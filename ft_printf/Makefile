# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agaleeva <agaleeva@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/25 13:11:57 by agaleeva          #+#    #+#              #
#    Updated: 2024/08/23 16:41:52 by agaleeva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
LIBFT_DIR = ../libft
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c ft_print.c ft_put.c

OBJ = $(SRC:.c=.o)

HEADER = ../includes/ft_printf.h ../libft/libft.h

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re