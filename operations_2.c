/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m3ayz00 <m3ayz00@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:25:21 by msaadidi          #+#    #+#             */
/*   Updated: 2024/01/10 21:18:11 by m3ayz00          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


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
