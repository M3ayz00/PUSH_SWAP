/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:29:11 by msaadidi          #+#    #+#             */
/*   Updated: 2024/03/31 21:47:18 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	free_strs(char **strs)
{
	int	i;

	i = -1;
	while (strs && strs[++i])	
		free(strs[i]);
	free(strs);
}

t_stack	*check_args(int ac, char **av)
{
	int	i;
	char	**tmp;
	t_stack	*stack;

	i = -1;
	stack = NULL;
	while (++i < ac - 1)
	{
		tmp = ft_split(av[i + 1], " \t");
		if (!tmp)
			return (free_strs(tmp), ft_lstclear(&stack) ,NULL);
		if (check_input(tmp))
			return (free_strs(tmp), ft_lstclear(&stack) ,NULL);
		init_stack(tmp, &stack);
		free_strs(tmp);
	}
	if (check_dups(stack))
		return (ft_lstclear(&stack), NULL);
	return (stack);
}

// void	print_list(t_stack *head)
// {
// 	t_stack *curr = head;
// 	while (curr)
// 	{
// 		printf("%d\n", curr->data);
// 		curr = curr->next;
// 	}
// }

