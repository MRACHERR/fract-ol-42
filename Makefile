# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acherraq <acherraq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/08 17:11:54 by acherraq          #+#    #+#              #
#    Updated: 2024/06/25 20:32:55 by acherraq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SOURCES = fractol.c utils.c
OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX = -lmlx -framework OpenGL -framework AppKit
$(NAME) : $(OBJECTS) printf/libftprintf.a libft/libft.a minilibx_opengl_20191021/libmlx.a
	$(CC) $(CFLAGS) $(OBJECTS) -o fractol -Llibft -lft -Lprintf -lftprintf $(MLX) 

%.o : %.c fractol.h | libft printf libmlx
	$(CC) $(CFLAGS) -c $< -o $@ 

all: $(NAME)

libmlx:
	make -C minilibx_opengl_20191021

libft:
	make -C libft

printf:
	make -C printf

clean:
	rm -f $(OBJECTS)
	make -C libft clean
	make -C printf clean
	make -C minilibx_opengl_20191021 clean
	
fclean: clean
	rm -f $(NAME) 
	make -C libft fclean
	make -C printf fclean
	make -C minilibx_opengl_20191021 clean
	
re: fclean all

.PHONY: all bonus libft printf clean fclean re