# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: satkins <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/25 14:05:53 by satkins           #+#    #+#              #
#    Updated: 2017/10/12 15:16:17 by satkins          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SOURCE = ft_alloc_answer_grid.c \
		 ft_print_answer_grid.c \
		 ft_place_tetriminos.c \
		 ft_placeable.c \
		 ft_io.c  \
		 helper_funcs.c


VPATH = srcs

HEADER_FILES = includes

CC = gcc

LIB = libft.a

FLAGS = -Wall -Wextra -Werror

TARG = $(SOURCE:.c=.o)
		

all: $(NAME)

$(NAME): $(SOURCE)
	@$(CC) $(FLAGS) -c $^
	@$(CC) $(FLAGS) -I$(HEADER_FILES) $(TARG) $(LIB) -o $(NAME)

clean:
	@/bin/rm -f $(TARG)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
