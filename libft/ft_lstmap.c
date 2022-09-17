/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 02:27:52 by kcomic            #+#    #+#             */
/*   Updated: 2021/11/13 18:09:13 by kcomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*elem;

	if (!lst)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		elem = ft_lstnew((*f)(lst->content));
		if (elem == NULL)
			ft_lstclear(&elem, del);
		else
			ft_lstadd_back(&new_lst, elem);
		lst = lst->next;
	}
	return (new_lst);
}
