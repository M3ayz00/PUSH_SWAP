/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:59:57 by msaadidi          #+#    #+#             */
/*   Updated: 2024/04/01 20:32:42 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_position(t_stack *stack)
{
	int	i;
	int	median;

	if (!stack)
		return ;
	i = 0;
	median = ft_lstsize(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack = stack->next;
		i++;
	}
}

void	last_rotations(t_stack **stack, t_stack *top, char c)
{
	if (!top)
		return ;
	update_position(*stack);
	while (*stack != top)
	{
		if (c == 'a')
		{
			if (top->above_median == 1)
				rotate(stack, "ra");
			else
				r_rotate(stack, "rra");
		}
		else if (c == 'b')
		{
			if (top->above_median == 1)
				rotate(stack, "rb");
			else
				r_rotate(stack, "rrb");
		}
	}
}
