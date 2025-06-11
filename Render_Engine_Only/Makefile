# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: francis <francis@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/02 14:02:17 by fallan            #+#    #+#              #
#    Updated: 2025/06/10 16:59:36 by fallan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Target executable/library name
NAME		= miniRT

# Compiler
CC			= cc

# Compiler flags
CFLAGS		= -Wall -Wextra -Werror
DFLAGS		= -O3 #-g3
INCLUDES	= -I$(SRCDIR) -I$(INCLUDEDIR) -I$(LFTHEADER) -I$(MLXDIR)
LIBDIRFLAGS	= -L$(LIBFTDIR) -L$(MLXDIR)
LIBFLAGS	= -lft -lmlx -lXext -lX11 -lm
UNAME_S		= $(shell uname -s)
ifeq ($(UNAME_S),Darwin) # If the system is macOS
        LIBDIRFLAGS += -L/opt/X11/lib
endif

# Folders
SRCDIR		= ./
OBJDIR		= ../Sources/obj/
INCLUDEDIR	= ../Sources/include/

LIBFTDIR	= $(INCLUDEDIR)libft/
MLXDIR		= $(INCLUDEDIR)mlx/

PARSEDIR	= ch0_parsing/
TUPLEDIR	= ch1_tuples/
COLORDIR	= ch2_colors/
MATRIXDIR	= ch3_matrices/
TRANSFDIR	= ch4_transformations/
RAYSDIR		= ch5_ray-sphere-intersections/
LIGHTDIR	= ch6_light-shadows/
SCENEDIR	= ch7_making-a-scene/
SHADOWDIR	= ch8_shadows/
PLANESDIR	= ch9_planes/
CYLINDERDIR	= ch13_cylinders/
TESTDIR		= test/

# Libs
LIBFT		= $(LIBFTDIR)libft.a
MLX			= $(MLXDIR)libmlx.a

# Header
HEADERS		= $(SRCDIR)$(NAME).h $(LFTHEADER)*.h $(MLXDIR)mlx.h
LFTHEADER	= $(INCLUDEDIR)libft/header/

# Source files
MAIN		= main

COLOR		= rt_colors_operations \
			rt_mlx \
			rt_mlx_free \
			rt_space

LIGHT		= rt_light \
			rt_normal_nonplanar \
			rt_phong

MATRIX		= rt_matrix_definition \
			rt_matrix_inversion \
			rt_matrix_operation

RAYS		= rt_hit \
			rt_intersection \
			rt_object \
			rt_ray \
			rt_ray_transform

SCENE		= rt_scene \
			rt_camera \
			rt_view_transform

SHADOW		= rt_shadow

TESTS		= test_parse
#			test \
#			print_objects \
#			test_input \
#			test_shape \
#			test_thread

TRANSF		= rt_rotation \
			rt_transform

TUPLE		= rt_magnitude \
			rt_tuples_definition \
			rt_tuples_operations \
			rt_vectors_operations

PARSE		= rt_assign_objects \
			rt_file_check \
			rt_scene_structs \
			rt_validate_input \
			rt_assign_view_elements \
			rt_init_scene \
			rt_utils

PLANE		= rt_planes

CYLINDER	= rt_cylinders \
			rt_caps_intersect

SRC			= $(addprefix $(SRCDIR), $(addsuffix .c, $(MAIN))) \
			$(addprefix $(SRCDIR)$(COLORDIR), $(addsuffix .c, $(COLOR))) \
			$(addprefix $(SRCDIR)$(LIGHTDIR), $(addsuffix .c, $(LIGHT))) \
			$(addprefix $(SRCDIR)$(MATRIXDIR), $(addsuffix .c, $(MATRIX))) \
			$(addprefix $(SRCDIR)$(RAYSDIR), $(addsuffix .c, $(RAYS))) \
			$(addprefix $(SRCDIR)$(SCENEDIR), $(addsuffix .c, $(SCENE))) \
			$(addprefix $(SRCDIR)$(SHADOWDIR), $(addsuffix .c, $(SHADOW))) \
			$(addprefix $(SRCDIR)$(TRANSFDIR), $(addsuffix .c, $(TRANSF))) \
			$(addprefix $(SRCDIR)$(TUPLEDIR), $(addsuffix .c, $(TUPLE))) \
			$(addprefix $(SRCDIR)$(PARSEDIR), $(addsuffix .c, $(PARSE))) \
			$(addprefix $(SRCDIR)$(PLANESDIR), $(addsuffix .c, $(PLANE))) \
			$(addprefix $(SRCDIR)$(CYLINDERDIR), $(addsuffix .c, $(CYLINDER))) \
			$(addprefix $(SRCDIR)$(TESTDIR), $(addsuffix .c, $(TESTS)))

# Object files
OBJ			= $(addprefix $(OBJDIR), $(addsuffix .o, $(MAIN))) \
			$(addprefix $(OBJDIR)$(COLORDIR), $(addsuffix .o, $(COLOR))) \
			$(addprefix $(OBJDIR)$(LIGHTDIR), $(addsuffix .o, $(LIGHT))) \
			$(addprefix $(OBJDIR)$(MATRIXDIR), $(addsuffix .o, $(MATRIX))) \
			$(addprefix $(OBJDIR)$(RAYSDIR), $(addsuffix .o, $(RAYS))) \
			$(addprefix $(OBJDIR)$(SCENEDIR), $(addsuffix .o, $(SCENE))) \
			$(addprefix $(OBJDIR)$(SHADOWDIR), $(addsuffix .o, $(SHADOW))) \
			$(addprefix $(OBJDIR)$(TRANSFDIR), $(addsuffix .o, $(TRANSF))) \
			$(addprefix $(OBJDIR)$(TUPLEDIR), $(addsuffix .o, $(TUPLE))) \
			$(addprefix $(OBJDIR)$(PARSEDIR), $(addsuffix .o, $(PARSE))) \
			$(addprefix $(OBJDIR)$(PLANESDIR), $(addsuffix .o, $(PLANE))) \
			$(addprefix $(OBJDIR)$(CYLINDERDIR), $(addsuffix .o, $(CYLINDER))) \
			$(addprefix $(OBJDIR)$(TESTDIR), $(addsuffix .o, $(TESTS)))

# Default target
all: $(MLX) $(LIBFT) $(OBJDIR) $(NAME)

# Build target
$(NAME): $(OBJ)
	@echo "Building $(NAME)..."
	@cp $(LIBFT) $(NAME)
	@cp $(MLX) $(NAME)
	$(CC) $(DFLAGS) $(INCLUDES) $(OBJ) $(LIBFT) $(MLX) $(LIBDIRFLAGS) $(LIBFLAGS) -o $(NAME)

# Build libft
$(LIBFT):
	@make -C $(LIBFTDIR) all

# Build MLX
$(MLX):
	@make -C $(MLXDIR) all

# Create object files directory
$(OBJDIR):
	@echo "Creating $(NAME) obj directories..."
	mkdir -p $(OBJDIR)
	mkdir -p $(OBJDIR)$(COLORDIR)
	mkdir -p $(OBJDIR)$(LIGHTDIR)
	mkdir -p $(OBJDIR)$(MATRIXDIR)
	mkdir -p $(OBJDIR)$(PARSEDIR)
	mkdir -p $(OBJDIR)$(RAYSDIR)
	mkdir -p $(OBJDIR)$(SCENEDIR)
	mkdir -p $(OBJDIR)$(SHADOWDIR)
	mkdir -p $(OBJDIR)$(TESTDIR)
	mkdir -p $(OBJDIR)$(TRANSFDIR)
	mkdir -p $(OBJDIR)$(TUPLEDIR)
	mkdir -p $(OBJDIR)$(PLANESDIR)
	mkdir -p $(OBJDIR)$(CYLINDERDIR)
	@echo "Compiling $(NAME)..."

# Build object files
$(OBJDIR)%.o: $(SRCDIR)%.c | $(HEADERS)
	$(CC) $(DFLAGS) $(INCLUDES) -c $< -o $@

# Clean compiled files
clean:
	@echo "Cleaning $(NAME) obj/ directory..."
	@rm -rf $(OBJDIR)

# Full clean
fclean: clean
	@echo "Removing $(NAME)..."
	@rm -rf $(NAME)
	@make -C $(LIBFTDIR) fclean
	@make -C $(MLXDIR) clean

# Rebuild from scratch
re: fclean
	@echo "Resetting $(NAME)..."
	@echo ""
	@$(MAKE) --no-print-directory all

# Phony targets
.PHONY: all clean fclean re

# $@ nom de la cible
# $< nom de la premiere dependance
# $ˆ liste des dependances
# $? liste des dependances mises a jour
# $* nom du fichier sans son extension
# $(wildcard *.c)