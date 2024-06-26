# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acherraq <acherraq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/08 17:11:54 by acherraq          #+#    #+#              #
#    Updated: 2024/06/26 18:38:19 by acherraq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SOURCES = fractol.c utils.c julia.c hooks.c mandelbrot.c utils_2.c
OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX = -lmlx -framework OpenGL -framework AppKit
$(NAME) : $(OBJECTS) printf/libftprintf.a libft/libft.a
	$(CC) $(CFLAGS) $(OBJECTS) -o fractol -Llibft -lft -Lprintf -lftprintf $(MLX) 

%.o : %.c fractol.h | libft printf 
	$(CC) $(CFLAGS) -c $< -o $@ 

all: $(NAME)


libft:
	make -C libft

printf:
	make -C printf

clean:
	rm -f $(OBJECTS)
	make -C libft clean
	make -C printf clean
	
fclean: clean
	rm -f $(NAME) 
	make -C libft fclean
	make -C printf fclean
	
re: fclean all

.PHONY: all bonus libft printf clean fclean re