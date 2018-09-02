/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nex_fun.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 19:12:08 by sprotsen          #+#    #+#             */
/*   Updated: 2017/03/15 19:12:10 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_head.h"

void	for_two_or_three_element_next(size_t *a, size_t *b, int *len, int k)
{
	int			n1;
	int			n2;
	int			i;

	n1 = 0;
	n2 = 0;
	i = -1;
	while (b[++i] >= a[0] - k)
		n1++;
	i = len[1];
	while (b[--i] >= a[0] - k)
		n2++;
	while (n1--)
		PA;
	while (n2--)
	{
		RRB;
		PA;
	}
}

void	for_two_or_three_element(size_t *a, size_t *b, int *len, int k)
{
	if (len[1] == 2)
	{
		PA;
		PA;
	}
	else if (len[1] == 3)
	{
		PA;
		PA;
		PA;
	}
	else
		for_two_or_three_element_next(a, b, len, k);
}

void	next_fun2(size_t *a, size_t *b, int *len, t_list **list)
{
	int			n;

	n = (int)(*list)->content_size;
	del_list_elem(list);
	(n == 0) ? exit(0) : 0;
	if (n == 1)
		PA;
	else if (n == 2)
	{
		for_two_or_three_element(a, b, len, 2);
		ss_sa(a, b, len);
	}
	else if (n == 3)
	{
		for_two_or_three_element(a, b, len, 3);
		when_len_a_3_but_not_empty(a, b, len);
	}
	else
	{
		if ((int)(*list)->content_size == 0)
			ft_lstadd(list, ft_lstnew("", division_stack_b_v2(a, b, len)));
		else
			ft_lstadd(list, ft_lstnew("", division_stack_b(a, b, len, n)));
		division_stack_a_v2(a, b, len, list);
	}
}

void	check_sort(size_t *a, int *len)
{
	int			i;
	int			count;

	i = -1;
	count = 0;
	while (++i < len[0] - 1)
		if (a[i] == a[i + 1] - 1)
			count++;
	if (count == len[0] - 1)
		exit(0);
}

void	next_fun1(size_t *a, int length)
{
	t_list		*list;
	size_t		b[length];
	int			len[2];

	len[0] = length;
	len[1] = 0;
	list = ft_lstnew(NULL, 0);
	check_sort(a, len);
	while (len[0] > 3)
		ft_lstadd(&list, ft_lstnew("", division_stack_a_v1(a, b, len)));
	if (len[0] == 2)
	{
		if (a[0] > a[1] && b[0] < b[1])
			SS;
		else if (a[0] > a[1])
			SA;
	}
	else if (len[0] == 3)
		when_len_a_3(a, b, len);
	while (1)
	{
		next_fun2(a, b, len, &list);
	}
}
