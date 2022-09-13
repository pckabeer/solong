# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpanikka <kpanikka@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/30 13:37:19 by kpanikka          #+#    #+#              #
#    Updated: 2022/09/13 10:56:27 by kpanikka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	solong.c map.c image.c ft_itoa.c player.c util.c \
					ft_putnbr_fd.c

OBJS			= $(SRCS:.c=.o)
CC				= gcc
RM				= rm -f
CFLAGS			= -g -Wall -Wextra -Werror -I.

NAME			= solong

MLX				= minilibx/libmlx.a

all:			$(NAME)

$(MLX)			: 
					make -C minilibx

$(NAME):		$(OBJS) $(MLX)
				cc $(MLX) -framework OpenGL -framework AppKit  $(OBJS) -o $(NAME)

clean:
				$(RM) $(OBJS) 
				make -C minilibx clean

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re