/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_help.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <echrysta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:37:16 by echrysta          #+#    #+#             */
/*   Updated: 2022/10/11 19:40:18 by echrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_line_s(t_all *vars, t_param *param)
{
	param->wall_width = vars->so.width;
	param->wall_height = vars->so.height;
	param->img = vars->so;
}

static void	draw_line_n(t_all *vars, t_param *param)
{
	param->wall_width = vars->no.width;
	param->wall_height = vars->no.height;
	param->img = vars->no;
}

static void	draw_line_w(t_all *vars, t_param *param)
{
	param->wall_width = vars->we.width;
	param->wall_height = vars->we.height;
	param->img = vars->we;
}

static void	draw_line_e(t_all *vars, t_param *param)
{
	param->wall_width = vars->ea.width;
	param->wall_height = vars->ea.height;
	param->img = vars->ea;
}

void	draw_line_help(t_all *vars, t_param	*param)
{
	if (vars->wall_side == 's')
		draw_line_s(vars, param);
	if (vars->wall_side == 'n')
		draw_line_n(vars, param);
	if (vars->wall_side == 'w')
		draw_line_w(vars, param);
	if (vars->wall_side == 'e')
		draw_line_e(vars, param);
}
