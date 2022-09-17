/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leroy <leroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 18:57:02 by leroy             #+#    #+#             */
/*   Updated: 2022/09/17 18:40:40 by leroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_vars(t_all *vars)
{
	vars->mlx_ptr = NULL;
	vars->win_ptr = NULL;
	vars->no.path = NULL;
	vars->no.img_ptr = NULL;
	vars->so.path = NULL;
	vars->so.img_ptr = NULL;
	vars->we.path = NULL;
	vars->we.img_ptr = NULL;
	vars->ea.path = NULL;
	vars->ea.img_ptr = NULL;
	vars->f_color = -1;
	vars->c_color = -1;
	vars->map = NULL;
}

static int	close_x(t_all *vars)
{
	ft_exit(vars, NULL);
	return (0);
}

static int	key_hook(int keycode, t_all *vars)
{
	float	radian;
	
	if (keycode == 0xff1b)
		ft_exit(vars, NULL);
	if (keycode == 65363)
		vars->player.dir += ROTATION;
	if (keycode == 65361)
		vars->player.dir -= ROTATION;
	vars->player.dir = (360 + vars->player.dir) % 360;
	radian = vars->player.dir * (M_PI / 180);
	if (keycode == 119)
	{
		vars->player.x += sinf(radian) * STEP;
		vars->player.y -= cosf(radian) * STEP;
	}
	if (keycode == 115)
	{
		vars->player.x -= sinf(radian) * STEP;
		vars->player.y += cosf(radian) * STEP;
	}
	if (keycode == 97)
	{
		vars->player.x -= cosf(radian) * STEP;
		vars->player.y -= sinf(radian) * STEP;
	}
	if (keycode == 100)
	{
		vars->player.x += cosf(radian) * STEP;
		vars->player.y += sinf(radian) * STEP;
	}
	



	
	printf("player.x = %f\n", vars->player.x);
	printf("player.y = %f\n", vars->player.y);
	printf("player.dir = %d\n", vars->player.dir);
	printf("radian = %f\n", radian);
	return (0);
}

int	main(int argc, char **argv)
{
	t_all vars;
	
	if (argc != 2)
		ft_exit(&vars, "Wrong number of arguments!");
	init_vars(&vars);
	parser(&vars, argv[1]);
	vars.mlx_ptr = mlx_init();
	if (!vars.mlx_ptr)
		ft_exit(&vars, "mlx_init failed!");
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, WIDTH, HEIGHT, "cub3D");
	if (!vars.win_ptr)
		ft_exit(&vars, "mlx_new_window failed!");
	mlx_hook(vars.win_ptr, 17, 1L<<0, close_x, &vars);
	mlx_key_hook(vars.win_ptr, key_hook, &vars);
	mlx_loop(vars.mlx_ptr);
}