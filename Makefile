# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/20 22:18:00 by tberthie          #+#    #+#              #
#    Updated: 2017/11/13 00:20:19 by tberthie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS = $(addsuffix .o, $(addprefix objs/, main parse solve ants tools))

NAME = lem-in

all: objs $(NAME)

objs:
	mkdir objs

$(NAME): $(OBJS)
	make -C libft
	make -C visu
	gcc -o $(NAME) $(OBJS) libft/libft.a

objs/%.o: srcs/%.c
	gcc -o $@ -c $< -I includes -I libft -Weverything

clean:
	make -C libft clean
	make -C visu clean
	rm -rf objs

fclean: clean
	rm -f $(NAME) libft/libft.a visu_hex

re: fclean all
