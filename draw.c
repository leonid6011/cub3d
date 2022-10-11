/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <echrysta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:56:45 by echrysta          #+#    #+#             */
/*   Updated: 2022/10/11 19:37:08 by echrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_line(t_all *vars, int begin, int end, int window_x)
{
	int		wall_x;
	float	prop;
	int		color;
	int		i;
	t_param	param;

	draw_line_help(vars, &param);
	wall_x = (int)floorf(vars->wall_x * param.wall_width);
	prop = (float)param.wall_height / (end - begin);
	i = begin;
	while (i < end)
	{
		if (0 <= i && i < HEIGHT)
		{
			color = get_color_from_img(param.img,
					wall_x, (int)((i - begin) * prop));
			my_pixel_put(vars->all_img, window_x, i, color);
		}
		i++;
	}
}
