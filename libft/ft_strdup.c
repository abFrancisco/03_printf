/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-b <falves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:27:45 by falves-b          #+#    #+#             */
/*   Updated: 2022/11/14 15:41:30 by falves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		size;
	char	*mem;

	size = ft_strlen(s) + 1;
	mem = malloc(size);
	if (!mem)
		return (NULL);
	ft_strlcpy(mem, s, size);
	return (mem);
}
