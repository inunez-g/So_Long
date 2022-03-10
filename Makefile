# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inunez-g <inunez-g@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/04 10:49:31 by inunez-g          #+#    #+#              #
#    Updated: 2022/03/04 11:08:31 by inunez-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC =   so_long.c\
		so_long_mapget.c\
		so_long_drawmap.c\
		so_long_moves.c\

CC =	gcc

OBJS = $(SRC:.c=.o)

CFLAGS =	-Werror -Wextra -Wall #-g3 -fsanitize=address

MAKE = make

LIB2 =	libft/libft.a

INCLUDES = so_long.h

all: $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJS) $(LIB2)
	$(CC) $(CFLAGS)  $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit $(LIB2) -o $(NAME)

$(LIB2): libft/*.c
	$(MAKE) -C libft/
	$(MAKE) -C libft/ bonus

all: $(NAME)

clean:
	$(MAKE) -C libft/ clean
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(LIB2)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
