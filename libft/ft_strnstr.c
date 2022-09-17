/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 18:40:05 by kcomic            #+#    #+#             */
/*   Updated: 2021/10/24 20:04:44 by kcomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len_needle;
	size_t	len_haystack;

	if (*needle == '\0')
		return ((char *)haystack);
	len_needle = ft_strlen(needle);
	len_haystack = ft_strlen(haystack);
	if (len_needle > len || len_needle > len_haystack)
		return (NULL);
	while (*haystack != '\0' && len >= len_needle
		&& len_haystack >= len_needle)
	{
		if (ft_strncmp(haystack, needle, len_needle) == 0)
			return ((char *)haystack);
		len--;
		len_haystack--;
		haystack++;
	}
	return (NULL);
}
