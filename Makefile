# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/07 15:29:04 by msaadidi          #+#    #+#              #
#    Updated: 2024/04/01 21:44:52 by msaadidi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BNAME = checker
CC = cc 
CFLAGS = -Wall -Wextra -Werror
SRCS = mandatory/sorting_utils.c \
		mandatory/test.c \
		mandatory/parsing.c \
		mandatory/lst_management.c \
		mandatory/put_in_fd.c \
		mandatory/ft_split.c \
		mandatory/operations_1.c \
		mandatory/operations_2.c \
		mandatory/push_swap_commands.c \
		mandatory/push_swap_utils.c \
		mandatory/push_swap.c \
		mandatory/string_operations.c \
		bonus/get_next_line_utils.c \

BONUS =	mandatory/lst_management.c \
		mandatory/sorting_utils.c \
		mandatory/ft_split.c \
		mandatory/parsing.c \
		mandatory/string_operations.c \
		mandatory/operations_1.c \
		mandatory/operations_2.c \
		mandatory/put_in_fd.c \
		mandatory/push_swap_utils.c \
		bonus/checker.c \
		bonus/get_next_line.c \
		bonus/get_next_line_utils.c \

OBJS = $(SRCS:.c=.o)
BOBJS = $(BONUS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@
	@make clean
	
bonus : $(BOBJS)
	$(CC) $(CFLAGS) $(BOBJS) -o $(BNAME)

clean : 
	@rm -rf $(OBJS) $(BOBJS)

fclean : clean
	@rm -f $(NAME) $(BNAME)

re : fclean all

.SECONDARY : $(OBJS)
