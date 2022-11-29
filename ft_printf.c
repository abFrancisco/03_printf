/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-b <falves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:51:32 by falves-b          #+#    #+#             */
/*   Updated: 2022/11/29 15:56:12 by falves-b         ###   ########.fr       */
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

#include <stdarg.h>
#include <stdio.h>

int	ft_printf(const char format, ...)
{
	va_list ap;
	
	va_start(ap, format);
	
	printf("%i\n", va_arg(ap, int));
	printf("%i\n", va_arg(ap, int));
	printf("%i\n", va_arg(ap, int));
	printf("%i\n", va_arg(ap, int));
	printf("%i\n", va_arg(ap, int));
	va_end(ap);
}


int main()
{
	ft_printf(1,2,3,4,5,6,7,8);
	printf("%5d\n", 15, 123, 50);
}
/*printf

format of format string contains 0 or more of:
	ordinary characters(not %) which are copied unchanged
	conversion specifications, result in fetchin 0 or more subsequent arguments
	
conversion specifications always start with % and end with a conversion specifier
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
*/