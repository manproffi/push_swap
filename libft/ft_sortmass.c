/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortmass.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 18:32:03 by sprotsen          #+#    #+#             */
/*   Updated: 2016/12/11 12:56:25 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sortmass(int *a, int length)
{
	int		i;
	int		j;
	int		res;

	i = 0;
	while (i < length - 1)
	{
		j = 0;
		while (j < length - i - 1)
		{
			if (a[j] > a[j + 1])
			{
				res = a[j];
				a[j] = a[j + 1];
				a[j + 1] = res;
			}
			j++;
		}
		i++;
	}
}
