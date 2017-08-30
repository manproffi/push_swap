/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_symbol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 20:03:38 by sprotsen          #+#    #+#             */
/*   Updated: 2017/02/13 20:03:39 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printhead.h"

void	for_symbol(void *point, size_t *res, int *flag)
{
	int		k;

	*res += 1;
	k = 0;
	flag[3] == 1 ? flag[4] = 0 : 0;
	flag[6] > 0 ? flag[6] = 0 : 0;
	if (flag[3] == 1)
		ft_putchar((int)point);
	if (flag[6] == -1)
		k = flag[5] - 1;
	else if (flag[5])
		k = flag[5] - 1;
	else if (flag[6] && flag[5])
		k = flag[5] - flag[6] - 1;
	if (flag[5] > 0)
		while (k-- > 0)
		{
			*res += 1;
			flag[4] == 1 ? ft_putchar('0') : ft_putchar(' ');
		}
	if (flag[3] == 0)
		ft_putchar((int)point);
}
