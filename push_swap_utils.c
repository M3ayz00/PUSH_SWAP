/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:59:57 by msaadidi          #+#    #+#             */
/*   Updated: 2024/02/02 16:58:18 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_cheapest(t_stack *stack)
{
	t_stack	*cheapest;
	int		min;

	min = stack->push_cost;
	cheapest = stack;
	while (stack->next)
	{
		if (stack->push_cost < min)
		{
			min = stack->push_cost;
			cheapest = stack;
		}
		stack = stack->next;
	}
	return (cheapest);
}

void	update_position(t_stack *stack)
{
	int	i;
	int	median;

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

void set_push_cost(t_stack *A, t_stack *B)
{
	t_stack *currB = B;
    while (currB)
    {
        currB->push_cost = 0;

        if (currB->target)
        {
            int targetIndex = currB->target->index;
            int bSize = ft_lstsize(B);
            int aSize = ft_lstsize(A);
            if (currB->above_median == 0)
                currB->push_cost = bSize - currB->index;
            else
                currB->push_cost = currB->index;

            if (currB->target->above_median == 1)
                currB->push_cost += targetIndex;
            else
                currB->push_cost += aSize - targetIndex;
        }

        currB = currB->next;
    }
}


void	set_target_node(t_stack *A, t_stack *B)
{
	t_stack	*curr;
	t_stack	*target;
	long	match;

	while (B)
	{
		curr = A;
		match = LONG_MAX;
		while (curr)
		{
			if (curr->data > B->data && curr->data < match)
			{
				match = curr->data;
				target = curr;
			}
			curr = curr->next;
		}
		if (match == LONG_MAX)
			B->target = ft_lstget_minnode(A);
		else
			B->target = target;
		B = B->next;
	}
}

void	last_rotations(t_stack **stack, t_stack *top, char c)
{
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
