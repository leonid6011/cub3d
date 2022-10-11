/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <echrysta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 22:54:59 by echrysta          #+#    #+#             */
/*   Updated: 2022/10/11 13:35:36 by echrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_exit_helper(t_all *vars)
{	
	if (vars->no.img_ptr)
		mlx_destroy_image(vars->mlx_ptr, vars->no.img_ptr);
	if (vars->so.img_ptr)
		mlx_destroy_image(vars->mlx_ptr, vars->so.img_ptr);
	if (vars->we.img_ptr)
		mlx_destroy_image(vars->mlx_ptr, vars->we.img_ptr);
	if (vars->ea.img_ptr)
		mlx_destroy_image(vars->mlx_ptr, vars->ea.img_ptr);
	if (vars->all_img.img_ptr)
		mlx_destroy_image(vars->mlx_ptr, vars->all_img.img_ptr);
	if (vars->minimap_wall.img_ptr)
		mlx_destroy_image(vars->mlx_ptr, vars->minimap_wall.img_ptr);
	if (vars->minimap_player.img_ptr)
		mlx_destroy_image(vars->mlx_ptr, vars->minimap_player.img_ptr);
	if (vars->win_ptr)
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	if (vars->mlx_ptr)
		mlx_destroy_display(vars->mlx_ptr);
	if (vars->map)
		ft_free_mass(vars->map);
}

void	ft_exit(t_all *vars, char *message)
{
	(void)vars;
	if (vars->no.path)
		free(vars->no.path);
	if (vars->so.path)
		free(vars->so.path);
	if (vars->we.path)
		free(vars->we.path);
	if (vars->ea.path)
		free(vars->ea.path);
	ft_exit_helper(vars);
	if (message)
	{
		printf("Error\n");
		printf("%s\n", message);
	}
	if (errno != 0 && errno != 11)
		perror(NULL);
	exit(errno);
}
