# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agiulian <arthur.giuliano@student.42.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/17 22:23:16 by agiulian          #+#    #+#              #
#    Updated: 2017/03/17 18:39:47 by agiulian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -Wall -Wextra -Werror

NAME = agiulian.filler

SRC = filler/position.c \
	  filler/main.c \
	  filler/putpiece.c \
	  filler/parse.c


HEAD = -Ilibft/includes/ -Iprintf/. -I.

LIB = libft/libftprintf.a

ECHO = printf

OBJ = $(SRC:.c=.o)

CFLAGS = $(HEAD)

%.o	:	%.c
		@$(CC) $(CFLAGS) -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@$(CC) $(CFLAGS) -o $(NAME) $(LIB) $(OBJ)
	@$(ECHO) "\033[32m[Compiling filler Project]\033[0m\n"

clean:
	@make clean -C libft
	@rm -f $(OBJECT) && $(ECHO) "\033[32m[Deleting filler objects]\033[0m\n"

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)
	@$(ECHO) "\033[32m[Deleting filler Binary]\033[0m\n"

re: fclean all
