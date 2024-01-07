/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:27:48 by msaadidi          #+#    #+#             */
/*   Updated: 2024/01/07 15:27:49 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	d;
	size_t	s;

	if (dstsize == 0 && !dst)
		return (0);
	i = 0;
	d = ft_strlen(dst);
	s = ft_strlen(src);
	j = d;
	if (dstsize <= d)
		return (s + dstsize);
	while (src[i] && i < dstsize - d - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (d + s);
}

// int main(void)
// {
// 	char src[] = "khiar";
// 	char dst[] = "Oussama ";
// 	int x = ft_strlcat(dst, src, 14);
// 	printf("%s\n%d", dst, x);
// 	return (0);
// }