/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 20:12:41 by sprotsen          #+#    #+#             */
/*   Updated: 2016/11/30 21:50:25 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
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
	while (big[++i])
		if (big[i] == little[0])
		{
			k = 0;
			while (big[i + k] == little[k] && little[k] != '\0')
			{
				n++;
				k++;
			}
			if (k == lit_len)
				return ((char*)big + i);
		}
	return (NULL);
}
