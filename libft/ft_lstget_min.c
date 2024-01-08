/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget_min.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m3ayz00 <m3ayz00@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:06:11 by msaadidi          #+#    #+#             */
/*   Updated: 2024/01/07 22:41:31 by m3ayz00          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_lstget_min(t_stack **stack)
{
    t_stack *curr;
    int min;

    curr = *stack;
    min = curr->data;
    while(curr->next)
    {
        if(min > curr->next->data)
            min = curr->next->data;
        curr = curr->next;
    }
    return (min);
}