/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 17:57:38 by sprotsen          #+#    #+#             */
/*   Updated: 2016/12/05 18:54:20 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*calculate(int size, int n, char flag)
{
	char	*str;

	if (flag)
		size++;
	str = (char*)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	str[size--] = '\0';
	while (n > 0)
	{
		str[size--] = n % 10 + '0';
		n = n / 10;
	}
	if (flag)
		str[size] = '-';
	return (str);
}

static char		*minimal(int n)
{
	char	*str;
	int		size;

	size = 11;
	str = (char*)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	str[size--] = '\0';
	while (n < 0)
	{
		str[size] = (n % 10) * -1 + '0';
		n = n / 10;
		size--;
	}
	str[size] = '-';
	return (str);
}

static char		*nul(int n)
{
	char	*str;

	str = (char*)malloc(sizeof(char) * 2);
	if (!str)
		return (NULL);
	str[0] = n + '0';
	str[1] = '\0';
	return (str);
}

char			*ft_itoa(int n)
{
	int		num;
	int		size;
	int		flag;
	char	*str;

	num = n;
	size = 0;
	flag = 0;
	if (n == 0)
		return (nul(n));
	if (n == -2147483648)
		return (minimal(n));
	if (n < 0)
	{
		n = n * -1;
		flag = 1;
	}
	while (num > 0 || num < 0)
	{
		size++;
		num = num / 10;
	}
	str = calculate(size, n, flag);
	return (str);
}
