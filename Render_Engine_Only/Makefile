NAME = micro_rt

CC = cc

UNAME_S = $(shell uname -s)
FLAGS = -Wall -Wextra -Werror -g
LIBFLAGS = -Lmlx
ifeq ($(UNAME_S),Darwin) # If the system is macOS (Darwin, add the Library path for X11)
	LIBFLAGS += -L/opt/X11/lib
endif

MLXFLAGS = -lmlx -lXext -lX11

SOURCES = $(wildcard ./main.c ./ch*/*.c ./test/*.c)

all: SOURCES

SOURCES:
	@make -C mlx/ all
	$(CC) $(FLAGS) -Imlx $(SOURCES) mlx/libmlx.a $(LIBFLAGS) $(MLXFLAGS) -lm -o $(NAME)

clean:
	rm -rf $(NAME)
	@make -C mlx/ clean

.PHONY: all clean