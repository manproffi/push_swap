/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 18:48:48 by sprotsen          #+#    #+#             */
/*   Updated: 2017/02/20 20:29:13 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printhead.h"

void	for_hex_next_part(size_t *res, int *fl, int s, char *row)
{
	size_t	len;

	len = ft_strlen(row);
	if (fl[1] == 1)
	{
		PSN(1, res, '0');
		PSN(1, res, (s == 97 ? 120 : 88));
	}
	pr_space_null((fl[6] - len), res, '0');
	pr_row(len, res, row);
	if (fl[6] > (int)len)
		pr_space_null((fl[5] - fl[6] - (fl[1] > 0 ? 2 : 0)), res, ' ');
	else
		pr_space_null((fl[5] - len - (fl[1] > 0 ? 2 : 0)), res, ' ');
}

void	for_hex_next(size_t *res, int *fl, int s, char *row)
{
	size_t	len;

	len = ft_strlen(row);
	if (fl[5] > fl[6] && fl[3] == 1)
		for_hex_next_part(res, fl, s, row);
	else if (fl[6] >= fl[5])
	{
		if (fl[1] == 1)
		{
			PSN(1, res, '0');
			PSN(1, res, (s == 97 ? 120 : 88));
		}
		pr_space_null((fl[6] - len), res, '0');
		pr_row(len, res, row);
	}
	else
	{
		if (fl[1] == 1)
		{
			PSN(1, res, '0');
			PSN(1, res, (s == 97 ? 120 : 88));
		}
		pr_row(len, res, row);
	}
	ft_strdel(&row);
}

void	pr_part_hex(char *r, int *fl, int s, size_t *res)
{
	int		pr;
	size_t	len;

	len = ft_strlen(r);
	if (fl[1] == 1)
	{
		PSN(1, res, '0');
		PSN(1, res, (s == 97 ? 120 : 88));
	}
	if (fl[6] > (int)len)
		(pr = fl[5] - fl[6] - (fl[1] > 0 ? 2 : 0));
	else
		(pr = fl[5] - len - (fl[1] > 0 ? 2 : 0));
	fl[4] == 1 ? PSN(pr, res, '0') : PSN(pr, res, ' ');
	PSN((fl[6] - len), res, '0');
	pr_row(len, res, r);
}

void	for_hex_part(char *r, int *fl, int s, size_t *res)
{
	int		pr;
	size_t	len;

	len = ft_strlen(r);
	if (fl[6] > (int)len)
		(pr = fl[5] - fl[6] - (fl[1] > 0 ? 2 : 0));
	else
		(pr = fl[5] - len - (fl[1] > 0 ? 2 : 0));
	fl[4] == 1 ? PSN(pr, res, '0') : PSN(pr, res, ' ');
	if (fl[1] == 1)
	{
		PSN(1, res, '0');
		PSN(1, res, (s == 97 ? 120 : 88));
	}
	PSN((fl[6] - len), res, '0');
	pr_row(len, res, r);
	ft_strclr(r);
	clear_flag(fl);
}

void	for_hex(void *point, size_t *res, int *fl, int s)
{
	char	*r;
	size_t	len;

	r = write_row(point, &s, fl);
	len = ft_strlen(r);
	fl[6] > 0 ? fl[4] = 0 : 0;
	(len == 1 && r[0] == 48) ? fl[1] = 0 : 0;
	(fl[6] < 0 && len == 1 && r[0] == 48) ? PSN(fl[5], res, ' ') : 0;
	(fl[6] < 0 && len == 1 && r[0] == 48) ? free(r) : 0;
	if (fl[6] < 0 && len == 1 && r[0] == 48)
		return ;
	if (fl[6] == 0 && fl[3] == 0 && fl[4] == 1 && fl[5] > 0)
	{
		pr_part_hex(r, fl, s, res);
		ft_strclr(r);
		clear_flag(fl);
	}
	if (fl[5] > fl[6] && fl[3] == 0)
		for_hex_part(r, fl, s, res);
	for_hex_next(res, fl, s, r);
}
