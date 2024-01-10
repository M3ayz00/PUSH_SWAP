/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget_minnode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m3ayz00 <m3ayz00@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:59:09 by m3ayz00           #+#    #+#             */
/*   Updated: 2024/01/10 16:11:52 by m3ayz00          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack *ft_lstget_minnode(t_stack *stack)
{
    t_stack *min_node;
    int min;

    min = ft_lstget_min(stack);
    min_node = stack;
    while(stack)
    {
        if (min == stack->data)
            min_node = stack;
        stack = stack->next;
    }
    return (min_node);
}