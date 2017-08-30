/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_function_for_flag_cv.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 12:43:43 by sprotsen          #+#    #+#             */
/*   Updated: 2017/03/12 12:43:50 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_head.h"

int		static_indentification(int a)
{
	static int flag = 0;

	flag += a;
	return (flag);
}

int		static_function_for_flag_cv(char *str)
{
	if (ft_strcmp("-cv", str) == 0 || ft_strcmp("-vc", str) == 0)
		return (static_indentification(1));
	if (ft_strcmp("-c", str) == 0)
		return (static_indentification(2));
	if (ft_strcmp("-v", str) == 0)
		return (static_indentification(3));
	return (0);
}
