/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elements_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <echrysta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 22:49:34 by echrysta          #+#    #+#             */
/*   Updated: 2022/10/11 16:14:11 by echrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_isprint(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_isprint(line[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_isdigit(char	*line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]))
			return (0);
		i++;
	}
	return (1);
}

void	handle_color_check(char **rgb, int fd, t_all *vars)
{
	if (masslen(rgb) != 3)
	{
		close(fd);
		ft_free_mass(rgb);
		ft_exit(vars, "Color len != 3!");
	}
	if (!check_isdigit(rgb[0]) || !check_isdigit(rgb[1])
		|| !check_isdigit(rgb[2]))
	{
		close(fd);
		ft_free_mass(rgb);
		ft_exit(vars, "Color is not digit!");
	}
}
