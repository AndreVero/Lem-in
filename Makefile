# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: averemiy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/14 21:00:23 by averemiy          #+#    #+#              #
#    Updated: 2018/06/11 15:05:55 by averemiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

FLAGS = -Wall -Werror -Wextra

LIB = ./libft/libft.a

OBJ = ./add_end.o ./create_end.o ./create_new_room.o ./create_start.o ./find_neighbors.o \
	  ./main.o ./get_next_line.o ./help_function.o ./printer.o ./free_helper.o ./solver_deep.o \
	  ./solver.o ./check_valid_2.o ./reader.o ./help_function2.o ./help_function3.o

SRC = ./add_end.c ./create_end.c ./create_new_room.c ./create_start.c ./find_neighbors.c \
	  ./main.c ./get_next_line.c ./help_function.c ./printer.c ./free_helper.c ./solver_deep.c \
	  ./solver.c ./check_valid_2.c ./reader.c ./help_function2.c ./help_function3.c

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft/
	gcc $(FLAGS) $(SRC) $(LIB) -o $(NAME)

clean :
	make -C ./libft/ clean
	rm -rf $(OBJ)

fclean : clean
	make -C ./libft/ fclean
	rm -rf $(NAME)
	rm -rf libft.a

re : fclean all
