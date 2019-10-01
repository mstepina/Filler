# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mstepina <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/25 20:13:17 by mstepina          #+#    #+#              #
#    Updated: 2019/09/25 20:13:25 by mstepina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=./resources/players/mstepina.filler

SRCS=src/*.c

INCLUDES=libft/libft.a

FLAGS=-Werror -Wextra -Wall

all: $(NAME)

$(NAME):
	@make -C libft/ all 
	gcc -o $(NAME) $(FLAGS) $(SRCS) $(INCLUDES) -g

clean:
	@make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all
