/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <echrysta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:17:53 by leroy             #+#    #+#             */
/*   Updated: 2022/10/11 22:35:35 by echrysta         ###   ########.fr       */
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

# define WIDTH 900
# define HEIGHT 640
# define ROTATION 4
# define STEP 0.1	
# define FOV 60	

typedef struct s_img {
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	char	*path;
	int		width;
	int		height;
}	t_img;

typedef struct s_one_ray {
	float	x;
	float	x2;
	float	y;
	float	y2;
	float	cx;
	float	cy;
	float	c;
}	t_one_ray;

typedef struct s_param {
	int		wall_width;
	int		wall_height;
	t_img	img;
}	t_param;

typedef struct s_player
{
	float	x;
	float	y;
	int		dir;
}	t_player;

typedef struct s_all
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		no;
	t_img		so;
	t_img		we;
	t_img		ea;
	t_img		all_img;
	t_img		minimap_wall;
	t_img		minimap_player;
	int			f_color;
	int			c_color;
	char		**map;
	int			map_width;
	int			map_height;
	t_player	player;
	float		wall_dist;
	char		wall_side;
	float		wall_x;
}	t_all;

/* parser.c */
void	parser(t_all *vars, char *path);

/* get_elements.c */
void	get_elements(t_all *vars, int fd);

/* get_elements_2.c */
int		check_isprint(char *line);
int		check_isdigit(char *line);
void	handle_color_check(char **rgb, int fd, t_all *vars);

/* get_map.c */
void	get_map(t_all *vars, int fd);

/* get_map_2.c */
void	check_map(t_all *vars);
int		is_in(char c, char *str);

/* get_map_3.c */
void	rm_spaces(char **map, float *x);
void	add_spaces(char **map);

/* init.c */
void	init_vars(t_all *vars);
void	init_images(t_all *vars);

/* int_imgs.c*/
void	init_imgs(t_all *vars);

/* raycating.c */
void	raycasting(t_all *vars);
char	define_side(t_all *vars, float x, float y, float rad);

/* draw.c */
void	draw_line(t_all *vars, int begin, int end, int window_x);

/* draw_line_help.c */
void	draw_line_help(t_all *vars, t_param	*param);

/* is_wall.c */
int		is_wall(t_all *vars, float x, float y, float rad);

/* one_ray.c */
void	one_ray(t_all *vars, float rad);

/* utils */
void	ft_free_mass(char **mass);
char	*rm_last_n(char *line);
int		masslen(char **mass);
void	my_pixel_put(t_img img, int x, int y, unsigned int color);
int		get_color_from_img(t_img img, int x, int y);

/* ft_exit.c */
void	ft_exit(t_all *vars, char *message);

/* math.c */
float	grad_to_rad(int dir);
int		rad_to_grad(float rad);
int		trgb_to_int(int t, int r, int g, int b);

/* init_minimap_bonus.c */
void	init_minimap_player(t_all *vars);
void	init_minimap_wall(t_all *vars);
void	minimap(t_all *vars);

#endif