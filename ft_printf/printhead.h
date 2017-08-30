/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhead.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 12:19:26 by sprotsen          #+#    #+#             */
/*   Updated: 2017/02/12 12:19:28 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTHEAD_H
# define PRINTHEAD_H

# include <stdarg.h>
# include <wchar.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>
# include <unistd.h>
# include <stdio.h>

# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define RESET   "\x1b[0m"

# define FL1(x) x == ' ' || x == '#' || x == '+' || x == '-' || x == '0' ? 1 : 0
# define FL2(x) (x == 46 || (x > 48 && x < 58)) ? 1 : 0
# define FL3(x) (x == 'h' || x == 'l' || x == 'j' || x == 'z') ? 1 : 0
# define PSN pr_space_null
# define PPF print_part_flag
# define SYMB(x, y, z) (x == 1 || y == 1 || z == 2) ? 1 : 0

void	for_hex(void *point, size_t *result, int *flag, int symb);
void	pr_space_null(int pr, size_t *res, char c);
void	pr_row(int len, size_t *res, char *str);
void	for_octal(void *point, size_t *res, int *fl);
void	clear_flag(int *flag);
void	for_string(void *point, size_t *res, int *fl);
void	for_symbol(void *point, size_t *res, int *flag);
void	for_decimal(void *point, size_t *res, int *fl);
void	for_u_decimal(void *point, size_t *res, int *fl);
void	pr_hex(uintmax_t a, int i, int *symb, char *row);
void	for_address(void *point, size_t *res, int *fl);
void	for_wchar(wchar_t *str, size_t *res, int *fl);
void	pr_null(size_t *res, int *fl);
void	pr_simple_symbol(char *str, size_t *result, size_t *i);
void	find_all_flags(int *flag, char *str, size_t *i);
void	fun_hh_ll(char *str, int *flag, size_t *a, size_t k);
void	fun_any(char *str, int *flag, size_t *a, size_t k);
void	precision(int *flag, char *str, size_t *a);
void	field_width(int *flag, char *str, size_t *qwe);
void	ft_putwchar(wchar_t s, size_t *res);
void	pr_decimal(intmax_t n, int i, char *row, int *fl);
void	pr_hex(uintmax_t a, int i, int *symb, char *row);
char	*write_row(void *point, int *symb, int *flag);
void	ft_putchar(char c);
void	ft_putstr(char const *s);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
void	ft_putnbr(int n);
int		ft_isdigit(int c);
char	*ft_strdup(const char *s1);
char	*ft_strnew(size_t size);
void	ft_strdel(char **as);
void	ft_strclr(char *s);
int		ft_printf(const char *format, ...);

#endif
