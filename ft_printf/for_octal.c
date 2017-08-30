/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_octal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 20:35:27 by sprotsen          #+#    #+#             */
/*   Updated: 2017/02/22 19:40:31 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printhead.h"

void	pr_octal(uintmax_t a, int i, char *row)
{
	int			n;
	uintmax_t	num;

	num = a / 8;
	n = a % 8;
	i++;
	if (num > 0)
		pr_octal(num, i, row);
	row[i] = (n + '0');
}

char	*write_row_octal(void *point, int *flag)
{
	char	*row;
	int		i;
	int		k;

	i = -1;
	k = 0;
	row = ft_strnew(25);
	flag[7] == 0 ? pr_octal((unsigned int)point, i, row) : 0;
	flag[7] == 1 ? pr_octal((unsigned char)point, i, row) : 0;
	flag[7] == 2 ? pr_octal((unsigned short)point, i, row) : 0;
	flag[7] == 3 ? pr_octal((unsigned long)point, i, row) : 0;
	flag[7] == 4 ? pr_octal((unsigned long long)point, i, row) : 0;
	flag[7] == 5 ? pr_octal((long long int)point, i, row) : 0;
	flag[7] == 6 ? pr_octal((size_t)point, i, row) : 0;
	if (flag[1] == 1)
	{
		if ((row[0] != 48 && row[1] != 48) || ft_strlen(row) > 1)
		{
			while (row[k] > 47 && row[k] < 58)
				k++;
			row[k] = 48;
		}
	}
	return (row);
}

void	for_octal_next(size_t *res, int *fl, size_t len, char *oct_row)
{
	int		pr;

	pr = 0;
	if ((fl[5] > fl[6]) && fl[3] == 1)
	{
		pr = fl[6] - (int)len;
		pr_space_null(pr, res, '0');
		pr_row(len, res, oct_row);
		if (fl[6] > (int)len)
			pr = fl[5] - fl[6];
		else
			pr = fl[5] - len;
		pr_space_null(pr, res, ' ');
	}
	else if (fl[6] > fl[5])
	{
		pr = fl[6] - (int)len;
		pr_space_null(pr, res, '0');
		pr_row(len, res, oct_row);
	}
	else
		pr_row(len, res, oct_row);
	ft_strdel(&oct_row);
}

void	for_octal_part(int *fl, size_t *res, char *oct_row, size_t *len)
{
	int		pr;

	pr = 0;
	if (fl[6] > (int)*len)
		pr = fl[5] - fl[6];
	else
		pr = fl[5] - *len;
	if (fl[4] == 1)
		pr_space_null(pr, res, '0');
	else
		pr_space_null(pr, res, ' ');
	pr = fl[6] - (int)*len;
	pr_space_null(pr, res, '0');
	pr_row(*len, res, oct_row);
	ft_strclr(oct_row);
	clear_flag(fl);
	*len = 0;
}

void	for_octal(void *point, size_t *res, int *fl)
{
	char		*oct_row;
	size_t		len;

	oct_row = write_row_octal(point, fl);
	fl[6] > 0 ? fl[4] = 0 : 0;
	if (fl[6] == 0 && fl[3] == 0 && fl[4] == 1)
	{
		fl[6] = fl[5] * fl[4];
		fl[5] = 0;
		fl[4] = 0;
	}
	len = ft_strlen(oct_row);
	if (fl[6] < 0 && len == 1 && oct_row[0] == 48 && oct_row[1] == '\0')
	{
		pr_space_null(fl[5], res, ' ');
		(fl[1] == 1) ? pr_space_null(1, res, '0') : 0;
		(fl[1] == 1) ? ft_strdel(&oct_row) : 0;
		return ;
	}
	if ((fl[5] >= fl[6]) && fl[3] == 0 && fl[5] != 0)
		for_octal_part(fl, res, oct_row, &len);
	for_octal_next(res, fl, len, oct_row);
}
