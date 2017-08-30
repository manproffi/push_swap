/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_wchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 21:08:48 by sprotsen          #+#    #+#             */
/*   Updated: 2017/02/22 20:23:07 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printhead.h"

int		ft_sizeof_wchar(wchar_t s)
{
	int		i;

	i = 0;
	if (s <= 0x7F)
		i += 1;
	else if (s <= 0x7FF)
		i += 2;
	else if (s <= 0xFFFF)
		i += 3;
	else if (s <= 0x10FFFF)
		i += 4;
	return (i);
}

void	pr_symb(wchar_t *str, int *fl, size_t *res, int i)
{
	size_t		k;

	k = *res;
	while (*str)
	{
		if (fl[6] > 0 && (int)(*res - k) >= fl[6])
			break ;
		ft_putwchar(*str, res);
		str++;
		if (fl[6] > 0 && (int)((*res - k) + ft_sizeof_wchar(*str)) > fl[6])
			break ;
	}
	if (i)
		pr_space_null(fl[5] - (*res - k), res, ' ');
}

int		find_i(wchar_t *str, int *fl)
{
	wchar_t	*row;
	int		i;

	i = 0;
	row = str;
	while ((int)i <= fl[6])
	{
		i += ft_sizeof_wchar(*row);
		row++;
	}
	row--;
	i -= ft_sizeof_wchar(*row);
	return (i);
}

void	for_wchar_next(wchar_t *str, size_t *res, int *fl, size_t len)
{
	int		pr;

	if (fl[5] > 0 && fl[3] == 0)
	{
		pr = fl[5] - (((fl[6] < (int)len) && fl[6] != 0) ? find_i(str, fl)
				: (int)len);
		fl[4] == 1 ? PSN(pr, res, '0') : PSN(pr, res, ' ');
		pr_symb(str, fl, res, 0);
	}
	else if ((fl[5] > (int)len && fl[3] == 1))
	{
		pr_symb(str, fl, res, 0);
		pr = fl[5] - (((fl[6] < (int)len) && fl[6] != 0) ? find_i(str, fl)
				: (int)len);
		fl[4] == 1 ? pr_space_null(pr, res, '0') : pr_space_null(pr, res, ' ');
	}
	else
		pr_symb(str, fl, res, 1);
}

void	for_wchar(wchar_t *str, size_t *res, int *fl)
{
	size_t		len;
	wchar_t		*row;

	len = 0;
	row = str;
	if ((char*)str == NULL)
	{
		pr_null(res, fl);
		return ;
	}
	if (fl[6] < 0)
	{
		fl[4] == 1 ? PSN(fl[5], res, '0') : PSN(fl[5], res, ' ');
		return ;
	}
	while (*row)
	{
		len += ft_sizeof_wchar(*row);
		row++;
	}
	for_wchar_next(str, res, fl, len);
}
