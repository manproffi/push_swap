/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 18:36:21 by sprotsen          #+#    #+#             */
/*   Updated: 2017/02/22 20:41:51 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printhead.h"

void	procenttecken(int *flag, char *str, size_t *i, size_t *result)
{
	if (str[*i] == '%')
	{
		if (flag[3] == 1)
			ft_putchar('%');
		*result += (flag[5] - 1) > 0 ? (flag[5] - 1) : 0;
		if (flag[4] == 0 || flag[3] == 1)
		{
			while (flag[5]-- > 1)
				ft_putchar(' ');
		}
		else if (flag[4] == 1)
		{
			while (flag[5]-- > 1)
				ft_putchar('0');
		}
		if (flag[3] == 0)
			ft_putchar('%');
		*result += 1;
		*i += 1;
	}
}

void	read_all_flags(char *str, size_t *result, size_t *i, int *flag)
{
	size_t	len;

	len = ft_strlen(str);
	clear_flag(flag);
	*i < len ? pr_simple_symbol(str, result, i) : 0;
	*i < len ? find_all_flags(flag, str, i) : 0;
	*i < len ? procenttecken(flag, str, i, result) : 0;
}

void	for_symbol_s(char s, size_t *res, int *flag)
{
	int		k;

	*res += 1;
	k = 0;
	flag[3] == 1 ? flag[4] = 0 : 0;
	flag[6] > 0 ? flag[6] = 0 : 0;
	if (flag[3] == 1)
		ft_putchar(s);
	if (flag[6] == -1)
		k = flag[5] - 1;
	else if (flag[5])
		k = flag[5] - 1;
	else if (flag[6] && flag[5])
		k = flag[5] - flag[6] - 1;
	if (flag[5] > 0)
		while (k-- > 0)
		{
			*res += 1;
			flag[4] == 1 ? ft_putchar('0') : ft_putchar(' ');
		}
	if (flag[3] == 0)
		ft_putchar(s);
}

void	conversions(int *fl, size_t *result, char s, va_list *ap)
{
	int		k;

	k = 0;
	s == 'x' ? for_hex(va_arg(*ap, void*), result, fl, 97) : k++;
	s == 'X' ? for_hex(va_arg(*ap, void*), result, fl, 65) : k++;
	(s == 's' && fl[7] == 3) ? for_wchar(va_arg(*ap, void*), result, fl) : k++;
	(s == 's' && fl[7] != 3) ? for_string(va_arg(*ap, void*), result, fl) : k++;
	s == 'S' ? for_wchar(va_arg(*ap, void*), result, fl) : k++;
	s == 'o' ? for_octal(va_arg(*ap, void*), result, fl) : k++;
	s == 'c' ? for_symbol(va_arg(*ap, void*), result, fl) : k++;
	s == 'C' ? for_symbol(va_arg(*ap, void*), result, fl) : k++;
	s == 'd' ? for_decimal(va_arg(*ap, void*), result, fl) : k++;
	s == 'i' ? for_decimal(va_arg(*ap, void*), result, fl) : k++;
	s == 'u' ? for_u_decimal(va_arg(*ap, void*), result, fl) : k++;
	if (s == 'O' || s == 'D' || s == 'U' || s == 'p')
	{
		s == 'p' ? fl[1] = 1 : 0;
		s == 'p' ? for_address(va_arg(*ap, void*), result, fl) : k++;
		fl[7] = 3;
		s == 'O' ? for_octal(va_arg(*ap, void*), result, fl) : k++;
		s == 'D' ? for_decimal(va_arg(*ap, void*), result, fl) : k++;
		s == 'U' ? for_u_decimal(va_arg(*ap, void*), result, fl) : k++;
	}
	if (k == 11)
		s != '\0' ? for_symbol_s(s, result, fl) : 0;
}

int		ft_printf(const char *format, ...)
{
	char		*str;
	size_t		result;
	int			flag[8];
	size_t		i;
	va_list		ap;

	result = 0;
	i = 0;
	str = ft_strdup(format);
	va_start(ap, format);
	while (i < ft_strlen(str))
	{
		read_all_flags(str, &result, &i, flag);
		conversions(flag, &result, str[i], &ap);
		i++;
	}
	va_end(ap);
	free(str);
	return (result);
}
