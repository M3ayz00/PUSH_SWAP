NAME = push_swap
CC = cc -Wall -Wextra -Werror
SRCS = push_swap.c


all : $(NAME)

$(NAME) : $(SRCS)
	@cd LIBFT-main && make
	@$(CC) $(SRCS) LIBFT-main/libft.a -o $(NAME)

clean : 
	@cd LIBFT-main && make clean

fclean : clean
	@cd LIBFT-main && make fclean
	@rm -f $(NAME)

re : fclean all
