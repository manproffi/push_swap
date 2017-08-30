/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stand_fun_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 20:10:41 by sprotsen          #+#    #+#             */
/*   Updated: 2017/02/19 20:10:44 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printhead.h"

int		ft_isdigit(int c)
{
	unsigned char	n;

	n = (unsigned char)c;
	if (c > 47 && c < 58)
		if (n > 47 && n < 58)
			return (1);
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char		*str;
	size_t		i;

	i = ft_strlen(s1);
	str = (char*)malloc(sizeof(*str) * i + 1);
	if (!str)
		return (NULL);
	while (*s1 != '\0')
	{
		*str = *s1;
		str++;
		s1++;
	}
	*str = '\0';
	return (str - i);
}

char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char*)malloc(sizeof(char) * size + 1);
	if (str == NULL)
		return (NULL);
	str[size++] = '\0';
	while (size--)
		str[size] = '\0';
	return (str);
}

void	ft_strdel(char **as)
{
	if (as != NULL)
	{
		free(*as);
		*as = NULL;
	}
}

void	ft_strclr(char *s)
{
	size_t	len;

	if (s != NULL)
	{
		len = ft_strlen(s);
		while (len--)
			s[len] = '\0';
	}
}
