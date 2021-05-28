# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/22 16:54:01 by elfetoua          #+#    #+#              #
#    Updated: 2020/02/28 20:22:19 by elfetoua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC = deal_key.c draw_map.c drawline.c exitenv_cleardraw_center.c fill_data.c ft_setup.c hex_to_dec.c main.c transform.c
OBJ = $(SRC:.c=.o)
INCLUDE = fdf.h
LIBFT = ./libft/libft.a
LDLIBS = -lft -lm -lmlx
LDFLAGS = -L./libft -framework OpenGl -framework Appkit
CC = gcc
CFLAGS =  -Wall -Wextra -Werror

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft
$(NAME): $(OBJ) $(INCLUDE)
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) $(OBJ) -o $(NAME)
clean:
	$(RM) $(OBJ)
	make clean -C libft
fclean:clean
	$(RM) $(NAME)
	make fclean -C libft
re: fclean all
