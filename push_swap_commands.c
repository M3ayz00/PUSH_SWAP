/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m3ayz00 <m3ayz00@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:54:25 by m3ayz00           #+#    #+#             */
/*   Updated: 2024/01/10 22:10:59 by m3ayz00          ###   ########.fr       */
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
    if (!stack || !(*stack) || !(*stack)->next || !(*stack)->next->next)
        return;

    if ((*stack)->data == ft_lstget_max(*stack))
        rotate(stack, "ra");
    if ((*stack)->next->data ==ft_lstget_max(*stack))
        r_rotate(stack, "rra");
    if ((*stack)->data > (*stack)->next->data)
        swap(stack, "sa");
}

void    init_nodes(t_stack *A, t_stack *B)
{
    update_position(A);
    update_position(B);
    set_target_node(A, B);
    set_push_cost(A, B);
}

void    move_nodes(t_stack **A, t_stack **B)
{
    t_stack *cheapest;

    cheapest = get_cheapest(*B);
    if(cheapest->above_median == 1 && cheapest->target_node->above_median == 1)
        rotate_both(A, B, cheapest);
    else if (cheapest->above_median == 0 && cheapest->target_node->above_median == 0)
        r_rotate_both(A, B, cheapest);
    last_rotations(B, cheapest, 'b');
    last_rotations(A, cheapest->target_node, 'a');
    push(B, A, "pa");
}

void    push_swap(t_stack **A, t_stack **B)
{
    t_stack *min;
    int len_a;
    
    len_a = ft_lstsize(*A);
    while(len_a-- > 3)
        push(A, B, "pb");
    sort_3(A);
    while(B && *B)
    {   
        init_nodes(*A, *B);
        move_nodes(A, B);
    }
    update_position(*A);
    min = ft_lstget_minnode(*A);
    if(min->above_median == 1)
        while(*A != min)
            rotate(A, "ra");
    else
        while(*A != min)
            r_rotate(A, "rra");
}