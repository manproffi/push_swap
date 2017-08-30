/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 10:51:34 by sprotsen          #+#    #+#             */
/*   Updated: 2016/11/27 11:31:52 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
