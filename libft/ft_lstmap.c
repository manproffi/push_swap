/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 20:11:25 by sprotsen          #+#    #+#             */
/*   Updated: 2016/12/10 12:56:04 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;

	if (lst && f)
	{
		list = (t_list*)malloc(sizeof(t_list));
		if (!list)
			return (NULL);
		list = f(lst);
		list->next = ft_lstmap(lst->next, f);
		return (list);
	}
	return (NULL);
}
