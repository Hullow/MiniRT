# Target executable/library name
NAME		= miniRT

# Compiler
CC			= cc

# Compiler flags
CFLAGS		= -Wall -Wextra -Werror
DFLAGS		= -g3
LIBFLAGS	= -L$(LIBFTDIR) -lft -L$(MLXDIR) -lmlx -lXext -lX11 -lm
INCLUDES	= -I$(INCLUDEDIR) -I$(LFTHEADER) -I$(MLXDIR)

# Folders
SRCDIR		= src/
OBJDIR		= obj/
INCLUDEDIR	= include/

LIBFTDIR	= $(INCLUDEDIR)libft/
MLXDIR		= $(INCLUDEDIR)mlx/

FILEDIR		= file_check/
SCENEDIR	= scene/
MATRIXDIR	= matrices/
TUPLEDIR	= tuples/
TRANSFDIR	= transforms/
UTILSDIR	= utils/
TESTDIR		= tests/

# Libs
LIBFT		= $(LIBFTDIR)libft.a
MLX			= $(MLXDIR)libmlx.a

# Header
HEADERS		= $(INCLUDEDIR)$(NAME).h $(LFTHEADER)*.h $(MLXDIR)mlx.h
LFTHEADER	= $(INCLUDEDIR)libft/header/

# Source files
MAIN		= miniRT

FILECHECK	= rt_file_check

SCENE		= rt_init_scene \
			rt_objects \
			rt_scene_structs

MATRIX		= rt_matrix_basic_ops \
			rt_matrix_general \
			rt_matrix_sub_det_cof

TUPLE		= rt_tuple_basic_ops \
			rt_tuple_general \
			rt_tuple_advanced_ops \
			rt_color_multiply

TRANSF		= rt_transform \
			rt_shearing

RAYSDIR		= rt_raycast \
			rt_intersections \

UTILS		= rt_utils

TESTS		= rt_test_tuple \
		#	rt_test_matrix \
		#	rt_test_transforms_and_rays

SRC			= $(addprefix $(SRCDIR), $(addsuffix .c, $(MAIN))) \
			$(addprefix $(SRCDIR)$(FILEDIR), $(addsuffix .c, $(FILECHECK))) \
			$(addprefix $(SRCDIR)$(SCENEDIR), $(addsuffix .c, $(SCENE))) \
			$(addprefix $(SRCDIR)$(MATRIXDIR), $(addsuffix .c, $(MATRIX))) \
			$(addprefix $(SRCDIR)$(TESTDIR), $(addsuffix .c, $(TESTS))) \
			$(addprefix $(SRCDIR)$(TUPLEDIR), $(addsuffix .c, $(TUPLE))) \
			$(addprefix $(SRCDIR)$(TRANSFDIR), $(addsuffix .c, $(TRANSF))) \
			$(addprefix $(SRCDIR)$(UTILSDIR), $(addsuffix .c, $(UTILS)))

# Object files
OBJ			= $(addprefix $(OBJDIR), $(addsuffix .o, $(MAIN))) \
			$(addprefix $(OBJDIR)$(FILEDIR), $(addsuffix .o, $(FILECHECK))) \
			$(addprefix $(OBJDIR)$(SCENEDIR), $(addsuffix .o, $(SCENE))) \
			$(addprefix $(OBJDIR)$(MATRIXDIR), $(addsuffix .o, $(MATRIX))) \
			$(addprefix $(OBJDIR)$(TESTDIR), $(addsuffix .o, $(TESTS))) \
			$(addprefix $(OBJDIR)$(TUPLEDIR), $(addsuffix .o, $(TUPLE))) \
			$(addprefix $(OBJDIR)$(TRANSFDIR), $(addsuffix .o, $(TRANSF))) \
			$(addprefix $(OBJDIR)$(UTILSDIR), $(addsuffix .o, $(UTILS)))


# Default target
all: $(MLX) $(LIBFT) $(OBJDIR) $(NAME)

# Build target
$(NAME): $(OBJ)
	@echo "Building $(NAME)..."
	@cp $(LIBFT) $(NAME)
	@cp $(MLX) $(NAME)
	$(CC) $(CFLAGS) $(DFLAGS) $(INCLUDES) $(OBJ) $(LIBFT) $(MLX) $(LIBFLAGS) -o $(NAME)

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
	mkdir -p $(OBJDIR)$(FILEDIR)
	mkdir -p $(OBJDIR)$(MATRIXDIR)
	mkdir -p $(OBJDIR)$(SCENEDIR)
	mkdir -p $(OBJDIR)$(TESTDIR)
	mkdir -p $(OBJDIR)$(TUPLEDIR)
	mkdir -p $(OBJDIR)$(TRANSFDIR)
	mkdir -p $(OBJDIR)$(UTILSDIR)
	@echo "Compiling $(NAME)..."

# Build object files
$(OBJDIR)%.o: $(SRCDIR)%.c | $(HEADERS)
	$(CC) $(CFLAGS) $(DFLAGS) $(INCLUDES) $(LIBFLAGS) -c $< -o $@

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