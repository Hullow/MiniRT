# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: francis <francis@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/04 18:04:50 by fallan            #+#    #+#              #
#    Updated: 2024/04/15 17:19:49 by francis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../libmlx.a

SRC = mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c

OBJ1 = $(SRC:.c=.o)

OBJ = $(OBJ1:.m=.o)

CFLAGS+=-O2 -DGL_SILENCE_DEPRECATION

all: $(NAME)

$(NAME):	$(OBJ)
	ar -r $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ) *~
	rm -f mlx_app

fclean: clean
	rm -f $(NAME)

re: clean all
