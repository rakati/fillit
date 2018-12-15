# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abiri <kerneloverseer@protonmail>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/21 19:54:59 by abiri             #+#    #+#              #
#    Updated: 2018/10/21 22:28:30 by abiri            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC = board.c\
	brain.c\
	checkfile.c\
	test.c\
	set_tetrims.c\
	main.c
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Werror -Wextra
NAME = fillit
LIBDIR = -L./libft
LIB = -lft
all: libft.a $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRC)
	gcc $(FLAGS) $(OBJ) -o $(NAME) $(LIBDIR) $(LIB)
libft.a:
	make -C ./libft
clean:
	make -C ./libft clean
	rm -rf $(OBJ)
fclean: clean
	make -C ./libft fclean
	rm -rf $(NAME)
re: fclean all

