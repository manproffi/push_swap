/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 19:54:57 by sprotsen          #+#    #+#             */
/*   Updated: 2017/03/11 20:43:07 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_head.h"

void	validation_duplicate(int *row, int len)
{
	int		i;
	int		j;

	i = -1;
	while (++i < len - 1)
	{
		j = i;
		while (++j < len)
			if (row[i] == row[j])
				error(0);
	}
}

void	validation_ins_stat(char *str)
{
	int		res;

	res = 0;
	if (str == NULL)
		return ;
	ft_strcmp("sa", str) == 0 ? res++ : 0;
	ft_strcmp("sb", str) == 0 ? res++ : 0;
	ft_strcmp("ss", str) == 0 ? res++ : 0;
	ft_strcmp("pa", str) == 0 ? res++ : 0;
	ft_strcmp("pb", str) == 0 ? res++ : 0;
	ft_strcmp("ra", str) == 0 ? res++ : 0;
	ft_strcmp("rb", str) == 0 ? res++ : 0;
	ft_strcmp("rr", str) == 0 ? res++ : 0;
	ft_strcmp("rra", str) == 0 ? res++ : 0;
	ft_strcmp("rrb", str) == 0 ? res++ : 0;
	ft_strcmp("rrr", str) == 0 ? res++ : 0;
	if (res != 1)
		error(0);
}

void	read_instruction_2(t_list *ins)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strlen(line) == 0)
		{
			break ;
		}
		validation_ins_stat(line);
		ft_lstaddend(&ins, ft_lstnew((void*)line, ft_strlen(line) + 1));
		ft_strdel(&line);
	}
	line != NULL ? ft_strdel(&line) : 0;
	validation_ins(ins->next);
}

void	get_ull_int(t_list **parameters, t_list **instruction)
{
	int			a[ft_lstsize((*parameters)->next)];
	int			len;
	int			i;
	long long	k;
	t_list		*list;

	i = -1;
	list = (*parameters)->next;
	len = ft_lstsize(list);
	while (++i < len)
	{
		k = ft_atoi_ulli(list->content);
		if (k < -2147483648 || k > 2147483647)
			error(0);
		else
			a[i] = (int)k;
		list = list->next;
	}
	validation_duplicate(a, len);
	if ((*instruction)->next == NULL)
		read_instruction_2(*instruction);
	operation(a, len, instruction, static_indentification(0));
	del_list(parameters);
	del_list(instruction);
}

void	validation_int(t_list *list)
{
	char	*c;
	int		i;

	list = list->next;
	if (!list)
		error(0);
	while (list)
	{
		c = list->content;
		if (c == NULL)
			error(0);
		i = -1;
		while (c && c[++i])
		{
			if (c[i] == '-' && ft_isdigit(c[i + 1]))
				;
			else if (ft_isdigit(c[i]) == 0)
				error(0);
		}
		list = list->next;
	}
}
