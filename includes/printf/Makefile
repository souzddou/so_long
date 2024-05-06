# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: souzddou <souzddou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 11:29:41 by souzddou          #+#    #+#              #
#    Updated: 2023/11/28 13:31:09 by souzddou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Wextra
RM = rm -f
SRC = ft_print_hex.c \
	  ft_print_ptr.c \
	  ft_print_str.c \
	  ft_print_unsigned.c \
	  ft_printf_char.c \
	  ft_printf.c \
	  ft_print_nbr.c \

OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)
	
clean:	
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)
re : fclean all

.PHONY: all clean fclean re 
