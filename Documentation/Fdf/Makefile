# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fallan <fallan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/19 20:06:01 by fallan            #+#    #+#              #
#    Updated: 2024/05/07 15:43:18 by fallan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = fdf.c debugging_utils.c input_handling.c input_utils.c graphing_utils.c projection_utils.c drawing.c drawing_utils.c utils.c $\
./lib/get_next_line/src/get_next_line.c ./lib/get_next_line/src/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

MLX = ./lib/libmlx.a

LIBFT = ./lib/libft.a

FT_PRINTF = ./lib/libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

sanitize: CFLAGS += -fsanitize=address -g3
sanitize: re

debug: CFLAGS += -g
debug: re

$(MLX):
	make -C ./lib/minilibx/ -f Makefile 

$(LIBFT):
	make -C ./lib/libft/ -f Makefile
	
$(FT_PRINTF):
	make -C ./lib/ft_printf/ -f Makefile

%.o : %.c
	$(CC) $(CFLAGS) -Ilib -c $< -o $@

$(NAME): $(OBJ) $(MLX) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJ) -L./lib -lft -lftprintf -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f $(OBJ)
	for dir in ./lib/minilibx/ ./lib/libft/ ./lib/ft_printf/; do \
		$(MAKE) -C $$dir clean; \
	done

fclean: clean
	rm -f $(NAME) $(LIBFT) $(FT_PRINTF) $(MLX)

re: fclean all

.PHONY: all sanitize clean fclean re