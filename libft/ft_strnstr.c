/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:28:09 by msaadidi          #+#    #+#             */
/*   Updated: 2024/01/07 15:28:10 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*needle)
		return ((char *)haystack);
	j = 0;
	while (j < len && len != 0 && *haystack)
	{
		if (*haystack == *needle)
		{
			i = 1;
			while (needle[i] == haystack[i] && needle[i] && j + i < len)
				i++;
			if (!needle[i])
				return ((char *)haystack);
		}
		haystack++;
		j++;
	}
	return (0);
}
