/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstbfr_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m3ayz00 <m3ayz00@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 03:46:10 by m3ayz00           #+#    #+#             */
/*   Updated: 2024/01/07 04:35:08 by m3ayz00          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack *ft_lstbfr_last(t_stack *stack)
{
    while(stack && stack->next)
    {
        if(stack->next->next)
        {
            stack = stack->next;
            continue;
        }
        break;
    }
    return (stack);
}