/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:26:22 by msaadidi          #+#    #+#             */
/*   Updated: 2024/01/07 15:26:23 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (!(lst && new))
		return ;
	new->next = *lst;
	*lst = new;
}
