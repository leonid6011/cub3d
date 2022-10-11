/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <echrysta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:37:26 by echrysta          #+#    #+#             */
/*   Updated: 2022/10/11 14:37:55 by echrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_wall_firts_and_second(t_all *vars, float rad, float x, float y)
{
	int		x_map;
	int		y_map;

	if (0 <= rad && rad <= (float)(M_PI / 2))
	{
		x_map = (int)(floorf(x));
		if (y == floor(y))
			y_map = (int)(y - 1);
		else
			y_map = (int)(floorf(y));
		if (vars->map[y_map][x_map] == '1')
			return (1);
	}
	if ((float)(M_PI / 2) <= rad && rad <= (float)M_PI)
	{
		x_map = (int)(floorf(x));
		y_map = (int)(floorf(y));
		if (vars->map[y_map][x_map] == '1')
			return (1);
	}
	return (0);
}

static int	is_wall_third(t_all *vars, float rad, float x, float y)
{
	int		x_map;
	int		y_map;

	if ((float)M_PI <= rad && rad <= (float)((3 * M_PI) / 2))
	{
		y_map = (int)(floorf(y));
		if (x == floor(x))
			x_map = (int)(x - 1);
		else
			x_map = (int)(floorf(x));
		if (vars->map[y_map][x_map] == '1')
			return (1);
	}
	return (0);
}

static int	is_wall_four(t_all *vars, float rad, float x, float y)
{
	int		x_map;
	int		y_map;

	if ((float)((3 * M_PI) / 2) <= rad)
	{
		if (x == floor(x))
			x_map = (int)(x - 1);
		else
			x_map = (int)(floorf(x));
		if (y == floor(y))
			y_map = (int)(y - 1);
		else
			y_map = (int)(floorf(y));
		if (vars->map[y_map][x_map] == '1')
			return (1);
	}
	return (0);
}

int	is_wall(t_all *vars, float x, float y, float rad)
{
	if (is_wall_firts_and_second(vars, rad, x, y))
		return (1);
	if (is_wall_third(vars, rad, x, y))
		return (1);
	if (is_wall_four(vars, rad, x, y))
		return (1);
	return (0);
}
