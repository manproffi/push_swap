/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 20:29:45 by sprotsen          #+#    #+#             */
/*   Updated: 2017/02/20 20:31:41 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printhead.h"

void	pr_hex(uintmax_t a, int i, int *symb, char *row)
{
	uintmax_t	num;
	int			n;

	i++;
	num = a / 16;
	n = a % 16;
	if (num > 0)
		pr_hex(num, i, symb, row);
	if (n > 9)
		row[i] = (*symb + n - 10);
	else
		row[i] = (n + '0');
}

char	*write_row(void *point, int *symb, int *flag)
{
	char	*row;
	int		i;

	i = -1;
	row = ft_strnew(25);
	flag[7] == 0 ? pr_hex((unsigned int)point, i, symb, row) : 0;
	flag[7] == 1 ? pr_hex((unsigned char)point, i, symb, row) : 0;
	flag[7] == 2 ? pr_hex((unsigned short)point, i, symb, row) : 0;
	flag[7] == 3 ? pr_hex((unsigned long)point, i, symb, row) : 0;
	flag[7] == 4 ? pr_hex((unsigned long long)point, i, symb, row) : 0;
	flag[7] == 5 ? pr_hex((long long int)point, i, symb, row) : 0;
	flag[7] == 6 ? pr_hex((size_t)point, i, symb, row) : 0;
	return (row);
}
