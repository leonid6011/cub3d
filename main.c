/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <echrysta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 18:57:02 by leroy             #+#    #+#             */
/*   Updated: 2022/10/11 18:35:24 by echrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	close_x(t_all *vars)
{
	ft_exit(vars, NULL);
	return (0);
}

static int	near_wall(t_all *vars, float x, float y)
{
	int	line;
	int	row;

	line = 0;
	while (line < vars->map_height)
	{
		row = 0;
		while (row < vars->map_width)
		{
			if ((float)row - STEP < x && x < (float)row + 1 + STEP
				&& (float)line - STEP < y && y < (float)line + 1 + STEP
				&& vars->map[line][row] == '1')
				return (1);
			row++;
		}
		line++;
	}
	return (0);
}

static void	key_hook_helper(int keycode, float radian, t_all *vars)
{
	float	x;
	float	y;

	x = vars->player.x;
	y = vars->player.y;
	if (keycode == 119 || keycode == 100 || keycode == 115 || keycode == 97)
	{
		x += sinf(radian) * STEP;
		y -= cosf(radian) * STEP;
		if (!near_wall(vars, x, y))
		{
			vars->player.x = x;
			vars->player.y = y;
		}
	}
	if (keycode == 119 || keycode == 100 || keycode == 115
		|| keycode == 97 || keycode == 65363 || keycode == 65361)
		raycasting(vars);
}

static int	key_hook(int keycode, t_all *vars)
{
	float	radian;
	int		move;

	move = 0;
	if (keycode == 0xff1b)
		ft_exit(vars, NULL);
	if (keycode == 65363)
		vars->player.dir += ROTATION;
	if (keycode == 65361)
		vars->player.dir -= ROTATION;
	if (keycode == 100)
		move = 90;
	if (keycode == 115)
		move = 180;
	if (keycode == 97)
		move = 270;
	vars->player.dir = (360 + vars->player.dir) % 360;
	radian = (vars->player.dir + move) * (M_PI / 180);
	key_hook_helper(keycode, radian, vars);
	return (0);
}

int	main(int argc, char **argv)
{
	t_all	vars;

	init_vars(&vars);
	if (argc != 2)
		ft_exit(&vars, "Wrong number of arguments!");
	parser(&vars, argv[1]);
	vars.mlx_ptr = mlx_init();
	if (!vars.mlx_ptr)
		ft_exit(&vars, "mlx_init failed!");
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, WIDTH, HEIGHT, "cub3D");
	if (!vars.win_ptr)
		ft_exit(&vars, "mlx_new_window failed!");
	init_images(&vars);
	raycasting(&vars);
	mlx_hook(vars.win_ptr, 17, 1L << 0, close_x, &vars);
	mlx_key_hook(vars.win_ptr, key_hook, &vars);
	mlx_loop(vars.mlx_ptr);
}
