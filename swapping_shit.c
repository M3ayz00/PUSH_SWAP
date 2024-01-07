/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapping_shit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m3ayz00 <m3ayz00@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:29:18 by msaadidi          #+#    #+#             */
/*   Updated: 2024/01/07 04:35:32 by m3ayz00          ###   ########.fr       */
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

    swap_data(&((*stack)->data), &((*stack)->next->data));
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
    
    if (!A || !(*A))
       return ;
    temp = (*A);
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
    
    if (!stack || !(*stack) || !(*stack)->next)
        return;
    bfrlast = ft_lstbfr_last(*stack);
    first = *stack;
    first->next = bfrlast->next;
    bfrlast->next = NULL;
    
    if (op)
        ft_putendl_fd(op, 1);
}