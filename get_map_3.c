/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <echrysta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:00:51 by echrysta          #+#    #+#             */
/*   Updated: 2022/10/11 20:06:15 by echrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	len_without_last_spaces(char *str)
{
	int	i;

	i = ft_strlen(str);
	while (str[i - 1] == ' ')
		i--;
	return (i);
}

static int	rm_space_helper(char **map, int spaces)
{
	int	line;
	int	i;
	int	row;

	line = 0;
	i = 0;
	while (map[line])
	{
		i = 0;
		row = 0;
		while (map[line][row++] == ' ')
			i++;
		if (i < spaces)
			spaces = i;
		line++;
	}
	return (spaces);
}

void	rm_spaces(char **map, float *x)
{
	int		line;
	int		spaces;
	char	*new_str;

	spaces = ft_strlen(map[0]);
	spaces = rm_space_helper(map, spaces);
	line = 0;
	while (map[line])
	{
		new_str = ft_substr(map[line], spaces,
				len_without_last_spaces(map[line] + spaces));
		free(map[line]);
		map[line] = new_str;
		line++;
	}
	*x -= spaces;
}

static size_t	max_len_fun(char **map)
{
	int		line;
	size_t	max_len;

	line = -1;
	max_len = ft_strlen(map[line + 1]);
	while (map[++line])
		if (ft_strlen(map[line]) > max_len)
			max_len = ft_strlen(map[line]);
	return (max_len);
}

void	add_spaces(char **map)
{
	int		line;
	size_t	max_len;
	char	*new_line;
	size_t	i;

	max_len = max_len_fun(map);
	line = 0;
	while (map[line])
	{
		new_line = (char *)malloc(sizeof(char) * (max_len + 1));
		new_line[max_len] = '\0';
		i = 0;
		while (map[line][i])
		{
			new_line[i] = map[line][i];
			i++;
		}
		while (i < max_len)
			new_line[i++] = ' ';
		free(map[line]);
		map[line] = new_line;
		line++;
	}
}
