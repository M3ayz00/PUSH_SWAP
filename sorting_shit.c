/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_shit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:25:21 by msaadidi          #+#    #+#             */
/*   Updated: 2024/01/07 20:23:40 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_2(t_stack **stack)
{
    if(!stack || !(*stack) || !(*stack)->next)
        return;
    if (((*stack)->data > (*stack)->next->data))
        swap(stack, "sa");
}

void    sort_3(t_stack **stack)
{
    if(!stack || !(*stack) || !(*stack)->next)
        return;
    if ((*stack)->data > (*stack)->next->data)
        swap(stack, "sa");
    if ((*stack)->data > (*stack)->next->next->data)
        r_rotate(stack, "rra");
    if ((*stack)->next->data > (*stack)->next->next->data)
    {
        r_rotate(stack, "rra");
        swap(stack, "sa");
    }
}

void    sort_5(t_stack **A, t_stack **B)
{
    if(!A || !(*A) || !(*A)->next || !B)
        return ;
    while((*A)->data != ft_lstget_min(A))
        rotate(A, "ra");
    if((*A)->data == ft_lstget_min(A))
        push(A, B, "pb");
    while((*A)->data != ft_lstget_min(A))
        rotate(A, "ra");
    if((*A)->data == ft_lstget_min(A))
        push(A, B, "pb");
    if(ft_lstsize(*A) == 3)
        sort_3(A);
    push(B, A, "pa");
    push(B, A, "pa");
}