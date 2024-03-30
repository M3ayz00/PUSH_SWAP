/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:43:12 by msaadidi          #+#    #+#             */
/*   Updated: 2024/03/30 21:04:49 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_lower_nodes(t_stack **A, t_stack **B, t_stack *median, int *iterations)
{
	t_stack *current_bot = ft_lstlast(*A);

	while (current_bot->data < median->data && *iterations > 0)
	{
		r_rotate(A, "rra");
		push(A, B, "pb");
		current_bot = ft_lstlast(*A);
		(*iterations)--;
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void	optimal_moves(t_stack **A, t_stack *median)
{
	t_stack	*head;

	update_position(*A);
	head = *A;
	while (head && head->data >= median->data)
			head = head->next;
	if (head->above_median)
		rotate(A, "ra");
	else
		r_rotate(A, "rra");
	
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////

void push_middle_nodes(t_stack **A, t_stack **B, t_stack *median, int *iterations)
{
	while (*iterations > 0)
	{
		if ((*A)->data < median->data)
		{
			push(A, B, "pb");
			(*iterations)--;
		}
		else
			optimal_moves(A, median);
	}
}
void	init_nodes(t_stack *A, t_stack *B)
{
	update_position(A);
	update_position(B);
	set_target_node(A, B);
	set_push_cost(A, B);
}

void	move_nodes(t_stack **A, t_stack **B)
{
	t_stack	*cheapest;

	cheapest = get_cheapest(*B);
	if (cheapest->above_median == 1 && cheapest->target->above_median == 1)
		rotate_both(A, B, cheapest);
	else if (cheapest->above_median == 0 && cheapest->target->above_median == 0)
		r_rotate_both(A, B, cheapest);
	last_rotations(B, cheapest, 'b');
	last_rotations(A, cheapest->target, 'a');
	push(B, A, "pa");
}

void	min_go_up(t_stack **A)
{
	t_stack	*min;

	min = ft_lstget_minnode(*A);
	if (min->above_median == 1)
		while (*A != min)
			rotate(A, "ra");
	else
		while (*A != min)
			r_rotate(A, "rra");
}