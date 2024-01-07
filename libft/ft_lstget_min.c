/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget_min.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:06:11 by msaadidi          #+#    #+#             */
/*   Updated: 2024/01/07 18:40:13 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_lstget_min(t_stack **stack)
{
    t_stack *curr;
    int min;

    curr = *stack;
    min = (*stack)->data;
    while(curr->next)
    {
        if(min > curr->next->data)
            min = curr->next->data;
        curr = curr->next;
    }
    return (min);
}