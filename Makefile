# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/07 15:29:04 by msaadidi          #+#    #+#              #
#    Updated: 2024/02/02 17:01:01 by msaadidi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc -Wall -Wextra -Werror
SRCS = stack_a_managment.c check_errors.c lst_search.c lst_management.c put_in_fd.c ft_split.c operations_1.c operations_2.c push_swap_commands.c push_swap_utils.c push_swap.c string_operations.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)

clean : 
	@rm -rf $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all
