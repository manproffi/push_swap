/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_head.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 15:43:02 by sprotsen          #+#    #+#             */
/*   Updated: 2017/02/26 15:45:17 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_HEAD_H
# define PUSH_HEAD_H

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

# define PF ft_printf
# define WF winfile
# define RT rotate
# define LEND ft_lstaddend

# define WSS write(3, "ss\n", 3)
# define WRR write(3, "rr\n", 3)
# define WRRA write(3, "rra\n", 4)
# define WRRB write(3, "rrb\n", 4)
# define WRRR write(3, "rrr\n", 4)

# define SA swap(a, len[0]), (WF(0) == 3 ? write(3, "sa\n", 3) : PF("sa\n"))
# define SB swap(b, len[1]), (WF(0) == 3 ? write(3, "sb\n", 3) : PF("sb\n"))
# define SS swap(a, len[0]), swap(b, len[1]), (WF(0) == 3 ? WSS : PF("ss\n"))
# define PA push_a(a, b, len), (WF(0) == 3 ? write(3, "pa\n", 3) : PF("pa\n"))
# define PB push_b(a, b, len), (WF(0) == 3 ? write(3, "pb\n", 3) : PF("pb\n"))
# define RA rotate(a, len[0]), (WF(0) == 3 ? write(3, "ra\n", 3) : PF("ra\n"))
# define RB rotate(b, len[1]), (WF(0) == 3 ? write(3, "rb\n", 3) : PF("rb\n"))
# define RR RT(a, len[0]), RT(b, len[1]), (WF(0) == 3 ?  WRR : PF("rr\n"))
# define RRA rev_rotate(a, len[0]), (WF(0) == 3 ? WRRA : PF("rra\n"))
# define RRB rev_rotate(b, len[1]), (WF(0) == 3 ? WRRB : PF("rrb\n"))
# define RRR rev_rotate_rot(a, b, len), (WF(0) == 3 ? WRRR : PF("rrr\n"))

void	next_fun1(size_t *a, int len);
void	swap(size_t *row, int len);
void	push_a(size_t *a, size_t *b, int *len);
void	push_b(size_t *a, size_t *b, int *len);
void	rotate(size_t *a, int len);
void	rev_rotate(size_t *a, int len);
void	rev_rotate_rot(size_t *a, size_t *b, int *len);
int		division_stack_a_v1(size_t *a, size_t *b, int *len);
void	division_stack_a_v2(size_t *a, size_t *b, int *len, t_list **list);
int		division_stack_b(size_t *a, size_t *b, int *len, int number);
void	when_len_a_3(size_t *a, size_t *b, int *len);
void	when_len_a_3_but_not_empty(size_t *a, size_t *b, int *len);
void	p_function(size_t *a, size_t *b, int *len_a, int *len_b);
int		division_stack_b_v2(size_t *a, size_t *b, int *len);
int		winfile(int fd);
void	write_in_file(int a);
void	ss_sa(size_t *a, size_t *b, int *len);
void	error(int i);
void	del_list_elem(t_list **list);
void	del_list_1(t_list **list);
void	chang_a(int *a, int len);
void	validation_duplicate_int(int *row, int len);
int		fun_aver_a_v2_next(size_t *a, int *n, int *len);
void	division_stack_a_v2_part1(size_t *a, size_t *b, int *len, int *n);
void	division_stack_a_v2_part2(size_t *a, size_t *b, int *len, int *n);
int		find_sort(size_t *a, int *len);
int		division_stack_a_v1(size_t *a, size_t *b, int *len);
int		fun_aver_v1(size_t *a, int *len, int *n);
int		division_stack_b(size_t *a, size_t *b, int *len, int number);
void	division_stack_b_part1(size_t *a, size_t *b, int *len, int *n);
void	division_stack_b_part2(size_t *a, size_t *b, int *len, int *n);
int		find_aver_for_b(size_t *b, int number, int *n, int *len);

#endif
