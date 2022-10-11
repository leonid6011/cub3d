/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <echrysta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:28:29 by echrysta          #+#    #+#             */
/*   Updated: 2022/10/11 19:53:36 by echrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_vars(t_all *vars)
{
	vars->mlx_ptr = NULL;
	vars->win_ptr = NULL;
	vars->no.path = NULL;
	vars->so.path = NULL;
	vars->we.path = NULL;
	vars->ea.path = NULL;
	vars->no.img_ptr = NULL;
	vars->so.img_ptr = NULL;
	vars->we.img_ptr = NULL;
	vars->ea.img_ptr = NULL;
	vars->all_img.img_ptr = NULL;
	vars->minimap_wall.img_ptr = NULL;
	vars->minimap_player.img_ptr = NULL;
	vars->f_color = -1;
	vars->c_color = -1;
	vars->map = NULL;
}

static void	init_images_helper(t_all *vars)
{
	int	wall;
	int	player;

	wall = WIDTH / 4 / vars->map_width;
	player = wall / 2;
	vars->no.img_ptr = mlx_xpm_file_to_image(vars->mlx_ptr,
			vars->no.path, &vars->no.width, &vars->no.height);
	vars->so.img_ptr = mlx_xpm_file_to_image(vars->mlx_ptr,
			vars->so.path, &vars->so.width, &vars->so.height);
	vars->we.img_ptr = mlx_xpm_file_to_image(vars->mlx_ptr,
			vars->we.path, &vars->we.width, &vars->we.height);
	vars->ea.img_ptr = mlx_xpm_file_to_image(vars->mlx_ptr,
			vars->ea.path, &vars->ea.width, &vars->ea.height);
	vars->all_img.img_ptr = mlx_new_image(vars->mlx_ptr, WIDTH, HEIGHT);
	vars->minimap_wall.img_ptr = mlx_new_image(vars->mlx_ptr, wall, wall);
	vars->minimap_player.img_ptr = mlx_new_image(vars->mlx_ptr, player, player);
}

void	init_images(t_all *vars)
{
	init_images_helper(vars);
	if (!vars->no.img_ptr || !vars->so.img_ptr
		|| !vars->we.img_ptr || !vars->ea.img_ptr
		|| !vars->all_img.img_ptr || !vars->minimap_wall.img_ptr
		|| !vars->minimap_player.img_ptr)
		ft_exit(vars, "init_images failed!");
	vars->no.addr = mlx_get_data_addr(vars->no.img_ptr,
			&vars->no.bits_per_pixel, &vars->no.size_line, &vars->no.endian);
	vars->so.addr = mlx_get_data_addr(vars->so.img_ptr,
			&vars->so.bits_per_pixel, &vars->so.size_line, &vars->so.endian);
	vars->we.addr = mlx_get_data_addr(vars->we.img_ptr,
			&vars->we.bits_per_pixel, &vars->we.size_line, &vars->we.endian);
	vars->ea.addr = mlx_get_data_addr(vars->ea.img_ptr,
			&vars->ea.bits_per_pixel, &vars->ea.size_line, &vars->ea.endian);
	vars->all_img.addr = mlx_get_data_addr(vars->all_img.img_ptr,
			&vars->all_img.bits_per_pixel, &vars->all_img.size_line,
			&vars->all_img.endian);
	vars->minimap_wall.addr = mlx_get_data_addr(vars->minimap_wall.img_ptr,
			&vars->minimap_wall.bits_per_pixel,
			&vars->minimap_wall.size_line, &vars->minimap_wall.endian);
	vars->minimap_player.addr = mlx_get_data_addr(vars->minimap_player.img_ptr,
			&vars->minimap_player.bits_per_pixel,
			&vars->minimap_player.size_line, &vars->minimap_player.endian);
}
