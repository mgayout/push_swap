# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 08:12:19 by mgayout           #+#    #+#              #
#    Updated: 2024/02/27 18:11:03 by mgayout          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
CC		=	gcc
CFLAGS	=	-Wextra -Wall -Werror -g3
REMOVE	=	rm -f
SRC_DIR	=	./src/
LIBFT	=	./libft/libft.a
LIBPF	=	./ft_printf/libftprintf.a

SRCS	=	src/main.c \
			src/stack.c \
			src/parse.c \
			src/stack_function.c \
			src/push_swap.c \
			src/push_swap2.c \
			src/lst_functions.c \
			src/to_do.c \

all: $(LIBFT) $(LIBPF) $(NAME)

$(NAME):
			$(CC) $(SRCS) $(LIBFT) $(LIBPF) $(CFLAGS) -o $(NAME)

$(LIBFT):
			@make bonus -C libft/

$(LIBPF):
			@make -C ft_printf/

clean:	
			@make clean -C libft/
			@make clean -C ft_printf/

fclean:
			$(REMOVE) $(NAME)

re: fclean all

.PHONY: all clean fclean re