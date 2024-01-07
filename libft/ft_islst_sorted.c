/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islst_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:33:51 by msaadidi          #+#    #+#             */
/*   Updated: 2024/01/07 20:19:44 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_islst_sorted(t_stack **stack)
{
    t_stack *curr;
    
    if (!stack || !(*stack) || !(*stack)->next)
        return (0);
    curr = *stack;
    while(curr->next)
    {
        if(curr->data > curr->next->data)
            return (0);
        curr = curr->next;
    }
    return (1);
    
}