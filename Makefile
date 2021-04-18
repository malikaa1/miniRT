NAME = miniRT
SRCS = ${wildcard ./src/*.c}
#SRCS =./src/test_mlx.c
INCLUDES = includes
CC = gcc
MLX_FLAGS = -I./minilibx-linux -L./minilibx-linux -lm -lmlx -lXext -lX11
LIBFT_FLAGS = -I./libft -L./libft -lftt
MLX_DIR = ./minilibx-linux
LIBFT_DIR = ./libft
OBJS		= ${SRCS:.c=.o}
CFLAGS= -Wall -Wextra -Werror
SRCS_LIBFT 	= ${wildcard ./libft/*.c}
OBJS_LIBFT	= ${SRCS_LIBFT:.c=.o}


$(NAME):	$(OBJS) $(OBJS_LIBFT)
	@make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDES) $(OBJS) $(OBJS_LIBFT) -o $(NAME) $(MLX_FLAGS)  -lm 


%.o: %.c
	$(CC) -g $(CFLAGS) -I $(INCLUDES) -o $@ -c $<

all:	$(NAME)



clean:
	${RM} ${OBJS}
	@make clean -C $(MLX_DIR)


fclean:	clean
	${RM} ${NAME}
	@$(RM) miniRT.bmp

re:	fclean all