# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: souzddou <souzddou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/06 16:32:14 by souzddou          #+#    #+#              #
#    Updated: 2024/05/06 13:25:20 by souzddou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
MLXFLAG = -lmlx -lXext -lX11
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rc

SRC = so_long.c \
		init_images.c \
		includes/printf/ft_printf.c includes/printf/ft_print_nbr.c includes/printf/ft_print_str.c includes/printf/ft_printf_char.c includes/printf/ft_print_hex.c includes/printf/ft_print_ptr.c includes/printf/ft_print_unsigned.c\
		  includes/get_next_line/get_next_line.c \
			includes/get_next_line/get_next_line_utils.c \
			 key_hook.c\
			  destroy_images.c \
				utils_function.c \
				 draw_map.c \
				  design_wall.c \
					display_map.c \
						read_from_file.c \
						parsing.c\
						libft.c\
						libft2.c\
						parsing2.c\
						
				
						

OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) -o  $(NAME)  $(OBJS) $(MLXFLAG)
	@echo "\033[0;32m so_long is ready"

play : all
	@echo '\033[0;33m'"  - Playing the map... \n"$(NONE)
	@./so_long maps/map.ber
	
clean:	
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)
	
re : fclean all

.PHONY: all clean fclean re 
.SILENT: