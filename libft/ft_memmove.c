/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 19:24:28 by kcomic            #+#    #+#             */
/*   Updated: 2021/10/24 19:25:04 by kcomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	i;

	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst < src)
		ft_memcpy(dst, src, len);
	else
	{
		i = len - 1;
		while (i >= 0)
		{
			*((char *)dst + i) = *((char *)src + i);
			i--;
		}
	}
	return (dst);
}
