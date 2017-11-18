# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/20 22:18:00 by tberthie          #+#    #+#              #
#    Updated: 2017/11/18 14:29:34 by tberthie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS = $(addsuffix .o, $(addprefix objs/, main run render parse rooms ants \
	   					stats utl refresh))

NAME = ../visu_hex

all: objs $(NAME)

objs:
	mkdir objs

$(NAME): $(OBJS)
	gcc -o $(NAME) $(OBJS) ../libft/libft.a SDL/SDL_lib SDL/SDL_libttf

objs/%.o: srcs/%.c
	gcc -o $@ -c $< -I includes -I ../libft -I includes -I SDL -Wall -Wextra

clean:
	rm -rf objs

fclean: clean
	rm -f $(NAME)

re: fclean all
