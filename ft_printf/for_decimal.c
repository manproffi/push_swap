/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_decimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 19:26:23 by sprotsen          #+#    #+#             */
/*   Updated: 2017/02/20 19:42:59 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printhead.h"

char	*write_row_decimal(void *point, int *fl)
{
	char	*row;
	int		i;

	i = -1;
	row = ft_strnew(30);
	fl[7] == 0 ? pr_decimal((int)point, i, row, fl) : 0;
	fl[7] == 1 ? pr_decimal((char)point, i, row, fl) : 0;
	fl[7] == 2 ? pr_decimal((short)point, i, row, fl) : 0;
	fl[7] == 3 ? pr_decimal((long)point, i, row, fl) : 0;
	fl[7] == 4 ? pr_decimal((long long)point, i, row, fl) : 0;
	fl[7] == 5 ? pr_decimal((intmax_t)point, i, row, fl) : 0;
	fl[7] == 6 ? pr_decimal((size_t)point, i, row, fl) : 0;
	return (row);
}

void	print_part_flag(int *fl, size_t *res, int k)
{
	if (k == 0)
	{
		fl[0] == 1 ? PSN(1, res, ' ') : 0;
		fl[1] == 2 ? PSN(1, res, '-') : 0;
		fl[2] == 1 ? PSN(1, res, '+') : 0;
	}
	else if (k == 1)
	{
		if (fl[6] < 0 && fl[2] == 1)
		{
			PSN(fl[5] - 1, res, ' ');
			PSN(1, res, '+');
		}
		(fl[6] < 0 && fl[2] != 1) ? PSN(fl[5], res, ' ') : 0;
	}
}

void	for_decimal_next(size_t *res, int *fl, char *row)
{
	size_t	len;

	len = ft_strlen(row);
	if (fl[5] > fl[6] && fl[3] == 1)
	{
		print_part_flag(fl, res, 0);
		pr_space_null((fl[6] - len), res, '0');
		pr_row(len, res, row);
		if (fl[6] > (int)len)
			PSN((fl[5] - fl[6] - (SYMB(fl[2], fl[0], fl[1]))), res, ' ');
		else
			PSN(fl[5] - (int)len - (SYMB(fl[2], fl[0], fl[1])), res, ' ');
	}
	else if (fl[6] >= fl[5])
	{
		print_part_flag(fl, res, 0);
		pr_space_null((fl[6] - len), res, '0');
		pr_row(len, res, row);
	}
	else
	{
		print_part_flag(fl, res, 0);
		pr_row(len, res, row);
	}
	ft_strdel(&row);
}

void	part_fun_decimal(int *fl, char *row, size_t *res, size_t len)
{
	int		pr;

	if (fl[6] > (int)len)
		pr = fl[5] - fl[6] - (SYMB(fl[2], fl[0], fl[1]));
	else
		pr = fl[5] - (int)len - (SYMB(fl[2], fl[0], fl[1]));
	fl[4] == 1 ? PSN(pr, res, '0') : PSN(pr, res, ' ');
	print_part_flag(fl, res, 0);
	PSN((fl[6] - len), res, '0');
	pr_row(len, res, row);
	ft_strclr(row);
	clear_flag(fl);
}

void	for_decimal(void *point, size_t *res, int *fl)
{
	char	*row;
	size_t	len;

	row = write_row_decimal(point, fl);
	len = ft_strlen(row);
	(fl[6] > 0 || fl[6] < 0) ? fl[4] = 0 : 0;
	if (fl[6] == 0 && fl[3] == 0 && fl[4] == 1)
	{
		fl[6] = fl[5] - (SYMB(fl[2], fl[0], fl[1]));
		fl[5] = 0;
		fl[4] = 0;
	}
	fl[2] == 1 ? fl[0] = 0 : 0;
	if (fl[6] < 0 && len == 1 && row[0] == 48)
	{
		PPF(fl, res, 1);
		free(row);
		return ;
	}
	if (fl[6] < 0 && len == 1 && row[0] == 48)
		return ;
	if (fl[5] > fl[6] && fl[3] == 0)
		part_fun_decimal(fl, row, res, len);
	for_decimal_next(res, fl, row);
}
