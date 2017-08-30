/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 12:24:42 by sprotsen          #+#    #+#             */
/*   Updated: 2017/03/10 20:24:09 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_head.h"

void	error(int i)
{
	if (i == 0)
		;
	ft_printf(RED"Error\n");
	exit(0);
}

void	del_list(t_list **list)
{
	if ((*list))
	{
		del_list(&(*list)->next);
		free((*list)->content);
		free(*list);
	}
}
