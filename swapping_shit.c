/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapping_shit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:29:18 by msaadidi          #+#    #+#             */
/*   Updated: 2024/01/06 19:18:50 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b ;
    *b = tmp;
}

void    swap_A(t_stack **stack, char *op)
{
    if (!stack || !(*stack) || !(*stack)->next)
        return;

    swap(&((*stack)->data), &((*stack)->next->data));
    if(op)
        ft_putstr_endl(op);
}

void    swap_B(t_stack **stack, char *op)
{
    if (!stack || !(*stack) || !(*stack)->next)
        return;

    swap(&((*stack)->data), &((*stack)->next->data));
    if(op)
        ft_putstr_endl(op);
}

void    swap_S(t_stack **stackA, t_stack **stackB, char*op)
{
    if (!stackA || !(*stackA) || !(*stackA)->next)
        return;
    if (!stackB || !(*stackB) || !(*stackB)->next)
        return;
    swap_A(stackA, NULL);
    swap_B(stackB, NULL);
    if(op)
        ft_putstr_endl(op);
}

void    push_A(t_stack **A, t_stack **B, char *op)
{
    if(!B || !(*B))
       return;
    t_stack *temp;
    temp = (*B);
    *B = temp->next;
    if(*A)
        temp->next = *A;
    else
        temp->next = NULL;
    *A = temp;
    if(op)
        ft_putstr_endl(op);
}

void    push_B(t_stack **A, t_stack **B, char *op)
{
    if(!A || !(*A))
       return;
    t_stack *temp;
    temp = (*A);
    *A = temp->next;
    if(*B)
        temp->next = *B;
    else
        temp->next = NULL;
    *B = temp;
    if(op)
        ft_putstr_endl(op);
}

void    push_S(t_stack **A, t_stack **B, char *op)
{
    t_stack *temp;
    push_A(A, B, NULL);
    printf("data pushed to A : %d\n", (*A)->data);
    temp = *A;
    temp = temp->next;
    push_B(&temp, B, NULL);
    printf("data pushed to B : %d\n", (*B)->data);
    if(op)
         ft_putstr_endl(op);
}