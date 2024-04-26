/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 19:45:19 by msaadidi          #+#    #+#             */
/*   Updated: 2024/04/25 23:37:27 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing(t_stack *a)
{
	int		*arr;
	int		arr_size;
	t_stack	*tmp;
	int		i;

	arr = list_to_arr(a);
	arr_size = ft_lstsize(a);
	tmp = a;
	while (tmp)
	{
		i = -1;
		while (++i < arr_size)
		{
			if (tmp->data == arr[i])
			{
				tmp->arr_index = i;
				break ;
			}
		}
		tmp = tmp->next;
	}
	free(arr);
}

t_stack	*find_node_a(t_stack *stack, int index, int sort_window)
{
	t_stack	*tmp;

	tmp = stack;
	update_position(stack);
	while (tmp)
	{
		if (tmp->arr_index <= index || tmp->arr_index <= index + sort_window)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_stack	*find_node_b(t_stack *stack, int index)
{
	t_stack	*tmp;

	tmp = stack;
	update_position(stack);
	while (tmp)
	{
		if (tmp->arr_index == index)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	push_to_b(t_stack **a, t_stack **b, int sort_window)
{
	int	i;
	int	size;

	i = 0;
	size = ft_lstsize(*a);
	indexing(*a);
	while (i < size)
	{
		if ((*a)->arr_index <= i)
		{
			push(a, b, "pb");
			rotate(b, "rb");
			i++;
		}
		else if ((*a)->arr_index <= i + sort_window)
		{
			push(a, b, "pb");
			i++;
		}
		else
			last_rotations(a, find_node_a(*a, i, sort_window), 'a');
	}
}

void	push_to_a(t_stack **a, t_stack **b)
{
	int	index;

	while (b && *b)
	{
		index = ft_lstsize(*b) - 1;
		last_rotations(b, find_node_b(*b, index), 'b');
		push(b, a, "pa");
	}
}
