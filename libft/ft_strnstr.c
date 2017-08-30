/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:55:58 by sprotsen          #+#    #+#             */
/*   Updated: 2016/12/10 13:03:00 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	n;
	size_t	k;
	size_t	lit_len;

	i = -1;
	n = 0;
	lit_len = ft_strlen(little);
	if (lit_len == 0)
		return ((char*)big);
	while (++i <= len && big[i] != '\0')
		if (big[i] == little[0])
		{
			k = 0;
			while (big[i + k] == little[k] && little[k] != '\0'
					&& (i + k) < len)
			{
				n++;
				k++;
			}
			if (k == lit_len)
				return ((char*)big + i);
		}
	return (NULL);
}
