NAME = push_swap
CC = cc -Wall -Wextra -Werror
SRCS = push_swap.c swapping_shit.c

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
