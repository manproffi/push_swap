/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 19:20:47 by sprotsen          #+#    #+#             */
/*   Updated: 2017/02/20 19:32:05 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printhead.h"

void	pr_decimal(intmax_t n, int i, char *row, int *fl)
{
	intmax_t	num;
	int			k;

	num = n / 10;
	k = n % 10;
	i++;
	if (n < 0)
	{
		fl[1] = 2;
		fl[0] = 0;
		fl[2] = 0;
	}
	if (n > -10 && n < 10)
	{
		k < 0 ? k = -k : 0;
		row[i] = (k + '0');
		return ;
	}
	pr_decimal(num, i, row, fl);
	k < 0 ? k = -k : 0;
	row[i] = (k + '0');
}
