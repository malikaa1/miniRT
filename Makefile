NAME = miniRT
SRCS = ${wildcard ./src/*.c}
INCLUDES = includes
CC = gcc
MLX_FLAGS = -I./minilibx-linux -L./minilibx-linux -lmlx -lXext -lX11
LIBFT_FLAGS = -I./libft -L./libft -lft
MLX_DIR = ./minilibx-linux
LIBFT_DIR = ./libft
OBJS		= ${SRCS:.c=.o}
CFLAGS= -Wall -Wextra -Werror


$(NAME):	$(OBJS)
	@make -C $(MLX_DIR)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDES) $(OBJS) -o $(NAME) $(LIBFT_FLAGS) $(MLX_FLAGS)


%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -o $@ -c $<

all:	$(NAME)



clean:
	${RM} ${OBJS}
	@make clean -C $(MLX_DIR)


fclean:	clean
	${RM} ${NAME}
	@$(RM) miniRT.bmp

re:	fclean all