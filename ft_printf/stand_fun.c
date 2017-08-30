/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stand_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 20:12:02 by sprotsen          #+#    #+#             */
/*   Updated: 2017/02/19 20:12:04 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printhead.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char const *s)
{
	if (s)
	{
		while (*s)
			ft_putchar(*s++);
	}
}

int		ft_atoi(const char *str)
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

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	if (s == NULL)
		return (0);
	while (*s++ != '\0')
		count++;
	return (count);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = n * (-1);
	}
	if (n < 10)
	{
		ft_putchar(n + '0');
		return ;
	}
	ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}
