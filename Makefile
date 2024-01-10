# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: m3ayz00 <m3ayz00@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/07 15:29:04 by msaadidi          #+#    #+#              #
#    Updated: 2024/01/10 14:51:57 by m3ayz00          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc -Wall -Wextra -Werror
SRCS = push_swap.c swapping_shit.c sorting_shit.c algo.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@cd libft && make
	@$(CC) $(OBJS) libft/libft.a -o $(NAME)

clean : 
	@cd libft && make clean
	@rm -rf $(OBJS)

fclean : clean
	@cd libft && make fclean
	@rm -f $(NAME)

re : fclean all
