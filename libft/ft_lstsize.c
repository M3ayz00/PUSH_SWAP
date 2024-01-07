/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m3ayz00 <m3ayz00@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:07:22 by elel-yak          #+#    #+#             */
/*   Updated: 2024/01/07 01:13:43 by m3ayz00          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

// int main()
// {
//     t_stack *head;
//     t_stack *second;
//     t_stack *third;
//     t_stack *fourth;
//     head = (t_stack *)malloc(sizeof(t_stack));
//     second = (t_stack *)malloc(sizeof(t_stack));
//     third = (t_stack *)malloc(sizeof(t_stack));
//     fourth = (t_stack *)malloc(sizeof(t_stack));
//     int i = 0;
//     head->content = 1;
//     head->next = second;
//     second->content = 2;
//     second->next = third;
//     third->content = 3;
//     third->next = fourth;
//     fourth->content = 4;
//     fourth->next = NULL;
//     printf("%i\n", ft_lstsize(head));
// }