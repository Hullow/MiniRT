# Target executable/library name
NAME		= miniRT

# Compiler
CC			= cc

# Compiler flags
CFLAGS		= -Wall -Wextra -Werror -lm
DFLAGS		= -g3
MLXFLAGS	= -L$(MLXDIR) -lmlx -I$(MLXDIR) -lXext -lX11

# Folders
SRCDIR		= src/
OBJDIR		= obj/
HEADDIR		= header/

FILEDIR		= file_check/
SCENEDIR	= scene/
MATRIXDIR	= matrices/
TUPLEDIR	= tuples/
UTILSDIR	= utils/

# Libs
LIBFTDIR	= libft/
LIBFT		= $(LIBFTDIR)libft.a

MLXDIR		= mlx/
MLX			= $(MLXDIR)libmlx.a

# Header files
HEADSRC		= $(HEADDIR)$(NAME).h

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

UTILS		= rt_utils

SRC			= $(addprefix $(SRCDIR), $(addsuffix .c, $(MAIN))) \
			$(addprefix $(SRCDIR)$(FILEDIR), $(addsuffix .c, $(FILECHECK))) \
			$(addprefix $(SRCDIR)$(SCENEDIR), $(addsuffix .c, $(SCENE))) \
			$(addprefix $(SRCDIR)$(MATRIXDIR), $(addsuffix .c, $(MATRIX))) \
			$(addprefix $(SRCDIR)$(TUPLEDIR), $(addsuffix .c, $(TUPLE))) \
			$(addprefix $(SRCDIR)$(UTILSDIR), $(addsuffix .c, $(UTILS)))

# Object files
OBJ			= $(addprefix $(OBJDIR), $(addsuffix .o, $(MAIN))) \
			$(addprefix $(OBJDIR)$(FILEDIR), $(addsuffix .o, $(FILECHECK))) \
			$(addprefix $(OBJDIR)$(SCENEDIR), $(addsuffix .o, $(SCENE))) \
			$(addprefix $(OBJDIR)$(MATRIXDIR), $(addsuffix .o, $(MATRIX))) \
			$(addprefix $(OBJDIR)$(TUPLEDIR), $(addsuffix .o, $(TUPLE))) \
			$(addprefix $(OBJDIR)$(UTILSDIR), $(addsuffix .o, $(UTILS)))

# Default target
all: $(MLX) $(LIBFT) $(OBJDIR) $(NAME) 

# Build target
$(NAME): $(OBJ)
	@echo "Building $(NAME)..."
	@cp $(LIBFT) $(NAME)
	@cp $(MLX) $(NAME)
	@ar -rcs $@.a $(OBJ)
	@$(CC) $(OBJ) $(NAME).a $(LIBFT) $(CFLAGS) $(MLXFLAGS) -o $(NAME)

# Build libft
$(LIBFT):
	@make -C $(LIBFTDIR) all

# Build MLX
$(MLX):
	@make -C $(MLXDIR) all

# Create object files directory
$(OBJDIR):
	@echo "Creating $(NAME) obj directories..."
	@mkdir -p $(OBJDIR)
	@mkdir -p $(OBJDIR)$(FILEDIR)
	@mkdir -p $(OBJDIR)$(SCENEDIR)
	@mkdir -p $(OBJDIR)$(MATRIXDIR)
	@mkdir -p $(OBJDIR)$(TUPLEDIR)
	@mkdir -p $(OBJDIR)$(UTILSDIR)
	@echo "Compiling $(NAME)..."

# Build object files
$(OBJDIR)%.o: $(SRCDIR)%.c | $(HEADSRC)
	@$(CC) $(CFLAGS) $(DFLAGS) -c $^ -o $@

# Clean compiled files
clean:
	@echo "Cleaning $(NAME) obj/ directory..."
	@rm -rf $(OBJDIR)
	@echo "Cleaning $(NAME).a..."
	@rm -rf $(NAME).a

# Full clean
fclean: clean
	@echo "Removing $(NAME)..."
	@rm -rf $(NAME)
	@make -C $(LIBFTDIR) fclean
	@make -C $(MLXDIR) clean

# Rebuild from scratch
re: fclean
	@echo "Reseting $(NAME)..."
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
