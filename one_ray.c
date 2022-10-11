/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <echrysta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:40:54 by echrysta          #+#    #+#             */
/*   Updated: 2022/10/11 22:32:20 by echrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	one_ray_utils(t_all *vars, float x2, float y2, float rad)
{
	vars->wall_side = define_side(vars, x2, y2, rad);
	if (x2 == floor(x2))
		vars->wall_x = y2 - (int)y2;
	else if (y2 == floor(y2))
		vars->wall_x = x2 - (int)x2;
}

static float	correction_rad(float rad)
{
	if (rad < 0)
		rad = (float)(2 * M_PI) + rad;
	if (rad > (2 * M_PI))
		rad = grad_to_rad((rad_to_grad(rad) % 360));
	return (rad);
}

static void	first(float rad, t_one_ray *ray)
{
	if (0 < rad && rad < (float)M_PI)
	{
		ray->x2 = ceilf(ray->x);
		if (ray->x == ray->x2)
			ray->x2++;
		ray->cx = (ray->x2 - ray->x) / sinf(rad);
	}
	else if ((float)(M_PI) < rad)
	{
		ray->x2 = floorf(ray->x);
		if (ray->x == ray->x2)
			ray->x2--;
		ray->cx = (ray->x2 - ray->x) / sinf(rad);
	}
	else
		ray->cx = INFINITY;
}

static void	second(float rad, t_one_ray *ray)
{
	if (((3 * (float)M_PI) / 2) < rad || rad < (float)(M_PI / 2))
	{
		ray->y2 = floorf(ray->y);
		if (ray->y == ray->y2)
			ray->y2--;
		ray->cy = (ray->y - ray->y2) / cosf(rad);
	}
	else if ((float)(M_PI / 2) < rad && rad < (float)((3 * M_PI) / 2))
	{
		ray->y2 = ceilf(ray->y);
		if (ray->y == ray->y2)
			ray->y2++;
		ray->cy = (ray->y - ray->y2) / cosf(rad);
	}
	else
		ray->cy = INFINITY;
}

void	one_ray(t_all *vars, float rad)
{
	t_one_ray	ray;

	rad = correction_rad(rad);
	ray.x = vars->player.x;
	ray.y = vars->player.y;
	ray.c = 0;
	while (1)
	{
		ray.x2 = ray.x;
		first(rad, &ray);
		ray.y2 = ray.y;
		second(rad, &ray);
		if (ray.cy < ray.cx)
			ray.cx = ray.cy;
		ray.x2 = ray.x + sinf(rad) * ray.cx;
		ray.y2 = ray.y - cosf(rad) * ray.cx;
		ray.c += ray.cx;
		if (is_wall(vars, ray.x2, ray.y2, rad))
			break ;
		ray.x = ray.x2;
		ray.y = ray.y2;
	}
	vars->wall_dist = ray.c;
	one_ray_utils(vars, ray.x2, ray.y2, rad);
}
