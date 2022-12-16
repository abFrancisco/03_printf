/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-b <falves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:51:32 by falves-b          #+#    #+#             */
/*   Updated: 2022/12/16 17:42:04 by falves-b         ###   ########.fr       */
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
#include "libft/libft.h"
#include <unistd.h>//write()
#include <stdlib.h>//malloc
#include <stdarg.h>
#include <stdio.h>
#include <string.h>


typedef struct s_format
{
	int		invalid;
	char	flags[6];
	int		field_width;
	int		precision;
	char	specifier;
	int		index;
	int		size;
	int		cursor;
} t_format;

int	flag_in_format(char flag, char *flags)
{
	if (ft_strchr(flags, flag))
		return (1);
	return (0);
}

int	ft_putchar(char c)
{
	return write(1, &c, 1);
}

int ft_putstr(char *str, t_format format)
{
	int	i;
	int	j;
	int	len;

	len = ft_strlen(str);
	j = 0;
	i = 0;
	while (!flag_in_format('-', format.flags) && (format.field_width > len || format.field_width > format.precision))
	{
		format.field_width--;
		write(1, " ", 1);
		j++;
	}
	while (str[i] && i < format.precision)
	{
		write(1, &str[i++], 1);
		if (i < format.precision && str[i + 1] == '\0')
			write(1, &str[i + 1], 1);
	}
	while (format.field_width > len || format.field_width > format.precision)
	{
		format.field_width--;
		write(1, " ", 1);
		j++;
	}
	return (i + j);
}

void	print_format(t_format format)
{
	printf( "\n\ninvalid     = %i\n"
			"flags       = %s\n"
			"field_width = %i\n"
			"precision   = %i\n"
			"specifier   = %c\n"
			"index       = %i\n"
			"size        = %i\n"
			"cursor      = %i\n\n",
			format.invalid, format.flags, format.field_width, format.precision, format.specifier, format.index, format.size, format.cursor);
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
				format->index = index;
				format->size = i + 1;
				return ;
			}
			j++;
		}
		i++;
	}
	return ;
}

int	set_flags(const char *format_str,int index, t_format *format)
{
	char	*found;
	char	*flags;
	int		j;

	j = 0;
	flags = "-0# +";
	format->cursor = index + 1;//+ 1 is to skip the first % of the format specifier entry
	while (format->cursor - index < format->size)
	{
		found = strchr(flags, format_str[format->cursor]);
		if (found)
		{
			if (strchr(format->flags, *found))
				return (-1);
			else
				format->flags[j++] = *found;
		}
		else
			return (0);
		format->cursor++;
	}
	return (0);
}

int	set_field_width(const char *format_str,int index, t_format *format)
{
	char	*digits;
	char	width[10];
	int		j;

	digits = "0123456789";
	j = 0;
	while (strchr(digits, format_str[format->cursor]) && format->cursor - index < format->size)
	{
		width[j++] = format_str[format->cursor++];
		if (j >= 10)
			return (-1);
	}
	format->field_width = atoi(width);
	if (format->field_width == -1)//need to modify atoi and make it return 0 in case of error(string cant be converted to int)
		return (-1);
	return (0);
}

int	set_precision(const char *format_str,int index, t_format *format)
{
	char	*digits;
	char	precision[10];
	int		j;


	digits = "0123456789";
	j = 0;
	if (format_str[format->cursor] != '.')
	{
		format->precision = -1;
		return (0);
	}
	format->cursor++;
	while (strchr(digits, format_str[format->cursor]) && format->cursor - index < format->size)
	{
		precision[j++] = format_str[format->cursor++];
		if (j >= 10)
			return (-1);
	}
	precision[j] = '\0';
	format->precision = atoi(precision);
	if (format->precision == -1)//same as set_field_width
		return (-1);
	return (0);
}

t_format	new_format(const char *format_str, int index)
{
	t_format	format;

	format.cursor = 0;
	format.invalid = 0;
	set_specifier(format_str, index, &format);
	//format.invalid = -1; check if this is needed with an if above
	if (set_flags(format_str, index, &format))
		format.invalid = -1;
	if (set_field_width(format_str, index, &format))
		format.invalid = -1;
	if (set_precision(format_str, index, &format))
		format.invalid = -1;
	return (format);
}

int	convert(t_format format, va_list ap)
{
	//specifiers = "cspdiuxX%";
	if (format.specifier == 'c')
		return ft_putchar(va_arg(ap, int));
	else if (format.specifier == 's')
		return ft_putstr(va_arg(ap, char*), format);

	return (0);
}

int	ft_printf(const char *format_str, ...)
{
	int			byte_count;
	int			i;
	va_list		ap;
	t_format	format;

	va_start(ap, format_str);
	i = 0;
	byte_count = 0;
	while(format_str[i])
	{
		if (format_str[i] == '%')
		{
			format = new_format(format_str, i);
			if (format.invalid)
				return (-1);
			byte_count += convert(format, ap);
			i += format.size;
		}
		else
			byte_count += ft_putchar(format_str[i++]);
	}
	va_end(ap);
	return (byte_count);
}

#include <stdio.h>

int main()
{
	char	*str;
	char	*str_ret;
	int ret;

 	str_ret = "\nReturn = %i\n\n\n\n\n";
	//CHAR TEST
 	//str = "12345%c54321\n";
 	//ret = 0;
 	//ret = ft_printf(str, 'z');
 	//printf(str_ret, ret);
 	//ret = printf(str, 'z');
 	//printf(str_ret, ret);

	//STRING TEST
	str = "12345%-2.2s4321";
	printf("\nTEST STRING = %s\n", str);
	printf("\n\nMY PRINTF\n");
	ret = ft_printf(str, "hello world");
	printf(str_ret, ret);
	printf("\n\nREAL PRINTF\n");
	ret = printf(str, "hello world");
	printf(str_ret, ret);
}

/*printf
conversion specifier format
	%[$][flags][width][.precision][length modifier]conversion

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
	manage any combination of the following f
		#	  The value should be converted to an "alternate form".  For
              o conversions, the first character of the output string is
              made zero (by prefixing a 0 if it was not zero already).
              For x and X conversions, a nonzero result has the string
              "0x" (or "0X" for X conversions) prepended to it.  For a,
              A, e, E, f, F, g, and G conversions, the result will
              always contain a decimal point, even if no digits follow
              it (normally, a decimal point appears in the results of
              those conversions only if a digit follows).  For g and G
              conversions, trailing zeros are not removed from the
              result as they would otherwise be.  For other conversions,
              the result is undefined.

       0      The value should be zero padded.  For d, i, o, u, x, X, a,
              A, e, E, f, F, g, and G conversions, the converted value
              is padded on the left with zeros rather than blanks.  If
              the 0 and - flags both appear, the 0 flag is ignored.  If
              a precision is given with a numeric conversion (d, i, o,
              u, x, and X), the 0 flag is ignored.  For other
              conversions, the behavior is undefined.

       -      The converted value is to be left adjusted on the field
              boundary.  (The default is right justification.)  The
              converted value is padded on the right with blanks, rather
              than on the left with blanks or zeros.  A - overrides a 0
              if both are given.

       ' '    (a space) A blank should be left before a positive number
              (or empty string) produced by a signed conversion.

       +      A sign (+ or -) should always be placed before a number
              produced by a signed conversion.  By default, a sign is
              used only for negative numbers.  A + overrides a space if
              both are used.

       The five flag characters above are defined in the C99 standard.
       The Single UNIX Specification specifies one further flag
       character.

       '      For decimal conversion (i, d, u, f, F, g, G) the output is
              to be grouped with thousands' grouping characters if the
              locale information indicates any.  (See setlocale(3).)
              Note that many versions of gcc(1) cannot parse this option
              and will issue a warning.  (SUSv2 did not include %'F, but
              SUSv3 added it.)

       glibc 2.2 adds one further flag character.

       I      For decimal integer conversion (i, d, u) the output uses
              the locale's alternative output digits, if any.  For
              example, since glibc 2.2.3 this will give Arabic-Indic
              digits in the Persian ("fa_IR") locale.

   Field width
       An optional decimal digit string (with nonzero first digit)
       specifying a minimum field width.  If the converted value has
       fewer characters than the field width, it will be padded with
       spaces on the left (or right, if the left-adjustment flag has
       been given).  Instead of a decimal digit string one may write "*"
       or "*m$" (for some decimal integer m) to specify that the field
       width is given in the next argument, or in the m-th argument,
       respectively, which must be of type int.  A negative field width
       is taken as a '-' flag followed by a positive field width.  In no
       case does a nonexistent or small field width cause truncation of
       a field; if the result of a conversion is wider than the field
       width, the field is expanded to contain the conversion result.

   Precision
       An optional precision, in the form of a period ('.')  followed by
       an optional decimal digit string.  Instead of a decimal digit
       string one may write "*" or "*m$" (for some decimal integer m) to
       specify that the precision is given in the next argument, or in
       the m-th argument, respectively, which must be of type int.  If
       the precision is given as just '.', the precision is taken to be
       zero.  A negative precision is taken as if the precision were
       omitted.  This gives the minimum number of digits to appear for
       d, i, o, u, x, and X conversions, the number of digits to appear
       after the radix character for a, A, e, E, f, and F conversions,
       the maximum number of significant digits for g and G conversions,
       or the maximum number of characters to be printed from a string
       for s and S conversions.

   Length modifier
       Here, "integer conversion" stands for d, i, o, u, x, or X
       conversion.

       hh     A following integer conversion corresponds to a signed
              char or unsigned char argument, or a following n
              conversion corresponds to a pointer to a signed char
              argument.

       h      A following integer conversion corresponds to a short or
              unsigned short argument, or a following n conversion
              corresponds to a pointer to a short argument.

       l      (ell) A following integer conversion corresponds to a long
              or unsigned long argument, or a following n conversion
              corresponds to a pointer to a long argument, or a
              following c conversion corresponds to a wint_t argument,
              or a following s conversion corresponds to a pointer to
              wchar_t argument.

       ll     (ell-ell).  A following integer conversion corresponds tolags -> '-0.' and the field minimum width under all conversions
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
