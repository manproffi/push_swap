/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_fun_for_stack_a3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 20:33:08 by sprotsen          #+#    #+#             */
/*   Updated: 2017/03/29 20:33:13 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_head.h"

void	division_stack_b_part1(size_t *a, size_t *b, int *len, int *n)
{
	while (n[2] && (int)b[len[1] - 1] >= n[3])
	{
		if ((int)b[len[1] - 1] >= n[4])
		{
			RRB;
			PA;
			n[2] -= 1;
		}
		else
			RRB;
	}
}

int		division_stack_b(size_t *a, size_t *b, int *len, int number)
{
	int		n[5];

	n[0] = 0;
	n[1] = 0;
	n[2] = 0;
	n[4] = find_aver_for_b(b, number, n, len);
	if (n[2] < n[1])
	{
		division_stack_b_part1(a, b, len, n);
		division_stack_b_part2(a, b, len, n);
	}
	else if (n[1] <= n[2])
	{
		division_stack_b_part2(a, b, len, n);
		division_stack_b_part1(a, b, len, n);
	}
	return (number - n[0]);
}

int		fun_aver_v1(size_t *a, int *len, int *n)
{
	int		row[len[0]];
	int		aver;
	int		i;

	i = -1;
	aver = 0;
	while (++i < len[0])
		row[i] = a[i];
	ft_sortmass(row, len[0]);
	aver = row[len[0] / 2 - 1];
	*n = aver - row[0] + 1;
	return (aver);
}

int		division_stack_a_v1(size_t *a, size_t *b, int *len)
{
	int		aver;
	int		n;
	int		n_return;

	n = 0;
	aver = fun_aver_v1(a, len, &n);
	n_return = n;
	while (n)
	{
		if ((int)a[0] <= aver)
		{
			PB;
			n--;
		}
		else
			RA;
	}
	return (n_return);
}
