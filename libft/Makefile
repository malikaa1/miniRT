# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/25 19:36:28 by mrahmani          #+#    #+#              #
#    Updated: 2021/04/02 22:57:38 by mrahmani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a


CC	=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM	=	rm -f

SRCS	=	ft_atoi.c\
		   	ft_bzero.c\
		   	ft_calloc.c\
		   	ft_isalnum.c\
		   	ft_isalpha.c\
		   	ft_isascii.c \
			ft_isdigit.c\
		   	ft_isprint.c\
		   	ft_itoa.c\
		   	ft_memccpy.c\
		   	ft_memchr.c\
		   	ft_memcmp.c \
			ft_memcpy.c\
		   	ft_memmove.c\
		   	ft_memset.c\
		   	ft_putchar_fd.c\
		   	ft_putendl_fd.c \
			ft_putnbr_fd.c\
		   	ft_putstr_fd.c\
		   	ft_split.c\
			ft_strchr.c\
			ft_strdup.c \
			ft_strjoin.c\
		   	ft_strlcat.c\
		   	ft_strlcpy.c\
		   	ft_strlen.c\
		   	ft_strmapi.c\
		   	ft_strncmp.c \
			ft_strnstr.c\
		   	ft_strrchr.c\
		   	ft_strtrim.c\
			ft_substr.c\
			ft_tolower.c\
		   	ft_toupper.c
					
SRCS_BONUS 	=	ft_lstnew.c\
			   	ft_lstadd_front.c\
			   	ft_lstadd_back.c\
			   	ft_lstmap.c\
			   	ft_lstiter.c\
			   	ft_lstsize.c\
			   	ft_lstclear.c\
			   	ft_lstlast.c\
			   	ft_lstdelone.c	

OBJS 	=	${SRCS:.c=.o}

OBJS_BONUS	= ${SRCS_BONUS:.c=.o}

INCLUDES	=	./libft

.c.o:
			${CC} ${CFLAGS} -c -I${INCLUDES} $< -o ${<:.c=.o}

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

all:		${NAME}

bonus:		$(OBJS_BONUS)
			ar rcs $(NAME) $(OBJS_BONUS)

clean:
			${RM} ${OBJS} ${OBJS_BONUS}

fclean:			clean
			$(RM) $(NAME)

re:			clean all

.PHONY:		all clean fclean re
