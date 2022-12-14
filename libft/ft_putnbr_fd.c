/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-b <falves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:25:39 by falves-b          #+#    #+#             */
/*   Updated: 2022/11/28 13:58:55 by falves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

static long	get_long_lenght(long nb)
{
	long	size;

	size = 1;
	while (nb >= 10)
	{
		nb /= 10;
		size *= 10 ;
	}
	return (size);
}

void	ft_putnbr_fd(int nb, int fd)
{
	long	size;
	long	nb_l;

	nb_l = nb;
	if (nb_l < 0)
	{
		ft_putchar('-', fd);
		nb_l = -nb_l;
	}
	size = get_long_lenght(nb_l);
	while (size != 0)
	{
		ft_putchar(nb_l / size + '0', fd);
		nb_l %= size;
		size /= 10;
	}
}
