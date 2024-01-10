/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:59:57 by msaadidi          #+#    #+#             */
/*   Updated: 2024/01/09 20:04:03 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    update_rank(t_stack **stack)
{
    int i;
    
    if (!stack || !(*stack))
        return ;
    i = 0;
    while(*stack)
    {
        (*stack)->rank = i;
        i++;
        (*stack) = (*stack)->next;
    }
}

int calculate_moves(t_stack **A, t_stack **B)
{
    
}