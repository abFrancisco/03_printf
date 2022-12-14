/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-b <falves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:03:16 by falves-b          #+#    #+#             */
/*   Updated: 2022/11/17 13:24:22 by falves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	l;
	int		len;

	len = ft_nlen(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	l = n;
	if (n < 0)
	{
		l = -l;
		str[0] = '-';
	}
	while (l)
	{
		str[len - 1] = (l % 10) + '0';
		l = l / 10;
		len--;
	}
	if (n == 0)
		str[len - 1] = '0';
	return (str);
}
