/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m3ayz00 <m3ayz00@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:29:14 by msaadidi          #+#    #+#             */
/*   Updated: 2024/01/10 21:59:36 by m3ayz00          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int				index;
	int				cheapest;
	int				data;
	int				above_median;
	int				push_cost;
	struct s_stack	*next;
	struct s_stack	*target_node;
}   t_stack;

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <stddef.h>
# include <stdint.h>

// operations1
void    swap_data(int *a, int *b);
void    swap(t_stack **B, char *op);
void    push(t_stack **A, t_stack **B, char *op);
void    rotate(t_stack **stack, char *op);
void    r_rotate(t_stack **stack, char *op);
//operations2
void    swap_S(t_stack **A, t_stack **B, char*op);
void    rotate_S(t_stack **A, t_stack **B ,char *op);
void    r_rotate_S(t_stack **A, t_stack **B, char *op);
void    rotate_both(t_stack **A, t_stack **B, t_stack *cheapest);
void    r_rotate_both(t_stack **A, t_stack **B, t_stack *cheapest);
//push_swap_utils
void    last_rotations(t_stack **stack, t_stack *top, char c);
void    set_target_node(t_stack *A, t_stack *B);
void    set_push_cost(t_stack *A, t_stack *B);
void    update_position(t_stack *stack);
t_stack *get_cheapest(t_stack *stack);
//push_swap commands
void    push_swap(t_stack **A, t_stack **B);
void    sort_2(t_stack **stack);
void    sort_3(t_stack **stack);
void    init_nodes(t_stack *A, t_stack *B);
void    move_nodes(t_stack **A, t_stack **B);
//string operations
int		ft_atoi(const char *str);
int     ft_strcmp(char *s1, char *s2);
int     ft_intcmp(int a, int b);
int		ft_isdigit(int c);
void	ft_perror(int e, char *err);
// lst search
int     ft_lstget_max(t_stack *stack);
t_stack *ft_lstbfr_last(t_stack *stack);
int     ft_lstget_min(t_stack *stack);
t_stack *ft_lstget_minnode(t_stack *stack);
t_stack	*ft_lstlast(t_stack *lst);
//lst_management
t_stack	*lst_new(int data, int index);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
int		ft_lstsize(t_stack *lst);
void	ft_lstclear(t_stack **lst);
int     ft_islst_sorted(t_stack **stack);
//ft_put_in_fd
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
// ft_split
int		ft_wordcount(const char *s, char c);
char	**ft_split(char const *s, char c);
//check_errors
int		check_dups(char **strs, int i);
void	check_input(char **strs, int i);
int is_many(char *str, char c);
t_stack	*init_stack(char **numbers, int i);


#endif