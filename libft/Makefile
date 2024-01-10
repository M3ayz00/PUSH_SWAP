# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: m3ayz00 <m3ayz00@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/07 15:28:45 by msaadidi          #+#    #+#              #
#    Updated: 2024/01/10 18:25:19 by m3ayz00          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a
CFLAGS	= -Wall -Werror -Wextra 
CC	= cc
SRCS    = ft_atoi.c \
	ft_isdigit.c \
	ft_strlen.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putchar_fd.c \
	ft_split.c \
	ft_perror.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstclear.c \
	ft_lstbfr_last.c \
	ft_islst_sorted.c \
	ft_lstget_min.c \
	ft_lstget_max.c \
	ft_lstget_minnode.c \

OBJS 	= $(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	@ar -rc $(NAME) $(OBJS) 

clean:
	@rm -f $(OBJS) $(BNS_OBJS)

fclean: clean
	@rm -f $(NAME)

re:	fclean all
