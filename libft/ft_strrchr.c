/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-b <falves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:49:08 by falves-b          #+#    #+#             */
/*   Updated: 2022/11/09 17:37:12 by falves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;

	tmp = ((void *)0);
	while (*s != '\0')
	{
		if (c == *s)
			tmp = (char *)s;
		s++;
	}
	if (c == *s)
		tmp = (char *)s;
	return (tmp);
}
