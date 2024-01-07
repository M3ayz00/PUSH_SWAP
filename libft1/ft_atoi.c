/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m3ayz00 <m3ayz00@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:12:06 by elel-yak          #+#    #+#             */
/*   Updated: 2024/01/07 01:45:31 by m3ayz00          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	size_t	result;

	i = 0;
	result = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
		ft_perror(1, "Error : double signs.\n");
	if (!ft_isdigit(str[i]))
		ft_perror(1, "Error : Please provide a valid argument (int).\n");
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + str[i++] - '0';
		if (!ft_isdigit(str[i]) && str[i] != '\0')
			ft_perror(1, "Error : Please provide a valid argument (int).\n");
	}
	if (result > INT_MAX)
		ft_perror(1, "Error : value greater than INT_MAX.\n");
	return (result * sign);
}
