/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:39:50 by msaadidi          #+#    #+#             */
/*   Updated: 2024/04/01 21:35:45 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*sort_int_tab(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (arr[i] < arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	return (arr);
}

int	*list_to_arr(t_stack *stack)
{
	int	*arr;
	int	i;
	int	size;

	size = ft_lstsize(stack);
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (stack)
	{
		arr[i] = stack->data;
		i++;
		stack = stack->next;
	}
	return (sort_int_tab(arr, size));
}

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
