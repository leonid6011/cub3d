/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leroy <leroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 23:03:11 by echrysta          #+#    #+#             */
/*   Updated: 2022/10/13 02:16:36 by leroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_in(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i + 1);
		i++;
	}
	return (0);
}

static void	check_map_fatal(t_all *vars, size_t	row, int line)
{
	if (!is_in(vars->map[line][row], "NEWS 01"))
		ft_exit(vars, "Invalid symbol in map!");
	if (is_in(vars->map[line][row], "NEWS0") &&
		(!line || line == masslen(vars->map) - 1
		|| !row || row == ft_strlen(vars->map[line] - 1)))
		ft_exit(vars, "Map is not closed!");
	else if (is_in(vars->map[line][row], "NEWS0") &&
		(ft_strlen(vars->map[line - 1]) < row + 1 ||
		ft_strlen(vars->map[line + 1]) < row + 1))
		ft_exit(vars, "Map is not closed!");
	else if (is_in(vars->map[line][row], "NEWS0") &&
		(vars->map[line - 1][row] == ' ' || vars->map[line + 1][row] == ' ' ||
		vars->map[line][row - 1] == ' ' || vars->map[line][row + 1] == ' '))
		ft_exit(vars, "Map is not closed!");
}

static void	player_init(t_all *vars, int line, size_t row)
{
	vars->player.x = row + 0.5;
	vars->player.y = line + 0.5;
	vars->player.dir = 90 * (is_in(vars->map[line][row], "NESW") - 1);
	vars->map[line][row] = '0';
}

void	check_map(t_all *vars)
{
	int		line;
	size_t	row;
	int		flag;

	flag = 0;
	line = 0;
	while (vars->map[line])
	{
		row = 0;
		while (vars->map[line][row])
		{
			check_map_fatal(vars, row, line);
			if (is_in(vars->map[line][row], "NEWS"))
			{
				if (flag)
					ft_exit(vars, "Player position > 1!");
				flag = 1;
				player_init(vars, line, row);
			}
			row++;
		}
		line++;
	}
	if (!flag)
		ft_exit(vars, "Player has no position!");
}
