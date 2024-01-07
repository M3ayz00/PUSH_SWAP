/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:26:55 by msaadidi          #+#    #+#             */
/*   Updated: 2024/01/07 15:26:56 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*x;
	unsigned char	*z;

	x = (unsigned char *)s1;
	z = (unsigned char *)s2;
	while (n--)
	{
		if (*x != *z)
			return ((int)(*x - *z));
		x++;
		z++;
	}
	return (0);
}
