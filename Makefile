# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anel-men <anel-men@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/28 18:02:56 by anel-men          #+#    #+#              #
#    Updated: 2024/11/02 17:55:26 by anel-men         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX = -lmlx -framework OpenGL -framework AppKit

SRCS = fractol.c u0.c
OBJS = $(SRCS:.c=.o)

NAME = fractol

all: $(NAME)



%.o: %.c libft.h
	$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean