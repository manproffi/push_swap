/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 15:47:47 by sprotsen          #+#    #+#             */
/*   Updated: 2016/12/10 13:03:49 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		words_num(char *str, char c)
{
	int		result;
	int		i;

	i = 0;
	result = 0;
	while (str[i] == c)
		i++;
	while (str[i] != '\0')
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			result++;
		i++;
	}
	return (result);
}

static int		n_symbol(char *str, int *k, char c)
{
	int		count;
	int		a;

	count = k[1];
	a = 0;
	while (str[count] == c)
		count++;
	while (str[count] != c && str[count] != '\0')
	{
		count++;
		a++;
	}
	k[1] = count;
	return (a);
}

static char		**prisvoenie(char *str, int *k, char **mass, char c)
{
	int		count;
	int		a;

	count = k[1];
	a = 0;
	while (str[count] == c)
		count++;
	while (str[count] != c && str[count] != '\0')
	{
		mass[k[2]][a] = str[count];
		count++;
		a++;
	}
	mass[k[2]][a] = '\0';
	k[1] = count;
	return (mass);
}

char			**ft_strsplit(char const *s, char c)
{
	int		a[3];
	char	**mass;

	if (!s || !c)
		return (NULL);
	a[0] = words_num((char*)s, c);
	a[1] = 0;
	a[2] = 0;
	mass = (char**)malloc(sizeof(char*) * (a[0] + 1));
	if (!mass)
		return (NULL);
	while (a[2] < a[0])
	{
		mass[a[2]++] = (char*)malloc(sizeof(char) * n_symbol((char*)s, a, c));
		if (!mass)
			return (NULL);
	}
	mass[a[2]] = NULL;
	a[1] = 0;
	a[2] = -1;
	while (++a[2] < a[0])
		prisvoenie((char*)s, a, mass, c);
	return (mass);
}
