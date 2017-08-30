/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:48:18 by sprotsen          #+#    #+#             */
/*   Updated: 2017/03/11 20:42:12 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_head.h"

void	read_parameters(char **argv, int n, t_list *par)
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
		ft_lstaddend(&par, ft_lstnew((void*)mass[j],
			ft_strlen((const char*)mass[j]) + 1));
	ft_strdel(&line);
	j = -1;
	while (mass[++j])
		ft_strdel(&(mass[j]));
	free(mass);
}

void	read_instruction(char **argv, int n, t_list *ins)
{
	int		fd;
	char	*line;

	fd = open(argv[n], O_RDONLY);
	fd < 1 ? error(0) : 0;
	while (get_next_line(fd, &line))
	{
		ft_lstaddend(&ins, ft_lstnew((void*)line,
			ft_strlen((const char*)line) + 1));
		ft_strdel(&line);
	}
	close(fd);
}

void	validation_ins(t_list *list)
{
	int		res;

	res = 0;
	if (list == NULL)
		return ;
	ft_strcmp("sa", (char*)(list->content)) == 0 ? res++ : 0;
	ft_strcmp("sb", (char*)list->content) == 0 ? res++ : 0;
	ft_strcmp("ss", (char*)list->content) == 0 ? res++ : 0;
	ft_strcmp("pa", (char*)list->content) == 0 ? res++ : 0;
	ft_strcmp("pb", (char*)list->content) == 0 ? res++ : 0;
	ft_strcmp("ra", (char*)list->content) == 0 ? res++ : 0;
	ft_strcmp("rb", (char*)list->content) == 0 ? res++ : 0;
	ft_strcmp("rr", (char*)list->content) == 0 ? res++ : 0;
	ft_strcmp("rra", (char*)list->content) == 0 ? res++ : 0;
	ft_strcmp("rrb", (char*)list->content) == 0 ? res++ : 0;
	ft_strcmp("rrr", (char*)list->content) == 0 ? res++ : 0;
	if (res != 1)
		error(0);
	validation_ins(list->next);
}

void	read_argum(int argc, char **argv, t_list *par, t_list *ins)
{
	int		i[2];
	char	**m;

	i[0] = 0;
	while (++i[0] < argc && (i[1] = -1))
	{
		if (ft_strcmp("-f", argv[i[0]]) == 0)
			read_parameters(argv, ++i[0], par);
		else if (ft_strcmp("-i", argv[i[0]]) == 0)
			read_instruction(argv, ++i[0], ins);
		else if (static_function_for_flag_cv(argv[i[0]]))
			;
		else
		{
			m = ft_strsplit(argv[i[0]], ' ');
			while (m[++i[1]])
				LEND(&par, ft_lstnew((void*)m[i[1]], ft_strlen(m[i[1]]) + 1));
			i[1] = -1;
			while (m[++i[1]])
				ft_strdel(&(m[i[1]]));
			free(m);
		}
	}
	validation_int(par);
	(ins->next != NULL) ? validation_ins(ins->next) : 0;
}

int		main(int argc, char **argv)
{
	t_list		*parameters;
	t_list		*instruction;

	if (argc == 2 && ft_strcmp(argv[1], "") == 0)
		error(0);
	parameters = ft_lstnew(NULL, 0);
	instruction = ft_lstnew(NULL, 0);
	if (argc < 2)
	{
		ft_printf("%-8s./checker <integer numeric parameters>\n", "usage:");
		ft_printf("\toperations for stack\n\n");
		ft_printf("\t./checker [-f] [name file with numeric parameters]");
		ft_printf("%s\n", "[-i] [name file with operations]");
		return (0);
	}
	read_argum(argc, argv, parameters, instruction);
	get_ull_int(&parameters, &instruction);
	return (0);
}
