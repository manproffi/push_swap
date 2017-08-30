/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ulli.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 17:33:05 by sprotsen          #+#    #+#             */
/*   Updated: 2017/03/05 17:35:37 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoi_ulli(const char *str)
{
	int					flag;
	int					i;
	unsigned long long	result;

	flag = 1;
	i = 0;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		flag = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + (str[i++] - 48);
		if (result > 9223372036854775807 && flag == 1)
			return (-1);
		else if (result > 9223372036854775807 && flag == -1)
			return (0);
	}
	return (result * flag);
}
