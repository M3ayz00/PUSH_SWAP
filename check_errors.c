/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m3ayz00 <m3ayz00@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:20:49 by m3ayz00           #+#    #+#             */
/*   Updated: 2024/02/02 02:01:48 by m3ayz00          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_dups(char **strs, int i)
{
	int	j;

	while (strs[i])
	{
		j = i + 1;
		while (strs[j])
		{
			if (ft_intcmp(ft_atoi(strs[j]), ft_atoi(strs[i])) == 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	check_input(char **strs, int i)
{
	int	j;

	if (check_dups(strs, i) == 0)
	{
		while (strs[i])
		{
			j = 0;
			while (strs[i][j])
			{
				if (strs[i][j] == '-' || strs[i][j] == '+')
					j++;
				if (strs[i][j] == '-' || strs[i][j] == '+')
					ft_perror(1, "Error\n");
				if (!ft_isdigit(strs[i][j]))
					ft_perror(1, "Error\n");
				j++;
			}
			i++;
		}
	}
	else
		ft_perror(1, "Error\n");
}

int	is_many(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

t_stack	*init_stack(char **numbers, int i)
{
	t_stack	*head;
	int		j;

	j = 0;
	head = NULL;
	while (numbers[i])
	{
		ft_lstadd_back(&head, lst_new(ft_atoi(numbers[i]), j));
		j++;
		i++;
	}
	return (head);
}
