/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <echrysta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:47:04 by echrysta          #+#    #+#             */
/*   Updated: 2022/10/08 23:26:18 by echrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	grad_to_rad(int dir)
{
	return ((float)(dir * M_PI) / 180);
}

int	rad_to_grad(float rad)
{
	return ((rad * 180) / M_PI);
}

int	trgb_to_int(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
