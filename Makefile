# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 08:12:19 by mgayout           #+#    #+#              #
#    Updated: 2025/01/14 15:51:45 by mgayout          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

FLAG	=	-Wextra -Wall -Werror

SRCDIR	= src
HEADIR	= include

SRC		= $(shell find $(SRCDIR) -name '*.c')

PRINTFDIR	=	ft_printf-main
PRINTFURL	=	https://github.com/mgayout/ft_printf/archive/refs/heads/main.tar.gz
PRINTFAR	=	libftprintf.a

all: $(NAME)

$(NAME):	$(PRINTFAR)
					@gcc $(SRC) $(PRINTFDIR)/$(PRINTFAR) $(FLAG) -o $(NAME)

$(PRINTFAR): 
					@if [ ! -d $(PRINTFDIR) ]; then \
						curl -L $(PRINTFURL) -o printf.tar.gz; \
						tar -xzf printf.tar.gz; \
						rm printf.tar.gz; \
					fi
					@make -C $(PRINTFDIR)

clean:
					@make clean -C $(PRINTFDIR)

fclean:
			@rm -rf $(NAME)
			@rm -rf $(PRINTFDIR)

re: fclean all

.PHONY: all clean fclean re