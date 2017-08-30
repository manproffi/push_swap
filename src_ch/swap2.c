/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 15:46:05 by sprotsen          #+#    #+#             */
/*   Updated: 2017/03/10 20:23:36 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_head.h"

void	swap(int *row, int len)
{
	int		a;

	if (len < 2)
		return ;
	a = row[0];
	row[0] = row[1];
	row[1] = a;
}

void	push_a(int *a, int *b, int *len_a, int *len_b)
{
	int		i;

	i = -1;
	if (*len_b > 0)
	{
		while (++i < *len_a)
			a[*len_a - i] = a[*len_a - i - 1];
		*len_a += 1;
		a[0] = b[0];
		i = -1;
		while (++i < *len_b)
			b[i] = b[i + 1];
		*len_b -= 1;
	}
}

void	push_b(int *a, int *b, int *len_a, int *len_b)
{
	int		i;

	i = -1;
	if (*len_a > 0)
	{
		while (++i < *len_b)
			b[*len_b - i] = b[*len_b - i - 1];
		*len_b += 1;
		b[0] = a[0];
		i = -1;
		while (++i < *len_a)
			a[i] = a[i + 1];
		*len_a -= 1;
	}
}

void	rotate(int *a, int *len)
{
	int		k;
	int		i;

	i = -1;
	if (*len > 1)
	{
		k = a[0];
		while (++i < *len)
			a[i] = a[i + 1];
		a[*len - 1] = k;
	}
}

void	rev_rotate(int *a, int *len)
{
	int		k;
	int		i;

	i = -1;
	if (*len > 1)
	{
		k = a[*len - 1];
		while (++i < *len)
			a[*len - i] = a[*len - i - 1];
		a[0] = k;
	}
}
