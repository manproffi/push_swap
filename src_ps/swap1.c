/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 20:52:50 by sprotsen          #+#    #+#             */
/*   Updated: 2017/03/29 20:52:52 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_head.h"

void	rev_rotate_rot(size_t *a, size_t *b, int *len)
{
	int		k;
	int		i;

	i = -1;
	if (len[0] < 2 && len[1] < 2)
		return ;
	if (len[0] > 1)
	{
		k = a[len[0] - 1];
		while (++i < len[0])
			a[len[0] - i] = a[len[0] - i - 1];
		a[0] = k;
	}
	i = -1;
	if (len[1] > 0)
	{
		k = b[len[1] - 1];
		while (++i < len[1])
			b[len[1] - i] = b[len[1] - i - 1];
		b[0] = k;
	}
}
