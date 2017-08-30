/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 19:05:00 by sprotsen          #+#    #+#             */
/*   Updated: 2017/03/13 19:05:02 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_head.h"

void	get_mass_int(t_list **param)
{
	int			a[ft_lstsize((*param)->next)];
	int			len;
	int			i;
	long long	k;
	t_list		*list;

	i = -1;
	list = (*param)->next;
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
	validation_duplicate_int(a, len);
	del_list_1(param);
	chang_a(a, len);
}

void	validation_param(t_list *list)
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

void	read_from_file(char **argv, int n, t_list *param)
{
	int		fd;
	int		j;
	char	*line;
	char	**mass;

	fd = open(argv[n], O_RDONLY);
	if (fd < 0)
		error(0);
	get_next_line(fd, &line);
	close(fd);
	mass = ft_strsplit(line, ' ');
	j = -1;
	while (mass[++j])
		LEND(&param, ft_lstnew((void*)mass[j], ft_strlen(mass[j]) + 1));
	ft_strdel(&line);
	j = -1;
	while (mass[++j])
		ft_strdel(&(mass[j]));
	free(mass);
}

void	read_param(int argc, char **argv, t_list *param)
{
	int		i;
	int		j;
	char	**mass;

	i = 0;
	while (++i < argc)
	{
		if (ft_strcmp("-f", argv[i]) == 0)
			read_from_file(argv, ++i, param);
		else if (ft_strcmp("-w", argv[i]) == 0)
			write_in_file(1);
		else
		{
			mass = ft_strsplit(argv[i], ' ');
			j = -1;
			while (mass[++j])
				LEND(&param, ft_lstnew((void*)mass[j], ft_strlen(mass[j]) + 1));
			j = -1;
			while (mass[++j])
				ft_strdel(&(mass[j]));
			free(mass);
		}
	}
	validation_param(param);
}

int		main(int argc, char **argv)
{
	t_list	*parameters;

	if (argc == 2 && ft_strcmp(argv[1], "") == 0)
		error(0);
	parameters = ft_lstnew(NULL, 0);
	if (argc < 2)
		return (0);
	read_param(argc, argv, parameters);
	get_mass_int(&parameters);
	if (winfile(0) == 3)
		close(3);
	return (0);
}
