NAME = push_swap
CC = cc -Wall -Wextra -Werror
SRCS = push_swap.c


all : $(NAME)

$(NAME) : $(SRCS)
	@cd libft && make
	@$(CC) $(SRCS) LIBFT-main/libft.a -o $(NAME)

clean : 
	@cd libft && make clean

fclean : clean
	@cd libft && make fclean
	@rm -f $(NAME)

re : fclean all
