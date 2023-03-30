# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozozdemi <ozozdemi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 15:30:27 by ozozdemi          #+#    #+#              #
#    Updated: 2023/03/30 15:14:04 by ozozdemi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		so_long
CC =		cc
CFLAGS =	-Wall -Werror -Wextra -g3
LIBFT_PATH =	./libft/
LIBFT_FILE =	libft.a
LIBFT_LIB =	$(addprefix $(LIBFT_PATH), $(LIBFT_FILE))
MLX_FLAG =	-lX11 -lXext
MLX_PATH =	./minilibx-linux/
MLX_FILE =	libmlx.a
MLX_LIB	=	$(addprefix $(MLX_PATH), $(MLX_FILE))
MLX_EX	=	$(MLX_LIB) $(MLX_FLAG)
RM =		rm -rf
SRC =		so_long.c \
		map.c \
		map_check.c \
		var_and_img.c \
		move.c \
		direction.c \
		utils.c \
		backtracking.c

OBJ =		$(SRC:.c=.o)

all: $(NAME)

lib:
	make -C $(LIBFT_PATH)

mlx:
	make -sC $(MLX_PATH)


$(NAME): lib mlx $(OBJ)
	$(CC) $(OBJ) $(LIBFT_LIB) $(MLX_EX) -o $(NAME) -g3

clean:
	make clean -sC $(MLX_PATH)
	make clean -sC $(LIBFT_PATH)
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re
