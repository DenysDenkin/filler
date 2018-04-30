# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/23 21:12:41 by akorunsk          #+#    #+#              #
#    Updated: 2018/02/22 21:45:29 by ddenkin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ddenkin.filler

LIBNAME = libft/libft.a
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror
SRC = main.c \
	  src/init.c \
	  src/parser.c

all: liball $(NAME)

obj: $(OBJ)

$(NAME) : $(LIBNAME) $(OBJ)
		gcc $(FLAGS) $^ -o $(NAME)

%.o: %.c
		gcc $(FLAGS) -o $@ -c $<

clean: libclean
		rm -rf $(OBJ)

fclean: libfclean clean
		rm -rf $(NAME)

re: fclean all

$(LIBNAME): liball

liball:
		@make -C libft/ all

libclean:
		@make -C libft/ clean

libfclean:
		@make -C libft/ fclean

libre: libfclean liball
