/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 19:26:37 by sprotsen          #+#    #+#             */
/*   Updated: 2016/12/10 13:00:42 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*a;

	a = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			a = (char*)s;
		s++;
	}
	if (*s == (char)c)
		a = (char*)s;
	return ((char*)a);
}
