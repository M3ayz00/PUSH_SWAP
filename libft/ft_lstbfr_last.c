/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstbfr_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:26:25 by msaadidi          #+#    #+#             */
/*   Updated: 2024/01/07 15:26:26 by msaadidi         ###   ########.fr       */
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