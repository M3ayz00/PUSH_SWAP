/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget_min.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m3ayz00 <m3ayz00@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:06:11 by msaadidi          #+#    #+#             */
/*   Updated: 2024/01/10 11:54:24 by m3ayz00          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_lstget_min(t_stack *stack)
{
    int min;

    min = stack->data;
    while(stack->next)
    {
        if(min > stack->next->data)
            min = stack->next->data;
        stack = stack->next;
    }
    return (min);
}