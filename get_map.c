/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leroy <leroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 06:16:18 by leroy             #+#    #+#             */
/*   Updated: 2022/10/13 00:36:41 by leroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*get_line(int fd, t_all *vars)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			ft_exit(vars, "EOF before map!");
		line = rm_last_n(line);
		if (!ft_strcmp(line, ""))
			break ;
		free(line);
	}
	return (line);
}

static void	get_map_free(t_list	*first, t_list	*elem)
{
	while (first)
	{
		elem = first->next;
		free(first->content);
		free(first);
		first = elem;
	}
}

static t_list	*get_map_map(t_all *vars, t_list *first)
{
	int		i;
	t_list	*elem;

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
	return (elem);
}

void	get_map(t_all *vars, int fd)
{
	t_list	**list;
	t_list	*first;
	t_list	*elem;
	char	*line;

	line = get_line(fd, vars);
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
	elem = get_map_map(vars, first);
	get_map_free(first, elem);
	check_map(vars);
	rm_spaces(vars->map, &vars->player.x);
	add_spaces(vars->map);
	vars->map_width = ft_strlen(vars->map[0]);
	vars->map_height = masslen(vars->map);
}
