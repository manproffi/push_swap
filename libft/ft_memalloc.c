/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 14:37:03 by sprotsen          #+#    #+#             */
/*   Updated: 2016/12/03 14:42:59 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*row;

	row = (void*)malloc(sizeof(void) * size);
	if (row == NULL)
		return (NULL);
	while (size--)
		row[size] = 0;
	return (row);
}
