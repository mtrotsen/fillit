#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtrotsen <mtrotsen@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/12 12:07:48 by mtrotsen          #+#    #+#              #
#    Updated: 2018/12/12 12:08:10 by mtrotsen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit
SRCS = ./sources/main.c ./sources/ft_read_file.c ./sources/ft_arrange.c \
./sources/ft_dot.c ./sources/funcc.c ./sources/ft_put_shape.c \
./sources/copying_area.c ./sources/put_shape_more.c
LIB = ./libft/libft.a

$(NAME):
	@make -C ./libft 
	@gcc -Wall -Wextra -Werror -o $(NAME) $(SRCS) $(LIB)

all: $(NAME)

clean:
	@make -C ./libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C ./libft fclean

re: fclean all
