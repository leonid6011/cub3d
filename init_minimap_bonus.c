/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leroy <leroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:08:31 by echrysta          #+#    #+#             */
/*   Updated: 2022/10/12 04:37:43 by leroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_minimap_player(t_all *vars)
{
	int	i;
	int	j;
	int	color_p;
	int	wall;
	int	player;

	wall = WIDTH / 4 / vars->map_width;
	player = wall / 2;
	color_p = trgb_to_int(0, 80, 60, 30);
	i = 0;
	while (i < player)
	{
		j = 0;
		while (j < player)
		{
			my_pixel_put(vars->minimap_player, j, i, color_p);
			j++;
		}
		i++;
	}
}

void	init_minimap_wall(t_all *vars)
{
	int		i;
	int		j;
	int		color_w;
	int		wall;

	wall = WIDTH / 4 / vars->map_width;
	color_w = trgb_to_int(0, 200, 230, 255);
	i = 0;
	while (i < wall)
	{
		j = 0;
		while (j < wall)
		{
			my_pixel_put(vars->minimap_wall, j, i, color_w);
			j++;
		}
		i++;
	}
}

static void	view_line(t_all *vars, int wall)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	while (i < vars->wall_dist * wall)
	{
		x = vars->player.x * wall + sinf(grad_to_rad(vars->player.dir)) * i;
		y = vars->player.y * wall - cosf(grad_to_rad(vars->player.dir)) * i;
		mlx_pixel_put(vars->mlx_ptr, vars->win_ptr, x, y, 0x000000FF);
		i++;
	}
}

void	minimap(t_all *vars)
{
	int	x;
	int	y;
	int	wall;
	int	player;

	wall = WIDTH / 4 / vars->map_width;
	player = wall / 2;
	y = 0;
	while (y < vars->map_height)
	{
		x = 0;
		while (x < vars->map_width)
		{
			if (vars->map[y][x] == '1')
				mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,
					vars->minimap_wall.img_ptr, x * wall, y * wall);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,
		vars->minimap_player.img_ptr, vars->player.x * wall - player / 2,
		vars->player.y * wall - player / 2);
	view_line(vars, wall);
}
