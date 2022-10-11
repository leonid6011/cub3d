/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <echrysta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:08:38 by echrysta          #+#    #+#             */
/*   Updated: 2022/10/11 20:05:38 by echrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_c(t_all *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT / 2)
	{
		j = 0;
		while (j < WIDTH)
		{
			my_pixel_put(vars->all_img, j, i, vars->c_color);
			j++;
		}
		i++;
	}
}

static void	init_f(t_all *vars)
{
	int	i;
	int	j;

	i = HEIGHT / 2;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			my_pixel_put(vars->all_img, j, i, vars->f_color);
			j++;
		}
		i++;
	}
}

static void	init_all_img(t_all *vars)
{
	init_c(vars);
	init_f(vars);
}

void	init_imgs(t_all *vars)
{
	init_all_img(vars);
	init_minimap_wall(vars);
	init_minimap_player(vars);
}
