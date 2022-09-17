/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leroy <leroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:42:56 by leroy             #+#    #+#             */
/*   Updated: 2022/09/17 07:21:38 by leroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_mass(char **mass)
{
	int	i;

	if (!mass)
		return;
	i = 0;
	while (mass[i])
	{
		free(mass[i]);
		i++;
	}
	free(mass);
}

void	ft_exit(t_all *vars, char *message)
{
	(void)vars;

	if (vars->no.path)
		free(vars->no.path);
	if (vars->no.img_ptr)
		mlx_destroy_image(vars->mlx_ptr, vars->no.img_ptr);
	if (vars->so.path)
		free(vars->so.path);
	if (vars->so.img_ptr)
		mlx_destroy_image(vars->mlx_ptr, vars->so.img_ptr);
	if (vars->we.path)
		free(vars->we.path);
	if (vars->we.img_ptr)
		mlx_destroy_image(vars->mlx_ptr, vars->we.img_ptr);
	if (vars->ea.path)
		free(vars->ea.path);
	if (vars->ea.img_ptr)
		mlx_destroy_image(vars->mlx_ptr, vars->ea.img_ptr);
	if (vars->win_ptr)
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	if (vars->mlx_ptr)
		mlx_destroy_display(vars->mlx_ptr);
	if (vars->map)
		ft_free_mass(vars->map);
	if (message)
	{
		printf("Error\n");
		printf("%s\n", message);
	}
	if (errno != 0 && errno != 11)
		perror(NULL);
	exit(errno);
}