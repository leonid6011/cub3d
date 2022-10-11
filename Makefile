# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: echrysta <echrysta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/13 20:59:29 by leroy             #+#    #+#              #
#    Updated: 2022/10/11 19:38:59 by echrysta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3D
HEADER	=	cub3d.h

CC		=	clang
CFLAGS	=	-Wall -Wextra -Werror
MFLAGS	=	-lmlx -lXext -lX11 -lm

LIBDIR	=	libft
LIBFT	=	libft.a

SRCS	=	draw.c\
			draw_line_help.c\
			gnl/get_next_line_utils.c\
			gnl/get_next_line.c\
			get_elements.c\
			get_elements_2.c\
			get_map.c\
			get_map_2.c\
			get_map_3.c\
			math.c\
			main.c\
			raycasting.c\
			ft_exit.c\
			parser.c\
			init.c\
			is_wall.c\
			init_imgs.c\
			one_ray.c\
			utils.c\
			init_minimap_bonus.c\
			#start_game.c

OBJS	=	$(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
OBJDIR	=	obj

.PHONY:	all clean fclean re bonus

all:	$(NAME)

$(NAME):	$(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBDIR)/$(LIBFT) $(MFLAGS) -o $(NAME)
	@echo "\n\033[0;32m$(NAME) compiled!\e[0m\n"

$(OBJS):	| $(OBJDIR)

$(OBJDIR):
	mkdir $@ $@/gnl

$(OBJDIR)/%.o:	%.c $(HEADER) gnl/get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make bonus -C $(LIBDIR)

clean:
	rm -rf $(OBJDIR)
	make fclean -C $(LIBDIR)/

fclean:	clean
	rm -f $(NAME)

re:	fclean all

bonus: $(NAME)