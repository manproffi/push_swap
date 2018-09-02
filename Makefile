# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/13 19:05:39 by sprotsen          #+#    #+#              #
#    Updated: 2017/03/13 19:05:41 by sprotsen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PS = push_swap

NAME_CH = checker

HEADER = push_head.h

HEADER2 = checker_head.h

HEADER_DIR = ./includes

HEADER_DIR2 = ./libft

HEADER_DIR3 = ./ft_printf

LIB_ALL = -L$(LIB_DIR) -l$(LIB_NAME) -L$(LIB_DIR2) -l$(LIB_NAME2)

HEAD_ALL = -I $(HEADER_DIR) -I $(HEADER_DIR2) -I $(HEADER_DIR3)

LIB_NAME = ft

LIB_NAME2 = ftprintf

LIB_DIR = ./libft

LIB_DIR2 = ./ft_printf

FLAG = -Wall -Wextra -Werror

SRC_PS = 	src_ps/when_len_a_3.c 			\
			src_ps/push_swap_1.c 			\
			src_ps/push_swap_2.c 			\
			src_ps/nex_fun.c 				\
			src_ps/swap.c 					\
			src_ps/swap1.c 					\
			src_ps/error_del_write.c 		\
			src_ps/new_fun_for_stack_a1.c 	\
			src_ps/new_fun_for_stack_a2.c 	\
			src_ps/new_fun_for_stack_a3.c 	\
			src_ps/new_fun_for_stack_a4.c 

OBJ_PS = $(SRC_PS:.c=.o)

SRC_CH = 	src_ch/checker_1.c 						\
			src_ch/checker_2.c 						\
			src_ch/error.c 							\
			src_ch/operation.c 						\
			src_ch/static_function_for_flag_cv.c 	\
			src_ch/swap2.c

OBJ_CH = $(SRC_CH:.c=.o)

all: $(NAME_PS) $(NAME_CH)

$(NAME_PS):	$(OBJ_PS)
	gcc $(FLAG) -o $(NAME_PS) $(OBJ_PS) $(LIB_ALL)

$(NAME_CH): $(OBJ_CH)
	gcc $(FLAG) -o $(NAME_CH) $(OBJ_CH) $(LIB_ALL)

%.o: %.c
	gcc $(FLAG) $(HEAD_ALL) -c $< -o $@

lib:
	make -C libft
	make -C ft_printf

clean:
	rm -f $(OBJ_PS)
	rm -f $(OBJ_CH)
	$(MAKE) clean -C libft
	$(MAKE) clean -C ft_printf

fclean: clean
	rm -f $(NAME_PS)
	rm -f $(NAME_CH)
	$(MAKE) fclean -C libft
	$(MAKE) fclean -C ft_printf

re: fclean lib all