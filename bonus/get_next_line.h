/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 19:34:03 by msaadidi          #+#    #+#             */
/*   Updated: 2024/04/01 21:09:14 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdint.h>
# include "../mandatory/push_swap.h"

# define BUFFER_SIZE 10

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*read_file(int fd, char *container);
char	*gget_line(char *container);
char	*update_container(char *container);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strchr(char *str, int c);
size_t	ft_strlen(char *str);
void	*ft_memcpy(void *dest, void *src, size_t n);
void	*ft_calloc(size_t num_elements, size_t element_size);

#endif