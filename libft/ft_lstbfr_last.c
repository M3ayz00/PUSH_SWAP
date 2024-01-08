/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstbfr_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m3ayz00 <m3ayz00@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:26:25 by msaadidi          #+#    #+#             */
/*   Updated: 2024/01/07 23:24:41 by m3ayz00          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

t_stack *ft_lstbfr_last(t_stack *stack)
{
    if (!stack || !stack->next)
        return (NULL);
    while(stack->next->next)
        stack = stack->next;
    return (stack);
}