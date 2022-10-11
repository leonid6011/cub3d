/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <echrysta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 02:49:47 by leroy             #+#    #+#             */
/*   Updated: 2022/10/11 22:36:49 by echrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	define_side_second(float x, float y, float rad)
{
	if ((float)M_PI < rad && rad < (float)((3 * M_PI) / 2))
	{
		if (roundf(x) - 0.0000001 < x && x < roundf(x) + 0.0000001)
			return ('e');
		else if (roundf(y) - 0.0000001 < y && y < roundf(y) + 0.0000001)
			return ('n');
	}
	else if ((float)((3 * M_PI) / 2) < rad)
	{
		if (roundf(y) - 0.0000001 < y && y < roundf(y) + 0.0000001)
			return ('s');
		else if (roundf(x) - 0.0000001 < x && x < roundf(x) + 0.0000001)
			return ('e');
	}
	return (0);
}

static char	define_side_first(float x, float y, float rad)
{
	if (0 < rad && rad < (float)(M_PI / 2))
	{
		if (roundf(x) - 0.0000001 < x && x < roundf(x) + 0.0000001)
			return ('w');
		else if (roundf(y) - 0.0000001 < y && y < roundf(y) + 0.0000001)
			return ('s');
	}
	else if ((float)(M_PI / 2) < rad && rad < (float)M_PI)
	{
		if (roundf(y) - 0.0000001 < y && y < roundf(y) + 0.0000001)
			return ('n');
		else if (roundf(x) - 0.0000001 < x && x < roundf(x) + 0.0000001)
			return ('w');
	}
	return (0);
}

char	define_side(t_all *vars, float x, float y, float rad)
{
	char	return_val;

	return_val = 0;
	return_val = define_side_first(x, y, rad);
	if (return_val)
		return (return_val);
	return_val = define_side_second(x, y, rad);
	if (return_val)
		return (return_val);
	if (rad == 0)
		return ('s');
	if (rad == (float)(M_PI / 2))
		return ('w');
	if (rad == (float)M_PI)
		return ('n');
	if (rad == (float)((3 * M_PI) / 2))
		return ('e');
	ft_exit(vars, "define_side can't define wall =(");
	return (0);
}

static void	view(t_all *vars, int x, float delta)
{
	int		end;
	int		begin;
	int		h_line;

	one_ray(vars, delta);
	vars->wall_dist *= cosf(grad_to_rad(vars->player.dir) - delta);
	h_line = (float)HEIGHT / (float)vars->wall_dist;
	begin = HEIGHT / 2 - h_line / 2;
	end = HEIGHT / 2 + h_line / 2;
	draw_line(vars, begin, end, x);
}

void	raycasting(t_all *vars)
{
	int		i;
	float	delta;
	float	delta_plus;

	i = 0;
	delta = grad_to_rad(vars->player.dir);
	delta_plus = ((FOV * M_PI) / (180 * WIDTH));
	delta = delta - grad_to_rad(FOV / 2);
	init_imgs(vars);
	while (i < WIDTH)
	{
		view(vars, i, delta);
		delta += delta_plus;
		if (delta > 2 * M_PI)
			delta -= 2 * M_PI;
		i++;
	}
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,
		vars->all_img.img_ptr, 0, 0);
	one_ray(vars, grad_to_rad(vars->player.dir));
	minimap(vars);
}
