/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-b <falves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:51:32 by falves-b          #+#    #+#             */
/*   Updated: 2022/12/09 19:41:23 by falves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*RETURN VALUE
Upon successful return, these functions return the number of
characters printed (excluding the null byte used to end output to
strings).
If an output error is encountered, a negative value is returned.
*/
/*DESCRIPTION
The functions printf() and
vprintf() write output to stdout, the standard output stream;

All of these functions write the output under the control of a
format string that specifies how subsequent arguments (or
arguments accessed via the variable-length argument facilities of
stdarg(3)) are converted for output.*/

#include <unistd.h>//write()
#include <stdarg.h>
#include <stdio.h>
#include <string.h>


typedef struct s_format
{
	char	flags[6];
	int		field_width;
	int		precision;
	char	specifier;
	int		size;
} t_format;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	set_specifier(const char *format_str, int index, t_format *format)
{
	int		i;
	int		j;
	char	*specifiers;

	
	specifiers = "cspdiuxX%";
	i = 1;
	while (format_str[index + i])
	{
		j = 0;
		while(specifiers[j])
		{
			if (format_str[index + i] == specifiers[j])
			{
				format->specifier = specifiers[j];
				format->size = i + 1;
				return ;
			}
			j++;
		}
		i++;
	}
	return ;
}

void	print_format(t_format format)
{
	printf( "\nflags       = %s\n"
			"field_width = %i\n"
			"precision   = %i\n"
			"specifier   = %c\n"
			"size        = %i\n",
			format.flags, format.field_width, format.precision, format.specifier, format.size);
}

t_format	get_format(const char *format_str, int index)
{
	t_format	format;
	char		specifier;
	int			size;


	set_specifier(format_str, index, &format);
	print_format(format);
	return (format);
}

int	convert(const char *format_str, int index, t_format format, va_list ap)
{
	return 0;
}

int	ft_printf(const char *format_str, ...)
{
	int			i;
	va_list		ap;
	va_list		ap_copy;
	t_format	format;
	
	va_start(ap, format_str);
	i = 0;
	while(*format_str)
	{
		if (format_str[i] == '%')
		{
			format = get_format(format_str, i);
			convert(format_str, i, format, ap);
			i += format.size;
		}
		else
			ft_putchar(format_str[i++]);
	}
	va_end(ap);
	return 1;
}

int main()
{
	ft_printf("asd%     casd\n", 'Z');
}

/*printf

format of format string contains 0 or more of:
	ordinary characters(not %) which are copied unchanged
	conversion specifications, result in fetchin 0 or more subsequent arguments
	
conversion specifications always start with % and end with a conversion specifier
in between there may be (in this order) zero or more flags, an optional minimum field /
	an optional precision and an optional length modifier (length modifier not required)
mandatory conversion specifiers:
	%c Prints a single character.
	%s Prints a string (as defined by the common C convention).
	%p The void * pointer argument has to be printed in hexadecimal format.
	%d Prints a decimal (base 10) number.
	%i Prints an integer in base 10.
	%u Prints an unsigned decimal (base 10) number.
	%x Prints a number in hexadecimal (base 16) lowercase format.
	%X Prints a number in hexadecimal (base 16) uppercase format.
	%% Prints a percent sign.
	extract all the formats

bonus 1
	manage any combination of the following flags -> '-0.' and the field minimum width under all conversions
	'-' ->	left aligns content instead of the default right align
	'0' ->	pads result with 0's to the left, Applied to d, i, u, x, X, for others behaviour is undefined
	'.' ->	precision, first digit after '.' cant be zero, '.' alone means precision 0, 
			is minimum number of digits for d, i, u, x, X 
			number of digits to appear after radix character for ...... (N/A)
			maximum number of characters to printed from a string for s, S
			.5 means precision 5
			
	field width
		->	field width never truncates or limits the size of the result
		->	will pad values smaller than field width with spaces or 0's, depending on flags used (left or right padded and '0' flag)
bonus 2
	Manage all the following flags: '# +' (Yes, one of them is a space)
*/