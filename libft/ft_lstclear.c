/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:26:28 by msaadidi          #+#    #+#             */
/*   Updated: 2024/01/07 15:26:29 by msaadidi         ###   ########.fr       */
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