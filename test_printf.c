/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:26:01 by falves-b          #+#    #+#             */
/*   Updated: 2022/12/23 11:50:53 by falves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(void)
{
	int number = 42;
	printf("%%0d    ->|%0d|\n", number);
	printf("%%1d    ->|%1d|\n", number);
	printf("%%2d    ->|%2d|\n", number);
	printf("%%3d    ->|%3d|\n", number);
	printf("%%03d   ->|%03d|\n", number);
	printf("%%03d   ->|%4d|\n", number);
	printf("%%03d   ->|%04d|\n", number);
	printf("%%0.0d  ->|%0.0d|\n", number);
	printf("%%0.1d  ->|%0.1d|\n", number);
	printf("%%1.0d  ->|%1.0d|\n", number);
	printf("%%1.1d  ->|%1.1d|\n", number);
	printf("%%2.0d  ->|%2.0d|\n", number);
	printf("%%2.1d  ->|%2.1d|\n", number);
	printf("%%3.0d  ->|%3.0d|\n", number);
	printf("%%3.1d  ->|%3.1d|\n", number);
	printf("%%3.2d  ->|%3.2d|\n", number);
	printf("%%3.3d  ->|%3.3d|\n", number);
	printf("%%3.4d  ->|%3.4d|\n", number);
	printf("%%3.5d  ->|%3.5d|\n", number);
	printf("%%4.0d  ->|%4.0d|\n", number);
	printf("%%4.1d  ->|%4.1d|\n", number);
	printf("%%4.2d  ->|%4.2d|\n", number);
	printf("%%4.3d  ->|%4.3d|\n", number);
	printf("%%4.4d  ->|%4.4d|\n", number);
	printf("%%4.5d  ->|%4.5d|\n", number);
	printf("%%4.6d  ->|%4.6d|\n", number);
	printf("%%5.0d  ->|%5.0d|\n", number);
	printf("%%5.1d  ->|%5.1d|\n", number);
	printf("%%5.2d  ->|%5.2d|\n", number);
	printf("%%5.3d  ->|%5.3d|\n", number);
	printf("%%5.4d  ->|%5.4d|\n", number);
	printf("%%5.5d  ->|%5.5d|\n", number);
	printf("%%5.6d  ->|%5.6d|\n", number);
	printf("%%5.7d  ->|%5.7d|\n", number);
	printf("%%05d   ->|%05d|\n", number);
	printf("%%05.7d ->|%05.7d|\n", number);
	printf("%%5.7d  ->|%5.7d|\n", number);
	printf("%%-5.7d ->|%-5.7d|\n", number);
	printf("%%5.7d  ->|%5.7d|\n", number);
	printf("%% 5.7d ->|% 5.7d|\n", number);
	printf("%%5.7d  ->|%5.7d|\n", number);
	printf("%%+5.7d ->|%+5.7d|\n", number);

	

}
