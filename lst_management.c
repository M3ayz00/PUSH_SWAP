/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m3ayz00 <m3ayz00@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:43:40 by m3ayz00           #+#    #+#             */
/*   Updated: 2024/01/10 21:57:34 by m3ayz00          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*lst_new(int data, int index)
{
	t_stack	*lst;
	
	lst = malloc(sizeof(t_stack));
	if(!lst)
	{
		free(lst);
		return (NULL);
	}
	lst->cheapest = 0;
	lst->index = index;
	lst->data = data;
	lst->next = NULL;
	return (lst);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!lst || !new)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}


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

void	ft_lstclear(t_stack **lst)
{
	t_stack	*curr;
	t_stack	*next;

	if (!(lst && *lst))
		return ;
	curr = *lst;
	while (curr != NULL)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	*lst = NULL;
}

int ft_islst_sorted(t_stack **stack)
{
    t_stack *curr;
    
    if (!stack || !(*stack) || !(*stack)->next)
        return (0);
    curr = *stack;
    while(curr->next)
    {
        if(curr->data > curr->next->data)
            return (0);
        curr = curr->next;
    }
    return (1);
}