/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m3ayz00 <m3ayz00@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:29:14 by msaadidi          #+#    #+#             */
/*   Updated: 2024/01/10 15:03:53 by m3ayz00          ###   ########.fr       */
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


# include "libft/libft.h"
# include <stdio.h>

void    swap_data(int *a, int *b);
void    swap(t_stack **B, char *op);
void    swap_S(t_stack **A, t_stack **B, char*op);
void    push(t_stack **A, t_stack **B, char *op);
void    rotate(t_stack **stack, char *op);
void    rotate_S(t_stack **A, t_stack **B ,char *op);
void    r_rotate(t_stack **stack, char *op);
void    r_rotate_S(t_stack **A, t_stack **B, char *op);
void    rotate_both(t_stack **A, t_stack **B, t_stack *cheapest);
void    r_rotate_both(t_stack **A, t_stack **B, t_stack *cheapest);
void    last_rotations(t_stack **stack, t_stack *top, char c);
void    sort_2(t_stack **stack);
void    sort_3(t_stack **stack);
void    sort_5(t_stack **A, t_stack **B);
void    set_target_node(t_stack *A, t_stack *B);
void    set_push_cost(t_stack *A, t_stack *B);
void    update_position(t_stack *stack);
t_stack *get_cheapest(t_stack *stack);
void    push_swap(t_stack **A, t_stack **B);
void    move_nodes(t_stack **A, t_stack **B);
void    init_nodes(t_stack *A, t_stack *B);
#endif