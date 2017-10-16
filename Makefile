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

NAME = libft.a

SOURCE = ft_atoi.c \
		  ft_bzero.c \
		  ft_isalnum.c \
		  ft_isalpha.c \
		  ft_isascii.c \
		  ft_isdigit.c \
		  ft_isprint.c \
		  ft_memccpy.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_memcpy.c \
		  ft_memmove.c \
		  ft_memset.c \
		  ft_strcat.c \
		  ft_strchr.c \
		  ft_strcmp.c \
		  ft_strcpy.c \
		  ft_strdup.c \
		  ft_strlcat.c \
		  ft_strlen.c \
		  ft_strncat.c \
		  ft_strncmp.c \
		  ft_strncpy.c \
		  ft_strnstr.c \
		  ft_strrchr.c \
		  ft_strstr.c \
		  ft_tolower.c \
		  ft_toupper.c \
		  ft_memalloc.c \
		  ft_memdel.c \
		  ft_strnew.c \
		  ft_strdel.c \
		  ft_strclr.c \
		  ft_striter.c \
		  ft_striteri.c \
		  ft_strmap.c \
		  ft_strmapi.c \
		  ft_strequ.c \
		  ft_strnequ.c \
		  ft_strsub.c \
		  ft_strjoin.c \
		  ft_strtrim.c \
		  ft_strsplit.c \
		  ft_itoa.c \
		  ft_putchar.c \
		  ft_putstr.c \
		  ft_putendl.c \
		  ft_putnbr.c \
		  ft_putchar_fd.c \
		  ft_putstr_fd.c \
		  ft_putendl_fd.c \
		  ft_putnbr_fd.c 


VPATH = srcs

TEST_DEPEND = ft_alloc_answer_grid.c \
			  ft_print_answer_grid.c \
			  ft_place_tetriminos.c \
			  ft_placeable.c \
			  ft_memset.c \
			  ft_putchar.c \
			  ft_putstr.c \
			  ft_putendl.c \
			  ft_strlen.c \
			  ft_strcpy.c \
			  ft_strncpy.c \
			  ft_io.c

HEADER_FILES = includes

CC = gcc

FLAGS = -Wall -Wextra -Werror

TARG = $(SOURCE:.c=.o)
		

all: $(NAME)

$(NAME): $(SOURCE)
	@$(CC) $(FLAGS) -c -I$(HEADER_FILES) $^ && ar rc $(NAME) $(TARG)

clean:
	@/bin/rm -f $(TARG)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

tester:$(TEST_DEPEND)
	@$(CC) $(FLAGS) -I$(HEADER_FILES) $^ -o exe
