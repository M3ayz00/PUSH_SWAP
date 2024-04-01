/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:54:25 by m3ayz00           #+#    #+#             */
/*   Updated: 2024/04/01 21:13:53 by msaadidi         ###   ########.fr       */
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

void	push_swap(t_stack **a, int chunksize)
{
	t_stack	*b;

	b = NULL;
	push_to_b(a, &b, chunksize);
	push_to_a(a, &b);
}
