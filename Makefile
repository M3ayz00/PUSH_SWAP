# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/07 15:29:04 by msaadidi          #+#    #+#              #
#    Updated: 2024/03/27 22:04:13 by msaadidi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc 
CFLAGS = -Wall -Wextra -Werror
SRCS = sorting_utils.c check_errors.c lst_search.c lst_management.c put_in_fd.c ft_split.c operations_1.c operations_2.c push_swap_commands.c push_swap_utils.c push_swap_utils2.c push_swap.c string_operations.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -o $@
	@make clean

clean : 
	@rm -rf $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.SECONDARY : $(OBJS)
