/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 18:21:51 by sprotsen          #+#    #+#             */
/*   Updated: 2016/12/11 12:50:20 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *begin_list)
{
	int		count;
	t_list	*list;

	count = 0;
	list = begin_list;
	if (list)
	{
		while (list)
		{
			count++;
			list = list->next;
		}
		return (count);
	}
	else
		return (0);
}
