# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/15 17:31:52 by tcakir-y          #+#    #+#              #
#    Updated: 2025/10/15 17:31:52 by tcakir-y         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

PURPLE = \033[1;35m
CYAN = \033[1;36m
BLUE = \033[1;34m
PINK = \033[1;95m
RESET = \033[0m

CC = cc
FLAGS = -Wall -Wextra -Werror -g

INC = -I $(LIBFT) -I $(MLX) -I $(CUB3D_HEADERS)
LIBFT = inc/libft
MLX = inc/mlx_linux
CUB3D_HEADERS = inc/cub3d_headers
OBJ_DIR = obj/
SRC_DIR = src/

SRC_FILES = main.c\
			parse_file.c\
			utils_error.c\
			init_program.c\
			game_init.c \
			free.c \
			get_identifier.c \

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

all: submodules $(NAME)

submodules:
	@git submodule update --init --recursive

$(NAME): $(OBJ)
	@make -C $(MLX)
	@make -C $(LIBFT)
	@$(CC) $(FLAGS) $(OBJ) -L $(LIBFT) -lft -L $(MLX) -lmlx_Linux -lXext -lX11 -lm -lz -o $(NAME)
	@echo "$(PINK)All files compiled!$(RESET)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@echo "$(PURPLE)Compiling $<..$(RESET)"
	@$(CC) $(FLAGS) $(INC) -c $< -o $@

clean:
	@$(RM) -rf $(OBJ_DIR)
	@make clean -C $(LIBFT)
	@make clean -C $(MLX)
	@echo "$(BLUE)All object files removed.$(RESET)"
	
fclean: clean
	@$(RM) -f $(NAME)
	@$(RM) -f $(LIBFT)/libft.a
	@$(RM) -f $(MLX)/libmlx_Linux.a
	@echo "$(BLUE)All executable files removed.$(RESET)"

re: fclean all
	@echo "$(PINK)Object + exec files have been cleaned and rebuilt.$(RESET)"

.PHONY: all re clean fclean submodules
