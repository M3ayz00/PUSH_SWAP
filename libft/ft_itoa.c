/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:26:16 by msaadidi          #+#    #+#             */
/*   Updated: 2024/01/07 15:26:17 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

static int	digit_count(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*result;
	long	num;
	int		digit;

	num = n;
	digit = digit_count(n);
	if (n < 0)
	{
		num *= -1;
		digit++;
	}
	result = malloc(digit + 1);
	if (!result)
		return (0);
	result[digit] = '\0';
	while (digit--)
	{
		result[digit] = num % 10 + '0';
		num /= 10;
	}
	if (n < 0)
		result[0] = '-';
	return (result);
}

// int main()
// {
// 	printf("%s\n", ft_itoa(0000000001));
// }
