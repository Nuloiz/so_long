NAME := so_long

CC := gcc

CFLAGS := -Wall -Wextra -Werror -g
# CFLAGS := $(CFLAGS) -fsanitize=address
SRC := so_long.c map/map.c map/map_check_line.c map/map_check_path.c map/map_fill.c map/map_tools.c map/map_lengths.c \
		start_screen.c moves.c movements.c free.c

SRC_DIR := src
OBJ_DIR := obj

MLX_DIR := tools/minilibx-linux
LIBS := -L/usr/X11/lib -lm -lX11 -lXext

INCLUDES := -I includes -I $(MLX_DIR) -I /usr/X11/include -I tools/libft

MLX := -L$(MLX_DIR) -lmlx

OBJ := $(SRC:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(MLX_DIR)
	@make -C tools/libft
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX) $(LIBS) tools/libft/libft.a

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c includes/
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/map
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)
	@echo "Compiling $<"

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(MLX_DIR) clean
	@make -C tools/libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C tools/libft fclean

re: fclean all

.PHONY: all clean fclean re

.PRECIOUS: $(OBJ_DIR)/%.o

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)
	@echo "Compiling $<"
