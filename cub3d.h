/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leroy <leroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:17:53 by leroy             #+#    #+#             */
/*   Updated: 2022/09/17 18:42:16 by leroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>

# include "libft/libft.h"
# include "gnl/get_next_line.h"

# define WIDTH 600
# define HEIGHT 400
# define RADIAN 180 / M_PI
# define ROTATION 1
# define STEP 0.1

typedef struct s_img
{
	void	*img_ptr;
	char	*path;
	int		width;
	int		height;
}	t_img;

typedef struct s_player
{
	float	x;
	float	y;
	int	dir; //направление взгляда в грудусах	
}	t_player;

typedef struct s_all
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	no;
	t_img	so;
	t_img	we;
	t_img	ea;
	int		f_color;
	int		c_color;
	char	**map;
	t_player	player;
}	t_all;

void	parser(t_all *vars, char *path);

void	ft_exit(t_all *vars, char *message);
void	ft_free_mass(char **mass);

#endif