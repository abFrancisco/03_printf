/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:37:37 by falves-b          #+#    #+#             */
/*   Updated: 2022/12/23 12:58:32 by falves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include "libft/libft.h"

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
	/*str = "12345%- # +-+----++##### 00047.000000000000000000000000000000000000009c4321";
	printf("\nTEST STRING = %s\n", str);
	printf("\n\nMY PRINTF\n");
	ret = ft_printf(str, "hello world");
	printf(str_ret, ret);
	printf("\n\nREAL PRINTF\n");
	ret = printf(str, "hello world");
	printf(str_ret, ret);*/

	//INT TEST
	ft_printf("%20d", -1234);
}
