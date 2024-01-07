/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:26:58 by msaadidi          #+#    #+#             */
/*   Updated: 2024/01/07 15:26:59 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*x;
	char	*z;
	size_t	i;

	i = 0;
	x = (char *)src;
	z = (char *)dest;
	if (dest == src)
		return (dest);
	while (i < n)
	{
		z[i] = x[i];
		i++;
	}
	return (dest);
}
