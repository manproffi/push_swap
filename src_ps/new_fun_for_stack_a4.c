/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_fun_for_stack_a4.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 20:34:56 by sprotsen          #+#    #+#             */
/*   Updated: 2017/03/29 20:34:57 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_head.h"

int		find_aver_for_b(size_t *b, int number, int *n, int *len)
{
	int		row[len[1]];
	int		i;
	int		aver;

	i = -1;
	while (++i < len[1])
		row[i] = b[i];
	ft_sortmass(row, len[1]);
	aver = row[len[1] - number / 2];
	n[0] = len[1] - aver + 1;
	n[3] = len[1] - number + 1;
	i = -1;
	while ((int)b[++i] >= n[3])
		n[1] += 1;
	i = len[1];
	while ((int)b[--i] >= n[3])
		n[2] += 1;
	return (aver);
}

void	division_stack_b_part2(size_t *a, size_t *b, int *len, int *n)
{
	while (n[1] && (int)b[0] >= n[3])
	{
		if ((int)b[0] >= n[4])
		{
			PA;
			n[1] -= 1;
		}
		else
			RB;
	}
}
