SRCS =		so_long.c \
		map.c \
		map_check.c \
		var_and_img.c \
		move.c \
		direction.c \
		utils.c \
		backtracking.c \
		des_img.c


OBJS =		${SRCS:.c=.o}

NAME =		so_long

CC =		cc

CFLAGS =	-Wall -Wextra -Werror -g3

LDFLAGS =	-lXext -lX11 -L./minilibx-linux -lmlx -L./libft -lft 

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
			@make -sC libft/
			@make -sC minilibx-linux/
			${CC} -o ${NAME} ${OBJS} ${LDFLAGS}

clean:
		@make clean -sC minilibx-linux/
		@make clean -sC libft/
		@rm -rf ${OBJS}

fclean:		clean
		@rm -rf ${NAME}
		@make fclean -C libft/

re:		fclean all

.PHONY:		all clean fclean re