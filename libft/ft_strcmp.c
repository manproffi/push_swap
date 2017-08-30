/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:59:47 by sprotsen          #+#    #+#             */
/*   Updated: 2017/03/05 17:37:39 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	if (s1 && s2)
	{
		while (*s1 && (*s1 == *s2))
		{
			s1++;
			s2++;
		}
		return (*(const unsigned char*)s1 - *(const unsigned char*)s2);
	}
	return (1);
}
