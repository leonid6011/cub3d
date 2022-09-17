/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leroy <leroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 02:31:39 by leroy             #+#    #+#             */
/*   Updated: 2022/09/17 08:03:03 by leroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int masslen(char **mass)
{
	int	i;

	i = 0;
	while (mass[i])
		i++;
	return (i);
}

static int	trgb_to_int(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static int		handle_color(char *line)
{
	char	**rgb;
	int		red;
	int		green;
	int		blue;

	rgb = ft_split(line, ',');
	red = ft_atoi(rgb[0]);
	green = ft_atoi(rgb[1]);
	blue = ft_atoi(rgb[2]);
	ft_free_mass(rgb);
	return (trgb_to_int(0, red, green, blue));
}

static int	check_element(t_all *vars, char **element, int fd)
{
	if (masslen(element) != 2)
	{
		close(fd);
		ft_free_mass(element);
		ft_exit(vars, "Element info != 2!");
	}
	else if (!vars->no.path && ft_strcmp(element[0], "NO"))
		vars->no.path = ft_strdup(element[1]);
	else if (!vars->so.path && ft_strcmp(element[0], "SO"))
		vars->so.path = ft_strdup(element[1]);
	else if (!vars->we.path && ft_strcmp(element[0], "WE"))
		vars->we.path = ft_strdup(element[1]);
	else if (!vars->ea.path && ft_strcmp(element[0], "EA"))
		vars->ea.path = ft_strdup(element[1]);
	else if (vars->f_color == -1 && ft_strcmp(element[0], "F"))
		vars->f_color = handle_color(element[1]);
	else if (vars->c_color == -1 && ft_strcmp(element[0], "C"))
		vars->c_color = handle_color(element[1]);
	else 
	{
		close(fd);
		ft_free_mass(element);
		ft_exit(vars, "Wrong element!");
	}
	if (vars->no.path && vars->so.path && vars->we.path
		&& vars->ea.path && vars->f_color != -1 && vars->c_color != -1)
		return (1);
	return (0);
}

static char	*rm_last_n(char *line)
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
			continue;
		}
		element = ft_split(line, ' ');
		free(line);
		if (check_element(vars, element, fd))
			break;
	}
}

void	get_map(t_all *vars, int fd)
{
	char	*line;
	t_list	**list;
	t_list	*first;
	int	i;
	t_list	*elem;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			ft_exit(vars, "EOF before map!");
		line = rm_last_n(line);
		if (!ft_strcmp(line, ""))
			break;
		free(line);
	}
	first = ft_lstnew(line);
	list = &first;
	line = get_next_line(fd);
	while (line)
	{
		line = rm_last_n(line);
		ft_lstadd_back(list, ft_lstnew(line));
		line = get_next_line(fd);
	}
	close(fd);
	vars->map = (char **)malloc(sizeof(char *) * (ft_lstsize(first) + 1));
	i = 0;
	elem = first;
	while (elem)
	{
		vars->map[i] = ft_strdup(elem->content);
		elem = elem->next;
		i++;
	}
	vars->map[i] = NULL;
	while (first)
	{
		elem = first->next;
		free(first->content);
		free(first);
		first = elem;
	}
}

int	is_in(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i + 1);
		i++;
	}
	return (0);
}

void	get_player(t_all *vars)
{
	int	line;
	int	row;

	line = 0;
	while (vars->map[line])
	{
		row = 0;
		while (vars->map[line][row])
		{
			vars->player.dir = is_in(vars->map[line][row], "NESW");
			if (vars->player.dir)
			{
				vars->player.x = row + 0.5;
				vars->player.y = line + 0.5;
				vars->player.dir = 90 * (vars->player.dir - 1);
				vars->map[line][row] = '0';
				return;
			}
			row++;
		}
		line++;
	}
	ft_exit(vars, "No player in map!");
}

void	parser(t_all *vars, char *path)
{
	int	fd;
	
	if (ft_strlen(path) < 5
		|| ft_strncmp(path + (ft_strlen(path) - 4), ".cub", 4) != 0)
		ft_exit(vars, "Not \".cub\" extension!");
	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_exit(vars, NULL);
	get_elements(vars, fd);
	get_map(vars, fd);
	//check_elements_and_map(vars)
	get_player(vars);



	for(int i = 0; vars->map[i]; i++)
		printf("%s\n", vars->map[i]);
	printf("player.x = %f\n", vars->player.x);
	printf("player.y = %f\n", vars->player.y);
	printf("player.dir = %d\n", vars->player.dir);
}