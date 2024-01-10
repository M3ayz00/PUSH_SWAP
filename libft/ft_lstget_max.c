/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m3ayz00 <m3ayz00@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:51:54 by m3ayz00           #+#    #+#             */
/*   Updated: 2024/01/10 11:54:41 by m3ayz00          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

int ft_lstget_max(t_stack *stack)
{
    int max;

    max = stack->data;
    while(stack->next)
    {
        if(max < stack->next->data)
            max = stack->next->data;
        stack = stack->next;
    }
    return (max);
}