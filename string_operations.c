/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:47:47 by m3ayz00           #+#    #+#             */
/*   Updated: 2024/03/28 22:20:52 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] || s2[i]) && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_intcmp(int a, int b)
{
	return (a == b);
}

void	ft_perror(int e, char *err)
{
	system("leaks --fullStacks push_swap");
	ft_putstr_fd(err, 2);
	exit(e);
}

int	ft_atoi(const char *str, char **numbers, t_stack **stack)
{
	int		i;
	size_t	result;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
		result = result * 10 + str[i++] - '0';
	if (result >= INT_MAX)
		return (free_strs(numbers), ft_lstclear(stack), ft_perror(1 ,"1Error\n"),0);
	return (result * sign);
}
