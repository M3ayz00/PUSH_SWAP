/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m3ayz00 <m3ayz00@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:54:25 by m3ayz00           #+#    #+#             */
/*   Updated: 2024/01/10 16:06:04 by m3ayz00          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *get_cheapest(t_stack *stack)
{
    t_stack *cheapest;
    int min;
    
    min = stack->push_cost;
    cheapest = stack;
    while(stack->next)
    {
        if(stack->push_cost < min)
        {
            min = stack->push_cost;
            cheapest = stack;
        }
        stack = stack->next;
    }
    return (cheapest);
}

void    update_position(t_stack *stack)
{
    int i;
    int median;
    
    i = 0;
    median = ft_lstsize(stack) / 2;
    while(stack)
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

void    set_push_cost(t_stack *A, t_stack *B)
{
    while(B)
    {
        B->push_cost = 0;
        if(B->target_node)
        {
            if(B->above_median == 0)
                B->push_cost = ft_lstsize(B) - B->index;
            if(B->target_node->above_median == 1)
                B->push_cost += B->target_node->index ;
            else
                B->push_cost += ft_lstsize(A) - B->target_node->index;
        }
        B = B->next;
    }   
}

void    set_target_node(t_stack *A, t_stack *B)
{
    t_stack *curr;
    t_stack *target;
    long    match;

    while(B)
    {
        curr = A;
        match = LONG_MAX;
        while(curr)
        {
            if(curr->data > B->data && curr->data < match)
            {
                match = curr->data;
                target = curr;
            }
            curr = curr->next;
        }
        if (match == LONG_MAX)
            B->target_node = ft_lstget_minnode(A);
        else
            B->target_node = target;
        B = B->next;
    }
    
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
    else if (cheapest->above_median == 0 && cheapest->above_median == 0)
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
        // t_stack *curr = *A;
        // while(curr)
		// {
		// 	printf("STACK A -->%d\n",curr->data);
		// 	curr = curr->next;
		// }
        // printf("\n_______________\n");
        init_nodes(*A, *B);
        move_nodes(A, B);
        // curr = *A;
        // while(curr)
		// {
		// 	printf("STACK A -->%d\n",curr->data);
		// 	curr = curr->next;
		// }
        // printf("\n_______________\n");
    }
    update_position(*A);
    min = ft_lstget_minnode(*A);
    if(min->above_median == 1)
        while(*A != min)
            rotate(A, "ra");
    else
        while(*A != min)
            r_rotate(A, "rra");
    // swap(A, "sa");
    // rotate(A, "ra");
    // rotate(A, "ra");
}