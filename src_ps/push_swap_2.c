/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 20:52:04 by sprotsen          #+#    #+#             */
/*   Updated: 2017/03/28 20:52:06 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_head.h"

void	ft_sortmass_two(size_t *a1, size_t *a2, int length)
{
	int			i;
	int			j;
	size_t		res;
	size_t		qwe;

	i = 0;
	while (i < length - 1)
	{
		j = 0;
		while (j < length - i - 1)
		{
			if (a1[j] > a1[j + 1])
			{
				res = a1[j];
				qwe = a2[j];
				a1[j] = a1[j + 1];
				a2[j] = a2[j + 1];
				a1[j + 1] = res;
				a2[j + 1] = qwe;
			}
			j++;
		}
		i++;
	}
}

void	chang_a(int *a, int len)
{
	int			sort[len];
	size_t		index[len];
	size_t		answer[len];
	int			i;
	int			j;

	i = -1;
	while (++i < len)
	{
		sort[i] = a[i];
		index[i] = i + 1;
	}
	ft_sortmass(sort, len);
	i = -1;
	while (++i < len)
	{
		j = -1;
		while (++j < len)
		{
			if (a[i] == sort[j])
				answer[i] = index[j];
		}
	}
	next_fun1(answer, len);
}

void	validation_duplicate_int(int *row, int len)
{
	int		i;
	int		j;

	i = -1;
	while (++i < len - 1)
	{
		j = i;
		while (++j < len)
			if (row[i] == row[j])
				error(0);
	}
}

void	ss_sa(size_t *a, size_t *b, int *len)
{
	if (a[0] > a[1] && b[0] < b[1])
		SS;
	else if (a[0] > a[1])
		SA;
}
