/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 13:23:52 by sprotsen          #+#    #+#             */
/*   Updated: 2016/12/10 14:02:38 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*s_without_symbol(void)
{
	char	*str;

	str = (char*)malloc(sizeof(char) * 1);
	str[0] = '\0';
	return (str);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	size_t	l;
	size_t	i;
	size_t	k;

	if (!s)
		return (NULL);
	l = ft_strlen(s);
	i = 0;
	k = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[l - 1 - k] == ' ' || s[l - 1 - k] == '\n' || s[l - 1 - k] == '\t')
		k++;
	if (l == i && i == k)
		return (s_without_symbol());
	str = (char*)malloc(sizeof(char) * (l - i - k) + 1);
	if (!str)
		return (NULL);
	l = l - k;
	k = i;
	while (i < l)
		*str++ = s[i++];
	*str = '\0';
	return (str - (i - k));
}
