NAME = micro_rt

CC = cc

FLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -Lmlx -lmlx -lXext -lX11

SOURCES = $(wildcard ./main.c ./ch*/*.c ./test/*.c)

all: SOURCES

SOURCES:
	@make -C mlx/ all
	$(CC) $(FLAGS) -Imlx $(SOURCES) mlx/libmlx.a $(MLXFLAGS) -lm -o $(NAME)

clean:
	rm -rf $(NAME)
	@make -C mlx/ clean

.PHONY: all clean