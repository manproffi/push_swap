/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_u.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 21:41:08 by sprotsen          #+#    #+#             */
/*   Updated: 2017/02/22 20:18:21 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printhead.h"

void	pr_u_decimal(uintmax_t n, int i, char *row, int *fl)
{
	int			k;
	intmax_t	num;

	num = n / 10;
	k = n % 10;
	i++;
	if (n < 10)
	{
		row[i] = (k + '0');
		return ;
	}
	pr_u_decimal(num, i, row, fl);
	row[i] = (k + '0');
}

char	*write_row_u(void *point, int *fl)
{
	char	*row;
	int		i;

	i = -1;
	row = ft_strnew(30);
	fl[7] == 0 ? pr_u_decimal((unsigned int)point, i, row, fl) : 0;
	fl[7] == 1 ? pr_u_decimal((unsigned char)point, i, row, fl) : 0;
	fl[7] == 2 ? pr_u_decimal((unsigned short)point, i, row, fl) : 0;
	fl[7] == 3 ? pr_u_decimal((unsigned long)point, i, row, fl) : 0;
	fl[7] == 4 ? pr_u_decimal((unsigned long long)point, i, row, fl) : 0;
	fl[7] == 5 ? pr_u_decimal((uintmax_t)point, i, row, fl) : 0;
	fl[7] == 6 ? pr_u_decimal((size_t)point, i, row, fl) : 0;
	return (row);
}

void	for_u_decimal_next(size_t *res, int *fl, char *row)
{
	size_t	len;
	int		pr;

	len = ft_strlen(row);
	if (fl[5] > fl[6] && fl[3] == 1)
	{
		pr_space_null((fl[6] - len), res, '0');
		pr_row(len, res, row);
		if (fl[6] > (int)len)
			(pr = fl[5] - fl[6] - (SYMB(fl[2], fl[0], fl[1])));
		else
			(pr = fl[5] - (int)len);
		pr_space_null(pr, res, ' ');
	}
	else if (fl[6] >= fl[5])
	{
		pr_space_null((fl[6] - len), res, '0');
		pr_row(len, res, row);
	}
	else
		pr_row(len, res, row);
	ft_strdel(&row);
}

void	for_u_decimal_part(int *fl, size_t *res, char *row, size_t len)
{
	int		pr;

	pr = 0;
	if (fl[6] > (int)len)
		(pr = fl[5] - fl[6] - (SYMB(fl[2], fl[0], fl[1])));
	else
		(pr = fl[5] - (int)len);
	fl[4] == 1 ? PSN(pr, res, '0') : PSN(pr, res, ' ');
	pr = fl[6] - len;
	PSN(pr, res, '0');
	pr_row(len, res, row);
	ft_strclr(row);
	clear_flag(fl);
}

void	for_u_decimal(void *point, size_t *res, int *fl)
{
	char	*row;
	size_t	len;

	row = write_row_u(point, fl);
	len = ft_strlen(row);
	fl[6] > 0 ? fl[4] = 0 : 0;
	if (fl[6] == 0 && fl[3] == 0 && fl[4] == 1)
	{
		fl[6] = fl[5] - (SYMB(fl[2], fl[0], fl[1]));
		fl[5] = 0;
		fl[4] = 0;
	}
	fl[2] == 1 ? fl[0] = 0 : 0;
	(fl[6] < 0 && len == 1 && row[0] == 48) ? (free(row)) : 0;
	if (fl[6] < 0 && len == 1 && row[0] == 48)
	{
		PSN(fl[5], res, ' ');
		return ;
	}
	if (fl[5] > fl[6] && fl[3] == 0)
		for_u_decimal_part(fl, res, row, len);
	for_u_decimal_next(res, fl, row);
}
