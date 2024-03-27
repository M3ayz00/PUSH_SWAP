/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:47:47 by m3ayz00           #+#    #+#             */
/*   Updated: 2024/03/27 23:31:00 by msaadidi         ###   ########.fr       */
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

t_atoi	ft_atoi(const char *str)
{
	int		i;
	t_atoi	atoi;

	i = 0;
	atoi.result = 0;
	atoi.sign = 1;
	atoi.flag = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			atoi.sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
		atoi.result = atoi.result * 10 + str[i++] - '0';
	if (atoi.result > INT_MAX)
		atoi.flag = 1;
	atoi.result *= atoi.sign;
	return (atoi);
}
