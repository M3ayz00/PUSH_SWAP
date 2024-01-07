/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:25:47 by msaadidi          #+#    #+#             */
/*   Updated: 2024/01/07 15:25:48 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if (size && count > (SIZE_MAX) / size)
		return (0);
	p = malloc (size * count);
	if (p == 0)
		return (p);
	ft_bzero (p, count * size);
	return (p);
}
