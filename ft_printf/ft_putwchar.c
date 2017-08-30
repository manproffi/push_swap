/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puwchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 19:17:34 by sprotsen          #+#    #+#             */
/*   Updated: 2017/02/22 20:43:13 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printhead.h"

void	ft_put2wchar(wchar_t s, size_t *res)
{
	unsigned char c;

	c = 0xF0 | (s >> 18);
	write(1, &c, 1);
	c = 0x80 | ((s >> 12) & 0x3F);
	write(1, &c, 1);
	c = 0x80 | ((s >> 6) & 0x3F);
	write(1, &c, 1);
	c = 0x80 | (s & 0x3F);
	write(1, &c, 1);
	*res += 4;
}

void	ft_putwchar(wchar_t s, size_t *res)
{
	unsigned char c;

	if (s <= 0x7F && s != '\0')
	{
		write(1, &s, 1);
		*res += 1;
	}
	else if (s <= 0x7FF && s != '\0')
	{
		(c = 0xC0 | (s >> 6)) ? write(1, &c, 1) : 0;
		(c = 0x80 | (s & 0x3F)) ? write(1, &c, 1) : 0;
		*res += 2;
	}
	else if (s <= 0xFFFF && s != '\0')
	{
		c = 0xE0 | (s >> 12);
		write(1, &c, 1);
		c = 0x80 | ((s >> 6) & 0x3F);
		write(1, &c, 1);
		c = 0x80 | (s & 0x3F);
		write(1, &c, 1);
		*res += 3;
	}
	else if (s <= 0x10FFFF && s != '\0')
		ft_put2wchar(s, res);
}
