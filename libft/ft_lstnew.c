/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 19:36:58 by sprotsen          #+#    #+#             */
/*   Updated: 2016/12/10 12:56:33 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*list;

	list = (t_list*)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	if (content)
	{
		list->content = malloc(content_size);
		if (!list->content)
			return (NULL);
		list->content_size = content_size;
		ft_memcpy(list->content, content, content_size);
	}
	else
	{
		list->content = NULL;
		list->content_size = 0;
	}
	list->next = NULL;
	return (list);
}
