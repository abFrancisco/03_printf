/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-b <falves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:58:52 by falves-b          #+#    #+#             */
/*   Updated: 2022/11/28 13:58:10 by falves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst2;
	t_list	*node;

	lst2 = NULL;
	if (lst && f && del)
	{
		while (lst)
		{
			node = ft_lstnew(f(lst->content));
			if (!node)
				ft_lstclear(&node, del);
			ft_lstadd_back(&lst2, node);
			lst = lst->next;
		}
	}
	return (lst2);
}
