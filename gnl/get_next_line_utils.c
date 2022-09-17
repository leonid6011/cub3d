/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 04:33:27 by marvin            #+#    #+#             */
/*   Updated: 2021/12/29 04:33:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_gnl_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] || c == 0)
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

char	*ft_gnl_strjoin(char *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	char	*ptr;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
	}
	len = ft_gnl_strlen(s1) + ft_gnl_strlen(s2);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		ptr[i] = s1[i];
	len = ft_gnl_strlen(s1);
	i = -1;
	while (s2[++i])
		ptr[len + i] = s2[i];
	ptr[len + i] = '\0';
	free(s1);
	return (ptr);
}

size_t	ft_gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
