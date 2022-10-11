/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <echrysta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 06:02:26 by leroy             #+#    #+#             */
/*   Updated: 2022/10/11 16:13:58 by echrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	handle_color(t_all *vars, int fd, char *line)
{
	char	**rgb;
	int		red;
	int		green;
	int		blue;

	rgb = ft_split(line, ',');
	handle_color_check(rgb, fd, vars);
	red = ft_atoi(rgb[0]);
	green = ft_atoi(rgb[1]);
	blue = ft_atoi(rgb[2]);
	ft_free_mass(rgb);
	if (!(0 <= red && red <= 255 && 0 <= green
			&& green <= 255 && 0 <= blue && blue <= 255))
	{
		close(fd);
		ft_exit(vars, "Color not in range 0..255!");
	}
	return (trgb_to_int(0, red, green, blue));
}

static void	check_element_fatal(char *msg, int fd, char **elem, t_all *vars)
{
	close(fd);
	ft_free_mass(elem);
	ft_exit(vars, msg);
}

static void	check_element_help(t_all *vars, char **element, int fd)
{
	if (masslen(element) != 2)
		check_element_fatal("Element info != 2!", fd, element, vars);
	else if (!check_isprint(element[0]) || !check_isprint(element[1]))
		check_element_fatal("Element info is unprintable!", fd, element, vars);
	else if (!vars->no.path && ft_strcmp(element[0], "NO"))
		vars->no.path = ft_strdup(element[1]);
	else if (!vars->so.path && ft_strcmp(element[0], "SO"))
		vars->so.path = ft_strdup(element[1]);
	else if (!vars->we.path && ft_strcmp(element[0], "WE"))
		vars->we.path = ft_strdup(element[1]);
	else if (!vars->ea.path && ft_strcmp(element[0], "EA"))
		vars->ea.path = ft_strdup(element[1]);
	else if (vars->f_color == -1 && ft_strcmp(element[0], "F"))
		vars->f_color = handle_color(vars, fd, element[1]);
	else if (vars->c_color == -1 && ft_strcmp(element[0], "C"))
		vars->c_color = handle_color(vars, fd, element[1]);
	else
		check_element_fatal("Wrong element!", fd, element, vars);
}

static int	check_element(t_all *vars, char **element, int fd)
{
	check_element_help(vars, element, fd);
	if (vars->no.path && vars->so.path && vars->we.path
		&& vars->ea.path && vars->f_color != -1 && vars->c_color != -1)
	{	
		ft_free_mass(element);
		return (1);
	}
	ft_free_mass(element);
	return (0);
}

void	get_elements(t_all *vars, int fd)
{
	char	*line;
	char	**element;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			ft_exit(vars, "EOF in elements!");
		line = rm_last_n(line);
		if (ft_strcmp(line, ""))
		{
			free(line);
			continue ;
		}
		element = ft_split(line, ' ');
		free(line);
		if (check_element(vars, element, fd))
			break ;
	}
}
