/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-b <falves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:39:57 by falves-b          #+#    #+#             */
/*   Updated: 2022/11/21 00:09:45 by falves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*prev_node;

	if (del && lst)
	{
		while (*lst)
		{
			prev_node = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = prev_node;
		}
	}
}
