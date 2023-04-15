# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-kora <mel-kora@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/20 16:48:53 by mel-kora          #+#    #+#              #
#    Updated: 2022/05/31 22:37:45 by mel-kora         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAP_SRCS	=	map_generator.c\
				Libft/ft_putendl_fd.c\
				Libft/ft_strlen.c\
				Libft/ft_atoi.c\
				Libft/ft_error.c


MAP_OBJS	=	${MAP_SRCS:.c=.o}

MAP_NAME	=	map_maker

CC			=	gcc

RM			=	rm -rf

CFLAGS		=	-Wall -Werror -Wextra #-g -fsanitize=address

.c.o:
			${CC} ${CFLAGS} -c $< -o $@

all:		${MAP_NAME}

${MAP_NAME}:${MAP_OBJS}
			${CC} ${CFLAGS} ${MAP_OBJS} -o ${MAP_NAME}
			############################################################################################################
			##########                                                                                        ##########
			########## Run "./map_maker "10CEMP" 20 30 10 new_map.ber" to make a 20 * 30 map with 10 monsters ##########
			##########                                                                                        ##########
			############################################################################################################

maze:
	make -C ./maze_generator/ && mv maze_generator/maze_maker .

clean:
			${RM} ${OBJS} ${MAP_OBJS}
			make -C ./maze_generator/ clean

fclean:		clean
			${RM} ${NAME} ${MAP_NAME}
			make -C ./maze_generator/ fclean

re:			fclean all
			make -C ./maze_generator/ re

.PHONY:		all clean fclean re
