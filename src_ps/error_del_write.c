/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_del_write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 20:53:19 by sprotsen          #+#    #+#             */
/*   Updated: 2017/03/28 20:53:21 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_head.h"

int		winfile(int fd)
{
	static int x = 0;

	x += fd;
	return (x);
}

void	write_in_file(int a)
{
	int		fd;

	if (a > 0)
	{
		fd = open("answer.txt", O_TRUNC | O_WRONLY | O_APPEND);
		if (fd < 0)
		{
			write(1, "Error with file\n", 16);
			exit(0);
		}
		winfile(fd);
	}
}

void	error(int i)
{
	if (i == 0)
		;
	ft_printf(RED"Error\n");
	exit(0);
}

void	del_list_1(t_list **list)
{
	if ((*list))
	{
		del_list_1(&(*list)->next);
		free((*list)->content);
		free(*list);
	}
}

void	del_list_elem(t_list **list)
{
	t_list	*free_me;

	if ((*list))
	{
		free_me = *list;
		*list = (*list)->next;
		free(free_me->content);
		free(free_me);
	}
}
