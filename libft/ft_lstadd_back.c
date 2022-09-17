/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 02:07:19 by kcomic            #+#    #+#             */
/*   Updated: 2021/11/10 19:06:13 by kcomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_elem;

	if (new == NULL)
		return ;
	if (*lst)
	{
		last_elem = ft_lstlast(*lst);
		last_elem->next = new;
	}
	else
		*lst = new;
}
