/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m3ayz00 <m3ayz00@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 18:42:52 by elel-yak          #+#    #+#             */
/*   Updated: 2024/01/07 01:14:07 by m3ayz00          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*ft_lstnew(int data)
{
	t_stack	*lst;

	lst = (t_stack *)malloc(sizeof(t_stack));
	if (!lst)
		return (0);
	lst->data = data;
	lst->next = 0;
	return (lst);
}

