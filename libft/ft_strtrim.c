/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 20:05:40 by kcomic            #+#    #+#             */
/*   Updated: 2021/10/24 20:22:15 by kcomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*norme_style(size_t start, char const *s1, char const *set)
{
	size_t	i;
	char	*ptr;
	size_t	fin;

	fin = ft_strlen(s1) - 1;
	while (fin > start)
	{
		if (ft_strchr(set, s1[fin]) == NULL)
			break ;
		fin--;
	}
	ptr = (char *)malloc(sizeof(char) * (fin - start + 2));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (start + i <= fin)
	{
		ptr[i] = s1[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	char	*ptr;

	if (!s1)
		return (NULL);
	start = 0;
	while (s1[start])
	{
		if (ft_strchr(set, s1[start]) == NULL)
			break ;
		start++;
	}
	if (ft_strlen(s1) == 0 || start == ft_strlen(s1))
	{
		ptr = (char *)malloc(sizeof(char));
		if (ptr == NULL)
			return (NULL);
		*ptr = '\0';
		return (ptr);
	}
	return (norme_style(start, s1, set));
}
