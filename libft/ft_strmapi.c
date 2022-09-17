/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 20:03:05 by kcomic            #+#    #+#             */
/*   Updated: 2021/10/24 20:03:48 by kcomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*dst;
	size_t	i;
	size_t	len;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dst[i] = f(i, s[i]);
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
