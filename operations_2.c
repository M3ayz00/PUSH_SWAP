/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:25:21 by msaadidi          #+#    #+#             */
/*   Updated: 2024/01/11 12:54:44 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_s(t_stack **A, t_stack **B, char *op)
{
	if (!A || !(*A) || !(*A)->next)
		return ;
	if (!B || !(*B) || !(*B)->next)
		return ;
	rotate(A, NULL);
	rotate(B, NULL);
	if (op)
		ft_putendl_fd(op, 1);
}

void	swap_s(t_stack **A, t_stack **B, char *op)
{
	if (!A || !(*A) || !(*A)->next)
		return ;
	if (!B || !(*B) || !(*B)->next)
		return ;
	swap(A, NULL);
	swap(B, NULL);
	if (op)
		ft_putendl_fd(op, 1);
}

void	r_rotate_s(t_stack **A, t_stack **B, char *op)
{
	if (!A || !(*A) || !(*A)->next)
		return ;
	if (!B || !(*B) || !(*B)->next)
		return ;
	r_rotate(A, NULL);
	r_rotate(B, NULL);
	if (op)
		ft_putendl_fd(op, 1);
}

void	rotate_both(t_stack **A, t_stack **B, t_stack *cheapest)
{
	while (*A != cheapest->target && *B != cheapest)
		rotate_s(A, B, "rr");
	update_position(*A);
	update_position(*B);
}

void	r_rotate_both(t_stack **A, t_stack **B, t_stack *cheapest)
{
	while (*A != cheapest->target && *B != cheapest)
		r_rotate_s(A, B, "rrr");
	update_position(*A);
	update_position(*B);
}
