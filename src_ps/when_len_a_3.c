/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   when_len_a_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 21:29:35 by sprotsen          #+#    #+#             */
/*   Updated: 2017/03/28 21:29:37 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_head.h"

void	when_len_a_3(size_t *a, size_t *b, int *len)
{
	if (a[0] < a[1] && a[1] < a[2])
		;
	else if (a[0] < a[1] && a[0] > a[2])
		RRA;
	else if (a[0] > a[1] && a[1] > a[2])
	{
		ss_sa(a, b, len);
		RRA;
	}
	else if (a[0] < a[2] && a[1] > a[2])
	{
		ss_sa(a, b, len);
		RA;
	}
	else if (a[0] > a[1] && a[0] < a[2])
		ss_sa(a, b, len);
	else if (a[0] > a[2] && a[2] > a[1])
		RA;
}

void	when_len_a_3_but_not_empty_next(size_t *a, size_t *b, int *len)
{
	if (a[0] > a[2] && a[1] < a[2])
	{
		ss_sa(a, b, len);
		RA;
		ss_sa(a, b, len);
		RRA;
	}
	else if (a[0] < a[1] && a[0] > a[2])
	{
		RA;
		ss_sa(a, b, len);
		RRA;
		ss_sa(a, b, len);
	}
	else if (a[0] > a[1] && a[0] < a[2])
		ss_sa(a, b, len);
}

void	when_len_a_3_but_not_empty(size_t *a, size_t *b, int *len)
{
	if (a[0] < a[1] && a[1] < a[2])
		;
	else if (a[0] > a[1] && a[1] > a[2])
	{
		ss_sa(a, b, len);
		RA;
		ss_sa(a, b, len);
		RRA;
		ss_sa(a, b, len);
		return ;
	}
	else if (a[0] < a[2] && a[1] > a[2])
	{
		RA;
		ss_sa(a, b, len);
		RRA;
		return ;
	}
	when_len_a_3_but_not_empty_next(a, b, len);
}
