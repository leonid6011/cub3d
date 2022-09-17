/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 19:36:49 by kcomic            #+#    #+#             */
/*   Updated: 2021/10/24 19:40:45 by kcomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *line, char sep)
{
	int	i;
	int	words;
	int	flag;

	i = 0;
	words = 0;
	flag = 0;
	while (line[i])
	{
		if ((flag == 0) && (line[i] != sep))
		{
			words++;
			flag = 1;
		}
		if ((flag == 1) && (line[i] == sep))
			flag = 0;
		i++;
	}
	return (words);
}

static char	*get_word(char	*ptr, char sep)
{
	int		i;
	int		len;
	char	*word;

	i = 0;
	while ((ptr[i] != sep) && (ptr[i] != '\0'))
		i++;
	len = i;
	word = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len)
	{
		word[i] = ptr[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	clean_mass(char **mass, int elem)
{
	int	i;

	i = 0;
	while (i <= elem)
	{
		free(mass[i]);
		i++;
	}
	free(mass);
}

static int	filling_mass(char const *s, char c, char **mass)
{
	int		i;
	int		flag;
	int		elem;

	i = 0;
	flag = 0;
	elem = 0;
	while (s[i])
	{
		if ((flag == 0) && (s[i] != c))
		{
			mass[elem] = get_word((char *)s + i, c);
			if (mass[elem] == NULL)
			{
				clean_mass(mass, elem);
				return (1);
			}
			elem++;
			flag = 1;
		}
		if ((flag == 1) && (s[i] == c))
			flag = 0;
		i++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**mass;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	mass = (char **)malloc(sizeof(char *) * (words + 1));
	if (filling_mass(s, c, mass))
		return (NULL);
	mass[words] = NULL;
	return (mass);
}
