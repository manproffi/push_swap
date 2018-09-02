/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_fun_for_stack_a2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 20:32:51 by sprotsen          #+#    #+#             */
/*   Updated: 2017/03/29 20:32:54 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_head.h"

int		find_sort(size_t *a, int *len)
{
	int		i;
	int		answer;

	i = len[0];
	answer = len[0] - 1;
	while (--i)
		if (a[i] - 1 == a[i - 1])
			answer = i - 1;
		else
			break ;
	return (answer);
}

int		fun_aver_a_v2_next_2(size_t *a, int *n, int *len)
{
	int		i;
	int		row[len[0]];
	int		aver;

	i = -1;
	while (++i < len[0])
		row[i] = a[i];
	ft_sortmass(row, len[0]);
	aver = row[n[7] / 2 - 1];
	n[1] = 0;
	n[2] = 0;
	i = -1;
	while ((int)a[++i] != n[4])
		if ((int)a[i] <= aver)
			n[1]++;
	while (n[5] < len[0])
	{
		if ((int)a[n[5]] <= aver)
			n[2]++;
		n[5] += 1;
	}
	n[0] = n[1] + n[2];
	return (aver);
}

int		fun_aver_a_v2_next(size_t *a, int *n, int *len)
{
	int		i;

	i = -1;
	n[3] = a[0];
	while (++i < len[0])
		if (n[3] < (int)a[i])
		{
			n[3] = (int)a[i];
			n[5] = i;
		}
	i = n[5];
	while ((int)a[i] - 1 == (int)a[i - 1])
		i--;
	n[4] = a[i];
	n[6] = i;
	n[7] = len[0] - 1 - n[5] + n[6];
	if (n[7] == 0)
		return (0);
	return (fun_aver_a_v2_next_2(a, n, len));
}

void	division_stack_a_v2_part2(size_t *a, size_t *b, int *len, int *n)
{
	while (n[1] > 0)
	{
		if ((int)a[0] <= n[8])
		{
			PB;
			n[1] -= 1;
		}
		else
			RA;
	}
}

void	division_stack_a_v2_part1(size_t *a, size_t *b, int *len, int *n)
{
	while (n[2] > 0)
	{
		if ((int)a[len[0] - 1] <= n[8])
		{
			RRA;
			PB;
			n[2] -= 1;
		}
		else
			RRA;
	}
}
