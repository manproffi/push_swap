/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_address.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 21:02:53 by sprotsen          #+#    #+#             */
/*   Updated: 2017/02/22 19:11:26 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printhead.h"

void	for_includ(size_t *res)
{
	pr_space_null(1, res, '0');
	pr_space_null(1, res, 120);
}

void	for_address_next_3(char *r, size_t *res, size_t len)
{
	if (r[0] != '\0')
	{
		PSN(1, res, '0');
		PSN(1, res, 120);
		pr_row(len, res, r);
	}
	ft_strdel(&r);
}

void	for_address_next_2(char *r, size_t *res, int *fl, size_t len)
{
	if (fl[6] == 0 && fl[3] == 0 && fl[4] == 1 && fl[5] > 0)
	{
		fl[6] = fl[5];
		fl[5] = 0;
		fl[4] = 0;
		PSN(1, res, '0');
		PSN(1, res, 120);
		(len == 1 && r[0] == 48) ? PSN((fl[6] - len), res, '0')
			: PSN((fl[6] - len - 2), res, '0');
		pr_row(len, res, r);
		ft_strdel(&r);
		return ;
	}
	else if (fl[6] > fl[5])
	{
		PSN(1, res, '0');
		PSN(1, res, 120);
		(len == 1 && r[0] == 48) ? PSN((fl[6] - len), res, '0')
			: PSN((fl[6] - len), res, '0');
		pr_row(len, res, r);
		ft_strdel(&r);
		return ;
	}
	for_address_next_3(r, res, len);
}

void	for_address_next(char *r, size_t *res, int *f, size_t len)
{
	if (f[5] > f[6] && f[3] == 0)
	{
		f[4] == 1 ? for_includ(res) : 0;
		if (f[4] == 1)
			PSN((f[6] > (int)len ? f[5] - f[6] - 2 : f[5] - len - 2), res, '0');
		else
			PSN((f[6] > (int)len ? f[5] - f[6] - 2 : f[5] - len - 2), res, ' ');
		f[4] != 1 ? for_includ(res) : 0;
		PSN((f[6] - len), res, '0');
		pr_row(len, res, r);
		ft_strdel(&r);
		return ;
	}
	if (f[5] > f[6] && f[3] == 1)
	{
		for_includ(res);
		pr_space_null((f[6] - len - 2), res, '0');
		pr_row(len, res, r);
		pr_space_null(((f[6] > (int)len) ? (f[5] - f[6] - 2)
			: (f[5] - len - 2)), res, ' ');
		ft_strdel(&r);
		return ;
	}
	for_address_next_2(r, res, f, len);
}

void	for_address(void *point, size_t *res, int *fl)
{
	char		*r;
	size_t		len;
	int			s;
	int			i;

	i = -1;
	s = 97;
	r = ft_strnew(20);
	pr_hex((uintmax_t)point, i, &s, r);
	len = ft_strlen(r);
	fl[6] > 0 ? fl[4] = 0 : 0;
	(len == 1 && r[0] == 48) ? fl[1] = 0 : 0;
	(fl[6] < 0 && len == 1 && r[0] == 48) ? PSN(fl[5] - 2, res, ' ') : 0;
	(fl[6] < 0 && len == 1 && r[0] == 48) ? free(r) : 0;
	if (fl[6] < 0 && len == 1 && r[0] == 48)
	{
		write(1, "0x", 2);
		*res += 2;
		return ;
	}
	for_address_next(r, res, fl, len);
}
