/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <echrysta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:42:56 by leroy             #+#    #+#             */
/*   Updated: 2022/10/11 19:40:58 by echrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_mass(char **mass)
{
	int	i;

	if (!mass)
		return ;
	i = 0;
	while (mass[i])
	{
		free(mass[i]);
		i++;
	}
	free(mass);
}

char	*rm_last_n(char *line)
{
	int		len;
	char	*ans;
	int		i;

	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		len--;
	ans = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len)
	{
		ans[i] = line[i];
		i++;
	}
	ans[i] = '\0';
	free(line);
	return (ans);
}

int	masslen(char **mass)
{
	int	i;

	i = 0;
	while (mass[i])
		i++;
	return (i);
}

void	my_pixel_put(t_img img, int x, int y, unsigned int color)
{
	char	*dst;

	dst = img.addr + y * img.size_line + x * (img.bits_per_pixel / 8);
	*(unsigned int *)dst = color;
}

int	get_color_from_img(t_img img, int x, int y)
{
	char	*dst;
	int		color;

	dst = img.addr + y * img.size_line + x * (img.bits_per_pixel / 8);
	color = *(unsigned int *)dst;
	return (color);
}
