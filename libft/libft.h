/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m3ayz00 <m3ayz00@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:28:33 by msaadidi          #+#    #+#             */
/*   Updated: 2024/01/10 18:24:04 by m3ayz00          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <stddef.h>
# include <stdint.h>
# include "../push_swap.h"


int		ft_isdigit(int c);
int		ft_atoi(const char *str);
void	ft_perror(int e, char *err);
int		ft_wordcount(const char *s, char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
int		ft_lstsize(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstclear(t_stack **lst, void (*del)(int));
t_stack *ft_lstbfr_last(t_stack *stack);
int     ft_islst_sorted(t_stack **stack);
int     ft_lstget_min(t_stack *stack);
int     ft_lstget_max(t_stack *stack);
t_stack *ft_lstget_minnode(t_stack *stack);


#endif
