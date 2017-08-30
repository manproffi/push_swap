/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 18:38:23 by sprotsen          #+#    #+#             */
/*   Updated: 2017/02/22 20:26:30 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printhead.h"

void	for_fl3(int *flag, char *str, size_t *i)
{
	int		k;

	k = 0;
	if (str[*i] == 'h' && flag[7] < 1)
	{
		while (str[*i + 1] == ' ')
			*i += 1;
		if (str[*i + 1] == 'h')
			fun_hh_ll(str, flag, i, 1);
	}
	else
		k++;
	(str[*i] == 'l' && str[*i + 1] == 'l' && flag[7] < 4) ?
		fun_hh_ll(str, flag, i, 4) : k++;
	(str[*i] == 'h' && flag[7] < 2) ? (fun_any(str, flag, i, 2)) : k++;
	(str[*i] == 'l' && flag[7] < 3) ? (fun_any(str, flag, i, 3)) : k++;
	(str[*i] == 'j' && flag[7] < 5) ? (fun_any(str, flag, i, 5)) : k++;
	(str[*i] == 'z' && flag[7] < 6) ? (fun_any(str, flag, i, 6)) : k++;
	if (k == 6)
	{
		str[*i] = '*';
		*i += 1;
	}
}

void	for_fl2(int *flag, char *str, size_t *i)
{
	int		a;

	a = 0;
	if (ft_isdigit(str[*i]) && str[*i - 1] != '.')
		field_width(flag, str, i);
	else if (str[*i] == '.')
	{
		if (str[*i + 1] == '0' && str[*i + 2] > 48 && str[*i + 2] < 58)
			*i += 1;
		flag[6] = 0;
		precision(flag, str, i);
	}
}

void	for_fl1(int *flag, char *str, size_t *i)
{
	str[*i] == 32 ? flag[0] = 1 : 0;
	str[*i] == 35 ? flag[1] = 1 : 0;
	str[*i] == 43 ? flag[2] = 1 : 0;
	str[*i] == 45 ? flag[3] = 1 : 0;
	str[*i] == 48 ? flag[4] = 1 : 0;
	str[*i] = '*';
	*i += 1;
}

void	find_all_flags(int *flag, char *str, size_t *i)
{
	while (FL1(str[*i]) || FL2(str[*i]) || FL3(str[*i]))
	{
		(FL1(str[*i]) > 0) ? for_fl1(flag, str, i) : 0;
		(FL2(str[*i]) > 0) ? for_fl2(flag, str, i) : 0;
		(FL3(str[*i]) > 0) ? for_fl3(flag, str, i) : 0;
	}
}

void	pr_simple_symbol(char *str, size_t *result, size_t *i)
{
	while (str[*i] != '\0')
	{
		if (str[*i] == '%' && str[*i + 1] == '%')
		{
			str[*i] = '*';
			*i += 1;
		}
		else if (str[*i] == '%')
		{
			*i += 1;
			break ;
		}
		ft_putchar(str[*i]);
		*i += 1;
		*result += 1;
	}
}
