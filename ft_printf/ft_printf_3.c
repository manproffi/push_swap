/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 18:39:06 by sprotsen          #+#    #+#             */
/*   Updated: 2017/02/22 20:28:00 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printhead.h"

int		n_plus_plus(int n)
{
	int		result;

	result = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		result++;
	}
	return (result);
}

void	field_width(int *flag, char *str, size_t *qwe)
{
	size_t		i;
	size_t		a;

	i = *qwe;
	a = *qwe;
	flag[5] = ft_atoi(str + i);
	i += n_plus_plus(flag[5]);
	while (a < i)
		str[a++] = '*';
	*qwe = i;
}

void	fun_hh_ll(char *str, int *flag, size_t *a, size_t k)
{
	flag[7] = k;
	str[*a] = '*';
	str[*a + 1] = '*';
	*a += 2;
}

void	fun_any(char *str, int *flag, size_t *a, size_t k)
{
	flag[7] = k;
	str[*a] = '*';
	*a += 1;
}

void	precision(int *flag, char *str, size_t *a)
{
	size_t		i;

	i = *a + 1;
	if (ft_isdigit(str[i]))
	{
		flag[6] = ft_atoi(str + i);
		i += n_plus_plus(flag[6]);
		flag[6] == 0 ? flag[6] = -1 : flag[6];
	}
	else
		flag[6] == 0 ? flag[6] = -1 : flag[6];
	while (*a < i)
	{
		str[*a] = '*';
		*a += 1;
	}
}
