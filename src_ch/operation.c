/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 19:50:24 by sprotsen          #+#    #+#             */
/*   Updated: 2017/03/10 20:03:27 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_head.h"

void	review_sort(int *a, int len_a, int len_b, t_list **ins)
{
	int		i;

	i = -1;
	(void)ins;
	if (len_b == 0)
	{
		while (++i < len_a - 1)
			if (a[i] < a[i + 1])
				;
			else
			{
				ft_printf(RED"KO\n");
				return ;
			}
		ft_printf(GREEN"OK\n");
	}
	else
		ft_printf(RED"KO\n");
}

void	p_function(int *a, int *b, int *len_a, int *len_b)
{
	int		i;
	int		len;

	i = -1;
	ft_printf(" -----------------------------------------------\n");
	ft_printf("|        stack a        |        stack b        |\n");
	ft_printf(" -----------------------------------------------\n");
	if (*len_a <= *len_b)
		(len = *len_b);
	else
		(len = *len_a);
	while (++i < len)
	{
		if (i < *len_a && i < *len_b)
			ft_printf("|%15d\t|\t%-15d\t|\n", a[i], b[i]);
		else if (i < *len_a)
			ft_printf("|%15d\t|\t%-15s\t|\n", a[i], "-");
		else if (i < *len_b)
			ft_printf("|%15s\t|\t%-15d\t|\n", "-", b[i]);
	}
	ft_printf(" -----------------------------------------------\n");
}

void	find_operation(t_list *list, int *a, int *b, int *len)
{
	ft_strcmp("sa", (char*)list->content) == 0 ? SA : 0;
	ft_strcmp("sb", (char*)list->content) == 0 ? SB : 0;
	ft_strcmp("ss", (char*)list->content) == 0 ? SS : 0;
	ft_strcmp("pa", (char*)list->content) == 0 ? PA : 0;
	ft_strcmp("pb", (char*)list->content) == 0 ? PB : 0;
	ft_strcmp("ra", (char*)list->content) == 0 ? RA : 0;
	ft_strcmp("rb", (char*)list->content) == 0 ? RB : 0;
	ft_strcmp("rr", (char*)list->content) == 0 ? RR : 0;
	ft_strcmp("rra", (char*)list->content) == 0 ? RRA : 0;
	ft_strcmp("rrb", (char*)list->content) == 0 ? RRB : 0;
	ft_strcmp("rrr", (char*)list->content) == 0 ? RRR : 0;
}

void	operation(int *a, int length, t_list **ins, int flag)
{
	int		b[length];
	int		len[2];
	t_list	*list;

	list = (*ins)->next;
	len[0] = length;
	len[1] = 0;
	while (list)
	{
		find_operation(list, a, b, len);
		if ((flag == 1 || flag == 5) && list->next == NULL)
		{
			ft_printf(YELLOW "%s\n", list->content);
			p_function(a, b, &len[0], &len[1]);
		}
		if (flag > 0 && flag != 2 && list->next != NULL)
		{
			ft_printf("%s\n", list->content);
			p_function(a, b, &len[0], &len[1]);
		}
		list = list->next;
		if (flag > 0)
			sleep(1);
	}
	review_sort(a, len[0], len[1], ins);
}
