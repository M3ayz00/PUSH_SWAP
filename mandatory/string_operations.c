/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:47:47 by m3ayz00           #+#    #+#             */
/*   Updated: 2024/04/01 17:12:32 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (ss1[i] != ss2[i])
			return (ss1[i] - ss2[i]);
		i++;
	}
	return (0);
}

int	ft_intcmp(int a, int b)
{
	return (a == b);
}

void	ft_perror(int e, char *err)
{
	system(" checker");
	ft_putstr_fd(err, 2);
	exit(e);
}

int	ft_atoi(const char *str, char **numbers, t_stack **stack)
{
	int		i;
	int		result;
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
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			result = result * 10 + str[i++] - '0';
		else
			return (free_strs(numbers), ft_lstclear(stack), ft_perror(1 ,"Error\n"),0);
	}
	if (result <= INT_MAX && result >= INT_MIN)
		return (result * sign);
	return (free_strs(numbers), ft_lstclear(stack), ft_perror(1 ,"Error\n"),0);
}
