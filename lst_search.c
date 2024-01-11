/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_search.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:38:42 by m3ayz00           #+#    #+#             */
/*   Updated: 2024/01/11 12:42:56 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstget_max(t_stack *stack)
{
	int	max;

	max = stack->data;
	while (stack->next)
	{
		if (max < stack->next->data)
			max = stack->next->data;
		stack = stack->next;
	}
	return (max);
}

int	ft_lstget_min(t_stack *stack)
{
	int	min;

	min = stack->data;
	while (stack->next)
	{
		if (min > stack->next->data)
			min = stack->next->data;
		stack = stack->next;
	}
	return (min);
}

t_stack	*ft_lstbfr_last(t_stack *stack)
{
	if (!stack || !stack->next)
		return (NULL);
	while (stack->next->next)
		stack = stack->next;
	return (stack);
}

t_stack	*ft_lstget_minnode(t_stack *stack)
{
	t_stack	*min_node;
	int		min;

	min = ft_lstget_min(stack);
	min_node = stack;
	while (stack)
	{
		if (min == stack->data)
			min_node = stack;
		stack = stack->next;
	}
	return (min_node);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}
