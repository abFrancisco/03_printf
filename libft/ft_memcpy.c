/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-b <falves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:46:40 by falves-b          #+#    #+#             */
/*   Updated: 2022/11/09 17:37:27 by falves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*tmp_src;
	char	*tmp_dest;

	if (!dest && !src)
		return (NULL);
	tmp_src = (char *)src;
	tmp_dest = (char *)dest;
	while (n--)
		*tmp_dest++ = *tmp_src++;
	return (dest);
}
