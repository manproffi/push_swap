/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 15:46:05 by sprotsen          #+#    #+#             */
/*   Updated: 2017/03/10 20:23:36 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_head.h"

void	swap(size_t *row, int len)
{
	int		a;

	if (len < 2)
		return ;
	a = row[0];
	row[0] = row[1];
	row[1] = a;
}

void	push_a(size_t *a, size_t *b, int *len)
{
	int		i;

	i = -1;
	if (len[1] > 0)
	{
		while (++i < len[0])
			a[len[0] - i] = a[len[0] - i - 1];
		len[0] += 1;
		a[0] = b[0];
		i = -1;
		while (++i < len[1])
			b[i] = b[i + 1];
		len[1] -= 1;
	}
}

void	push_b(size_t *a, size_t *b, int *len)
{
	int		i;

	i = -1;
	if (len[0] > 0)
	{
		while (++i < len[1])
			b[len[1] - i] = b[len[1] - i - 1];
		len[1] += 1;
		b[0] = a[0];
		i = -1;
		while (++i < len[0])
			a[i] = a[i + 1];
		len[0] -= 1;
	}
}

void	rotate(size_t *a, int len)
{
	int		k;
	int		i;

	i = -1;
	if (len > 1)
	{
		k = a[0];
		while (++i < len)
			a[i] = a[i + 1];
		a[len - 1] = k;
	}
}

void	rev_rotate(size_t *a, int len)
{
	int		k;
	int		i;

	i = -1;
	if (len > 1)
	{
		k = a[len - 1];
		while (++i < len)
			a[len - i] = a[len - i - 1];
		a[0] = k;
	}
}
