# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: souzddou <souzddou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/06 16:32:14 by souzddou          #+#    #+#              #
#    Updated: 2024/03/11 00:51:20 by souzddou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
MLXFLAG = -lmlx -lXext -lX11
CFLAGS = -Wall -Wextra -Werror
# MLXFLAG = -L./minilibx-linux -lm -lmlx -lXext -lX11
RM = rm -f
AR = ar rc

SRC = so_long.c \
		init_images.c \
		  includes/get_next_line/get_next_line.c \
			includes/get_next_line/get_next_line_utils.c \
			 key_hook.c\
			  destroy_images.c \
				utils_function.c \
				 draw_map.c \
				  design_wall.c \
					display_map.c \
						read_from_file.c \
						

OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) -o  $(NAME)  $(OBJS) $(MLXFLAG)
	
clean:	
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)
test:
	valgrind ./so_long
re : fclean all

.PHONY: all clean fclean re 