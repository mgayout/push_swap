# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 10:59:59 by mgayout           #+#    #+#              #
#    Updated: 2023/12/01 10:59:59 by mgayout          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libftprintf.a
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -rf
SRC 			=	src/ft_printf

SRC_A			=	$(addsuffix .c, ${SRC})

OBJ				=	$(SRC_A:.c=.o)

all:			$(NAME)

lib :
				make -C libft/
				cp -rf libft/libft.a $(NAME)

$(NAME):		lib $(OBJ) 
					ar -rc $(NAME) $(OBJ)

clean:
					$(RM) $(OBJ) libft/*.o

fclean: 		clean
					$(RM) $(NAME) libft/libft.a

re:				fclean all

.PHONY: 		all clean fclean re