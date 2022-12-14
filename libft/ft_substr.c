/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-b <falves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:28:12 by falves-b          #+#    #+#             */
/*   Updated: 2022/11/20 23:40:14 by falves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	char	*sub_start;
	size_t	i;

	if (!s)
		return (NULL);
	sub = malloc(len + 1);
	sub_start = sub;
	i = 0;
	if (sub == NULL)
		return (NULL);
	while (s[i] && i < start + len)
	{
		if (i >= start)
			*sub++ = s[i];
		i++;
	}
	*sub = '\0';
	return (sub_start);
}

/* int main()
{
	char *str = "01234";
	char *ptr = ft_substr(str, 10, 10);
	if (*ptr)
		printf("%s\n", ptr);
	else
		printf("it is NULL\n");
} */