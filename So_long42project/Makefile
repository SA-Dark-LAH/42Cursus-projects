# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saharraz <saharraz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/16 15:18:13 by saharraz          #+#    #+#              #
#    Updated: 2025/02/19 11:10:26 by saharraz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRCDIR = libft
SRCS =  so_long.c  checking_map.c alloc_parse_map.c \
        start_drawing.c animation.c error_printer.c\
    	get_heap_map.c utils.c \

LIBFTSRCS = $(wildcard $(SRCDIR)/*.c)

OBJS = ${SRCS:.c=.o}
OBJS2 = ${LIBFTSRCS:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3


all: ${NAME}

bonus : all

$(NAME): $(OBJS) $(OBJS2)
	$(CC) ${CFLAGS} $(OBJS) $(OBJS2) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	rm -rf ${OBJS} ${OBJS2}

fclean:
	rm -rf ${NAME}
	rm -rf ${OBJS} ${OBJS2}

re: fclean all
