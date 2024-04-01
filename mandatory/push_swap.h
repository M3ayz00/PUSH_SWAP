/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:29:14 by msaadidi          #+#    #+#             */
/*   Updated: 2024/04/01 21:41:33 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <stddef.h>
# include <stdint.h>
# include "../bonus/get_next_line.h"

typedef struct s_stack
{
	int				index;
	int				arr_index;
	int				data;
	int				above_median;
	int				push_cost;
	int				rotate_cost;
	struct s_stack	*next;
	struct s_stack	*target;
}	t_stack;

// operations1
void	swap_data(int *a, int *b);
void	swap(t_stack **B, char *op);
void	push(t_stack **A, t_stack **B, char *op);
void	rotate(t_stack **stack, char *op);
void	r_rotate(t_stack **stack, char *op);

// operations2
void	swap_s(t_stack **A, t_stack **B, char *op);
void	rotate_s(t_stack **A, t_stack **B, char *op);
void	r_rotate_s(t_stack **A, t_stack **B, char *op);
void	rotate_both(t_stack **A, t_stack **B, t_stack *cheapest);
void	r_rotate_both(t_stack **A, t_stack **B, t_stack *cheapest);

// push_swap_utils
void	last_rotations(t_stack **stack, t_stack *top, char c);
void	update_position(t_stack *stack);

// push_swap commands
void	push_swap(t_stack **A, int chunksize);
void	sort_2(t_stack **stack);
void	sort_3(t_stack **stack);

// string operations
int		ft_atoi(const char *str, char **numbers, t_stack **stack);
int		ft_strncmp(char *s1, char *s2, size_t n);
int		ft_intcmp(int a, int b);
int		ft_isdigit(int c);
void	ft_perror(int e, char *err);

// lst search
int		ft_lstget_max(t_stack *stack);
t_stack	*ft_lstbfr_last(t_stack *stack);
t_stack	*ft_lstlast(t_stack *lst);

// lst_management
t_stack	*lst_new(int data);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
int		ft_lstsize(t_stack *lst);
void	ft_lstclear(t_stack **lst);
int		ft_islst_sorted(t_stack **stack);

// ft_put_in_fd
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);

// ft_split
char	**ft_split(char *s, char *set);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t num_elements, size_t element_size);
void	free_strs(char **strs);

// check_errors
int		check_dups(t_stack *stack);
int		check_input(char **strs);
void	init_stack(char **numbers, t_stack **stack);

// sorting_utils
int		*list_to_arr(t_stack *stack);

// void	push_max(t_stack **A,t_stack **B);
t_stack	*check_args(int ac, char **av);
void	push_to_b(t_stack **a, t_stack **b, int chunksize);
void	push_to_a(t_stack **a, t_stack **b);

#endif
