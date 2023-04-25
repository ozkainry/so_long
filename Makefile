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
		@echo "\033[0;33m\nCOMPILING LIBFT"
		@make -sC libft/
		@echo "\033[1;32mLIBFT COMPILED\n"
		@echo "\033[0;33mCOMPILING MLX"
		@make -sC minilibx-linux/ > /dev/null 2>&1
		@echo "\033[1;32mMLX COMPILED\n"
		@echo "\033[0;33mCOMPILING SO_LONG"
		${CC} -o ${NAME} ${OBJ} ${LDFLAGS}
		@echo "\033[1;32mSO_LONG COMPILED\n"

obj:
			@mkdir -p obj

obj/%.o:	src/%.c
			$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
		@echo "\033[0;31m\nDELETING OBJ FILES IN MLX"
		@make clean -sC minilibx-linux/ > /dev/null 2>&1
		@echo "\033[1;32mDONE\n"
		@echo "\033[0;31mDELETING OBJ FILES IN LIBFT"
		@make clean -sC libft/
		@echo "\033[1;32mDONE\n"
		@echo "\033[0;31mDELETING SO_LONG OBJ FILES"
		@rm -rf ${OBJ} obj
		@echo "\033[1;32mDONE\n"

fclean:		clean
		@echo "\033[0;31mDELETING SO_LONG EXECUTABLE"
		@rm -rf ${NAME}
		@make fclean -sC libft/
		@echo "\033[1;32mDONE\n"

re:		fclean all

.PHONY:		all clean fclean re