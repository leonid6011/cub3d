# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leroy <leroy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/13 20:59:29 by leroy             #+#    #+#              #
#    Updated: 2022/09/17 17:09:12 by leroy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3D
HEADER	=	cub3d.h

CC		=	clang
CFLAGS	=	-Wall -Wextra -Werror
MFLAGS	=	-lmlx -lXext -lX11 -lm

LIBDIR	=	libft
LIBFT	=	libft.a

SRCS	=	gnl/get_next_line_utils.c\
			gnl/get_next_line.c\
			main.c\
			parser.c\
			utils.c

OBJS	=	$(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
OBJDIR	=	obj

.PHONY:	all clean fclean re bonus

all:	$(NAME)

$(NAME):	$(OBJS)
	make bonus -C $(LIBDIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBDIR)/$(LIBFT) $(MFLAGS) -o $(NAME)
	@echo "\n\033[0;32m$(NAME) compiled!\e[0m\n"

$(OBJS):	| $(OBJDIR)

$(OBJDIR):
	mkdir $@ $@/gnl

$(OBJDIR)/%.o:	%.c $(HEADER) gnl/get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)
	make fclean -C $(LIBDIR)/

fclean:	clean
	rm -f $(NAME)

re:	fclean all

bonus: $(NAME)