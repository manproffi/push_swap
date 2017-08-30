# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/28 19:44:33 by sprotsen          #+#    #+#              #
#    Updated: 2017/01/28 19:44:37 by sprotsen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = stand_fun.c \
		stand_fun_1.c \
		ft_printf.c \
		ft_printf_2.c \
		ft_printf_3.c \
		clear_flag.c \
		for_hex.c \
		for_octal.c \
		pr_space_null_row.c \
		for_string.c \
		for_symbol.c \
		for_decimal.c \
		for_u_decimal.c \
		for_address.c \
		for_wchar.c \
		ft_putwchar.c \
		pr_decimal.c \
		pr_hex.c

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

%.o: %.c
	gcc $(FLAG) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all