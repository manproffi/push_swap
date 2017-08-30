/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 13:21:49 by sprotsen          #+#    #+#             */
/*   Updated: 2016/11/26 17:16:44 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*a_src;
	unsigned char	*b_dst;

	a_src = (unsigned char*)src;
	b_dst = (unsigned char*)dst;
	if (src > dst)
		while (len--)
			*b_dst++ = *a_src++;
	else
		while (len--)
			b_dst[len] = a_src[len];
	return (dst);
}
