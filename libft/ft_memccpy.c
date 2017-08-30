/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 19:07:18 by sprotsen          #+#    #+#             */
/*   Updated: 2016/11/27 11:27:44 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*pdst;
	unsigned char	*psrc;
	size_t			i;

	i = 0;
	pdst = (unsigned char*)dst;
	psrc = (unsigned char*)src;
	while (i < n)
	{
		if (psrc[i] == (unsigned char)c)
		{
			pdst[i] = psrc[i];
			return (dst + i + 1);
		}
		pdst[i] = psrc[i];
		i++;
	}
	return (NULL);
}
