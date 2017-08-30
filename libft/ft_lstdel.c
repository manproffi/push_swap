/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:05:25 by sprotsen          #+#    #+#             */
/*   Updated: 2016/12/10 12:55:33 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	if (*alst)
	{
		del((*alst)->content, (*alst)->content_size);
		(*alst)->content = NULL;
		if ((*alst)->next)
			ft_lstdel(&(*alst)->next, del);
		free(*alst);
	}
	*alst = NULL;
}
