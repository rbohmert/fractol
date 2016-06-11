# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbohmert <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 11:23:48 by rbohmert          #+#    #+#              #
#    Updated: 2016/06/11 08:15:57 by rbohmert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, fclean, clean, re

NAME = libft/libft.a

SRC = fractol.c hook.c mandelbrot.c julia.c sword.c chameleon.c tricorn.c \
	  burn.c lapin.c brain.c

EXE = fractol

GCC = gcc -lmlx -framework Appkit -framework OpenGl -o $(EXE) \
	  -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@echo "\033[33mLibrary's compilation\033[0m"
	@make -C libft/
	@echo "\033[33mProject's compilation\033[0m"
	@$(GCC) $(SRC) $(NAME)
	@echo "\033[33mAll compilation done\033[0m" "\033[32m [ok] \033[32m"

clean:
	@echo "\033[33mLibrary's cleaning\033[0m"
	@make -C libft/ clean

fclean: clean
	@rm -rf $(EXE)
	@rm -rf $(NAME)
	@make -C libft/ fclean

re: fclean all
