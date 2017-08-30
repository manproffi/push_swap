/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_head.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 15:43:02 by sprotsen          #+#    #+#             */
/*   Updated: 2017/02/26 15:45:17 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_HEAD_H
# define CHECKER_HEAD_H

# include "libft.h"
# include "printhead.h"

# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define RESET   "\x1b[0m"

# include <fcntl.h>

# define SA swap(a, len[0])
# define SB swap(b, len[1])
# define SS swap(a, len[0]), swap(b, len[1])
# define PA push_a(a, b, &len[0], &len[1])
# define PB push_b(a, b, &len[0], &len[1])
# define RA rotate(a, &len[0])
# define RB rotate(b, &len[1])
# define RR rotate(a, &len[0]), rotate(b, &len[1])
# define RRA rev_rotate(a, &len[0])
# define RRB rev_rotate(b, &len[1])
# define RRR rev_rotate(a, &len[0]), rev_rotate(b, &len[1])

# define LEND ft_lstaddend

void	validation(t_list *list);
void	error(int i);
void	cast_to_int(t_list *list);
void	pr_list(t_list *list);
void	validation_ins(t_list *list);
void	operation(int *a, int len, t_list **ins, int flag);
void	swap(int *row, int len);
void	push_a(int *a, int *b, int *len_a, int *len_b);
void	push_b(int *a, int *b, int *len_a, int *len_b);
void	rotate(int *a, int *len);
void	rev_rotate(int *a, int *len);
void	del_list(t_list **list);
void	get_ull_int(t_list **parameters, t_list **instruction);
void	read_instruction_2(t_list *ins);
void	validation_int(t_list *list);
int		static_function_for_flag_cv(char *str);
int		static_indentification(int a);

#endif
