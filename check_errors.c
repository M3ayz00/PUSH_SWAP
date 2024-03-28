/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:20:49 by m3ayz00           #+#    #+#             */
/*   Updated: 2024/03/28 22:26:34 by msaadidi         ###   ########.fr       */
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
		while(curr2)
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
			if (strs[i][j] == '-' || strs[i][j] == '+' || !ft_isdigit(strs[i][j]))
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
		ft_lstadd_back(stack, lst_new(ft_atoi(numbers[i],numbers, stack)));
}
