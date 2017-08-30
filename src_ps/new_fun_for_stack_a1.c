/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_fun_for_stack_a1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 20:32:41 by sprotsen          #+#    #+#             */
/*   Updated: 2017/03/29 20:32:43 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_head.h"

int		division_stack_a_v2_next(size_t *a, size_t *b, int *len, int *ind_sort)
{
	int		n[9];

	n[8] = fun_aver_a_v2_next(a, n, len);
	if (n[8] == 0)
		return (0);
	*ind_sort -= n[0];
	if (n[2] <= n[1])
	{
		division_stack_a_v2_part1(a, b, len, n);
		division_stack_a_v2_part2(a, b, len, n);
	}
	else
	{
		division_stack_a_v2_part2(a, b, len, n);
		division_stack_a_v2_part1(a, b, len, n);
	}
	return (n[0]);
}

void	division_stack_a_v2_next2(size_t *a, size_t *b, int *len, int ind_sort)
{
	int		i;
	int		max;

	i = -1;
	max = (int)a[0];
	while (++i < len[0])
		if (max < (int)a[i])
			max = (int)a[i];
	while (max != (int)a[len[0] - 1])
		RRA;
	if (ind_sort == 2)
		ss_sa(a, b, len);
	else if (ind_sort == 3)
		when_len_a_3_but_not_empty(a, b, len);
}

void	division_stack_a_v2(size_t *a, size_t *b, int *len, t_list **list)
{
	int		ind_sort;
	int		k;

	ind_sort = find_sort(a, len);
	k = 10;
	if (ind_sort == 0)
		return ;
	if (ind_sort == 2)
		ss_sa(a, b, len);
	else if (ind_sort == 3)
		when_len_a_3_but_not_empty(a, b, len);
	else
	{
		while (ind_sort > 3)
		{
			k = division_stack_a_v2_next(a, b, len, &ind_sort);
			if (k == 0)
				break ;
			else
				ft_lstadd(list, ft_lstnew("", k));
		}
		division_stack_a_v2_next2(a, b, len, ind_sort);
	}
}

int		fun_aver_b_for_v2(size_t *b, int *len, int *n)
{
	int		row[len[1]];
	int		aver;
	int		i;

	i = -1;
	aver = 0;
	while (++i < len[1])
		row[i] = b[i];
	ft_sortmass(row, len[1]);
	aver = row[len[1] / 2 - 1];
	*n = len[1] - aver;
	return (aver);
}

int		division_stack_b_v2(size_t *a, size_t *b, int *len)
{
	int		aver;
	int		n;
	int		n_return;

	aver = fun_aver_b_for_v2(b, len, &n);
	n_return = n;
	while (n)
	{
		if ((int)b[0] > aver)
		{
			PA;
			n--;
		}
		else
			RB;
	}
	return (len[1]);
}
