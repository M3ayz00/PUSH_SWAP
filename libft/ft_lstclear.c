/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m3ayz00 <m3ayz00@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:29:12 by elel-yak          #+#    #+#             */
/*   Updated: 2024/01/07 01:16:33 by m3ayz00          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_stack **lst, void (*del)(int))
{
	t_stack	*tmp;

	if (!(lst && del))
		return ;
	while (*lst != 0)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(tmp, del);
	}
	*lst = 0;
}

// void    ft_del(void *content)
// {
//     printf("%s\n", content);
// }

// int main()
// {
//     t_stack *head;
//     t_stack *second;
//     t_stack *third;
//     t_stack *fourth;
//     t_stack *ptr;
//     head = (t_stack *)malloc(sizeof(t_stack));
//     second = (t_stack *)malloc(sizeof(t_stack));
//     third = (t_stack *)malloc(sizeof(t_stack));
//     fourth = (t_stack *)malloc(sizeof(t_stack));
//     head->content = "one";
//     head->next = second;
//     second->content = "two";
//     second->next = third;
//     third->content = "three";
//     third->next = fourth;
//     fourth->content = "last";
//     fourth->next = NULL;

//     ft_lstclear(&head, ft_del);
// }