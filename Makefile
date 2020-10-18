# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sassassi <sassassi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/05 20:15:19 by sassassi          #+#    #+#              #
#    Updated: 2020/10/18 12:25:47 by sassassi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
NAME = fdf
SRC_NAME = main.c ft_atoi_base.c
OBJ_NAME = $(SRC_NAME:%.c=%.o)
OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_NAME))
INC_DIR = ./includes/
INC = -I $(INC_DIR) 
LIB_DIR = ./libft/
SRC_DIR = src/
LIBRARIES = -lftprintf -L$(LIB_DIR) 
MLX_PATH = ./minilibx_macos/
MLXFLGS = -L$(MLX_PATH) -I$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit

LIBFT = $(LIB_DIR)libftprintf.a


all: $(NAME) 

$(NAME): $(OBJ)
	@make -C $(LIB_DIR)
	@make -C $(MLX_PATH)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L./$(LIB_DIR) -lftprintf  $(MLXFLGS)


$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $< $(INC)

cleanmlx:
	make -C $(MLX_PATH) clean

clean:
	@make -C $(LIB_DIR) clean
	@/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIB_DIR) fclean

re: fclean all
