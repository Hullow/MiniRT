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

# Libs
LIBFTDIR	= libft/
LIBFT		= $(LIBFTDIR)libft.a

MLXDIR		= mlx/
MLX			= $(MLXDIR)libmlx.a

# Header files
HEADSRC		= $(HEADDIR)$(NAME).h

# Source files
MAIN		= miniRT \
			rt_file_check \
			rt_scene_structs \
			rt_init_scene \
			rt_objects

SRC			= $(addprefix $(SRCDIR), $(addsuffix .c, $(MAIN)))

# Object files
OBJ			= $(addprefix $(OBJDIR), $(addsuffix .o, $(MAIN)))

# Default target
all: $(MLX) $(LIBFT) $(OBJDIR) $(NAME) 
	@echo "Compilation of $(NAME) done!"

# Build target
$(NAME): $(OBJ)
	@echo "Building $(NAME)..."
	@cp $(LIBFT) $(NAME)
	@cp $(MLX) $(NAME)
	@ar -rcs $@.a $(OBJ)
	@$(CC) $(OBJ) $(NAME).a $(LIBFT) $(MLXFLAGS) -o $(NAME)

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
