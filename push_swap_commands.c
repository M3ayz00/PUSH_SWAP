/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:54:25 by m3ayz00           #+#    #+#             */
/*   Updated: 2024/03/27 21:26:53 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack **stack)
{
	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	if (((*stack)->data > (*stack)->next->data))
		swap(stack, "sa");
}

void	sort_3(t_stack **stack)
{
	if (!stack || !(*stack) || !(*stack)->next || !(*stack)->next->next)
		return ;
	if ((*stack)->data == ft_lstget_max(*stack))
		rotate(stack, "ra");
	if ((*stack)->next->data == ft_lstget_max(*stack))
		r_rotate(stack, "rra");
	if ((*stack)->data > (*stack)->next->data)
		swap(stack, "sa");
}
void push_a_to_b(t_stack **A, t_stack **B)
{
	t_stack *median;
	t_stack *curr_top = *A;
	int size = ft_lstsize(curr_top);
	int iterations;
	while (size > 3)
	{
		iterations = size / 2;
		median = ft_lstget_median(curr_top);
		push_lower_nodes(A, B, median, &iterations);
		push_middle_nodes(A, B, median, &iterations);
		curr_top = *A;
		size = ft_lstsize(curr_top);
	}
	sort_3(A);
}

void	push_b_to_a(t_stack **A, t_stack **B)
{
	while (B && *B)
	{
		init_nodes(*A, *B);
		move_nodes(A, B);
	}
}

void	push_swap(t_stack **A)
{
	t_stack **B;

	B = NULL;
	push_a_to_b(A, B);
	push_b_to_a(A, B);
	update_position(*A);
	min_go_up(A);
}
