/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 18:19:53 by kcomic            #+#    #+#             */
/*   Updated: 2021/10/23 17:01:13 by kcomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] || c == 0)
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
