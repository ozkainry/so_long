NAME =		so_long
CC =		@cc
CFLAGS =	-Wall -Wextra -Werror -g3
LDFLAGS =	-lXext -lX11 -L./minilibx-linux -lmlx -L./libft -lft 
OBJ =		$(patsubst src%, obj%, $(SRC:.c=.o))
SRC =		src/so_long.c \
		src/map.c \
		src/map_check.c \
		src/var_and_img.c \
		src/move.c \
		src/direction.c \
		src/utils.c \
		src/backtracking.c \
		src/des_img.c

all:		obj ${NAME}

${NAME}:	${OBJ}
		@echo "COMPILING LIBFT\n"
		@make -sC libft/
		@echo "LIBFT COMPILED\n"
		@echo "COMPILING MLX\n"
		@make -sC minilibx-linux/
		@echo "MLX COMPILED\n"
		@echo "COMPILING SO_LONG\n"
		${CC} -o ${NAME} ${OBJ} ${LDFLAGS}
		@echo "SO_LONG COMPILED\n"

obj:
			@mkdir -p obj

obj/%.o:	src/%.c
			$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
		@make clean -sC minilibx-linux/
		@make clean -sC libft/
		@rm -rf ${OBJ} obj

fclean:		clean
		@rm -rf ${NAME}
		@make fclean -C libft/

re:		fclean all

.PHONY:		all clean fclean re