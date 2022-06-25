# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdarrin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/19 21:51:21 by fdarrin           #+#    #+#              #
#    Updated: 2020/11/19 21:51:27 by fdarrin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER = libasm.h

FLAGS = -fmacho64

NAME = libasm.a

SRC = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s

OBJ = $(SRC:.s=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o:%.s $(HEADER)
	nasm $(FLAGS) $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f a.out

re: fclean all

.PHONY: all clean fclean re
