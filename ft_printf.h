/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:58:18 by falves-b          #+#    #+#             */
/*   Updated: 2022/12/21 17:36:39 by falves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#endif
#include "libft/libft.h"
#include <unistd.h>//write()
#include <stdlib.h>//malloc
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

typedef struct s_format
{
	int     invalid;
	char    flags[7];
	int     field_width;
	int     precision;
	char    specifier;
	int     index;
	int     size;
	int     cursor;
} t_format;

int ft_putnbr(int nbr, t_format format);
int ft_putnbr_unsigned(unsigned int nbr, t_format format);
int ft_puthex(unsigned int hex, t_format format);
int	ft_putptr(void *ptr, t_format format);
int	flag_in_format(char flag, char *flags);
int	ft_putchar(char c);
int ft_putstr(char *str, t_format format);
void	print_format(t_format format);
void	set_specifier(const char *format_str, int index, t_format *format);
int	set_flags(const char *format_str,int index, t_format *format);
int	set_field_width(const char *format_str,int index, t_format *format);
int	set_precision(const char *format_str,int index, t_format *format);
t_format	new_format(const char *format_str, int index);
int	convert(t_format format, va_list ap);
int	ft_printf(const char *format_str, ...);
