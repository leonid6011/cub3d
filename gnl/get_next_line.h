/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 04:39:41 by marvin            #+#    #+#             */
/*   Updated: 2021/12/29 04:39:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 21
# endif

char	*get_next_line(int fd);

char	*ft_gnl_strchr(const char *s, int c);
char	*ft_gnl_strjoin(char *s1, char const *s2);
size_t	ft_gnl_strlen(const char *s);

#endif