/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapping_shit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m3ayz00 <m3ayz00@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:25:28 by msaadidi          #+#    #+#             */
/*   Updated: 2024/01/10 14:52:38 by m3ayz00          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void    swap_data(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b ;
    *b = tmp;
}

void    swap(t_stack **stack, char *op)
{
    if (!stack || !(*stack) || !(*stack)->next)
        return;
    swap_data(&(*stack)->data, &((*stack)->next->data));
    if(op)
        ft_putendl_fd(op, 1);
}



void    swap_S(t_stack **A, t_stack **B, char*op)
{
    if (!A || !(*A) || !(*A)->next)
        return;
    if (!B || !(*B) || !(*B)->next)
        return;
    swap(A, NULL);
    swap(B, NULL);
    if(op)
        ft_putendl_fd(op, 1);
}


void    push(t_stack **A, t_stack **B, char *op)
{
    t_stack *temp;
    
    if (!A || !(*A) || !B)
       return ;
    temp = *A;
    *A = temp->next;
    if (*B)
        temp->next = *B;
    else
        temp->next = NULL;
    *B = temp;
    
    if(op)
        ft_putendl_fd(op, 1);
}

void    rotate(t_stack **stack, char *op)
{
    t_stack *last;
    t_stack *first;
    
    if (!stack || !(*stack) || !(*stack)->next)
        return;
    first = *stack;
    *stack = (*stack)->next;
    last = ft_lstlast(*stack);
    last->next = first; 
    first->next = NULL;
    
    if (op)
        ft_putendl_fd(op, 1);
}
void    rotate_S(t_stack **A, t_stack** B,char *op)
{
    if (!A || !(*A) || !(*A)->next)
        return;
    if (!B || !(*B) || !(*B)->next)
        return;
    rotate(A, NULL);
    rotate(B, NULL);
    if(op)
        ft_putendl_fd(op, 1);
}

void    r_rotate(t_stack **stack, char *op)
{
    t_stack *bfrlast;
    t_stack *first;
    t_stack *last;
    
    if (!stack || !(*stack) || !(*stack)->next)
        return;
    if(!(*stack)->next->next)
    {
        swap(&(*stack),NULL);
        return ;
    }
    last = ft_lstlast(*stack);
    bfrlast = ft_lstbfr_last(*stack);
    first = *stack;
    *stack = last;
    (*stack)->next = first;
    bfrlast->next = NULL;
    if (op)
        ft_putendl_fd(op, 1);
}

void    r_rotate_S(t_stack **A, t_stack **B, char *op)
{
    if (!A || !(*A) || !(*A)->next)
        return;
    if (!B || !(*B) || !(*B)->next)
        return;
    r_rotate(A, NULL);
    r_rotate(B, NULL);
    if(op)
        ft_putendl_fd(op, 1);
}

void    rotate_both(t_stack **A, t_stack **B, t_stack *cheapest)
{
    while (*A != cheapest->target_node && *B != cheapest)
        rotate_S(A, B, "rr");
    update_position(*A);
    update_position(*B);
}

void    r_rotate_both(t_stack **A, t_stack **B, t_stack *cheapest)
{
    while (*A != cheapest->target_node && *B != cheapest)
        r_rotate_S(A, B, "rrr");
    update_position(*A);
    update_position(*B);
}
void    last_rotations(t_stack **stack, t_stack *top, char c)
{
    while(*stack != top)
    {
        if (c == 'a')
        {
            if(top->above_median == 1)
                rotate(stack, "ra");
            else
                r_rotate(stack, "rra");
        }
        else if (c == 'b')
        {
            if(top->above_median == 1)
                rotate(stack, "rb");
            else
                r_rotate(stack, "rrb");
        }
    }
}