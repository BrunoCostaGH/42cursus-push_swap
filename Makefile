# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsilva-c <bsilva-c@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 13:15:22 by bsilva-c          #+#    #+#              #
#    Updated: 2023/03/15 18:19:33 by bsilva-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Werror -Wextra -g
DEPS=libft/libft.a

SRC=error.c init_n_free.c sort_algo.c sort_algo2.c ps_operations.c ps_operations2.c ps_utils.c ps_utils2.c push_swap.c ft_atol.c
OBJ=$(SRC:.c=.o)
NAME=push_swap

all: deps $(NAME)
deps:
	$(MAKE) -C ./libft
$(NAME): $(OBJ) $(DEPS)
	$(CC) $(OBJ) $(DEPS) -o $(NAME)
clean:
	$(MAKE) $@ -C ./libft
	@rm -rf $(OBJ)
fclean: clean
	$(MAKE) $@ -C ./libft
	@rm -rf $(NAME)
re: fclean all
	$(MAKE) $@ -C ./libft
