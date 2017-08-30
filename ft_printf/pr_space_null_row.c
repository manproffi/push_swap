/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_space_null_row.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 20:49:10 by sprotsen          #+#    #+#             */
/*   Updated: 2017/02/22 20:49:11 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printhead.h"

void	pr_space_null(int pr, size_t *res, char c)
{
	while (pr-- > 0)
	{
		*res += 1;
		write(1, &c, 1);
	}
}

void	pr_row(int len, size_t *res, char *str)
{
	while (len-- > 0)
	{
		*res += 1;
		ft_putchar(str[len]);
	}
}
