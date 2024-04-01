/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:29:11 by msaadidi          #+#    #+#             */
/*   Updated: 2024/04/01 21:29:49 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_dups(t_stack *stack)
{
	t_stack	*curr1;
	t_stack	*curr2;

	curr1 = stack;
	while (curr1)
	{
		curr2 = curr1->next;
		while (curr2)
		{
			if (ft_intcmp(curr1->data, curr2->data) == 1)
				return (1);
			curr2 = curr2->next;
		}
		curr1 = curr1->next;
	}
	return (0);
}

int	check_input(char **strs)
{
	int	j;
	int	i;

	i = -1;
	while (strs[++i])
	{
		j = -1;
		while (strs[i][++j])
		{
			if (strs[i][j] == '-' || strs[i][j] == '+')
				++j;
			if (strs[i][j] == '-' || strs[i][j] == '+'
			|| !ft_isdigit(strs[i][j]))
				return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

void	init_stack(char **numbers, t_stack **stack)
{
	int		i;

	i = -1;
	while (numbers[++i])
		ft_lstadd_back(stack, lst_new(ft_atoi(numbers[i], numbers, stack)));
}

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
	int		i;
	char	**tmp;
	t_stack	*stack;

	i = -1;
	stack = NULL;
	while (++i < ac - 1)
	{
		tmp = ft_split(av[i + 1], " \t");
		if (!tmp)
			return (free_strs(tmp), ft_lstclear(&stack), NULL);
		if (check_input(tmp))
			return (free_strs(tmp), ft_lstclear(&stack), NULL);
		init_stack(tmp, &stack);
		free_strs(tmp);
	}
	if (check_dups(stack))
		return (ft_lstclear(&stack), NULL);
	return (stack);
}
