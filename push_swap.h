/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:33:05 by msaadidi          #+#    #+#             */
/*   Updated: 2024/01/06 19:08:09 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
    int                 data;
    struct s_stack    *next;
}   t_stack;


# include "libft/libft.h"
# include <stdio.h>

void    swap(int *a, int *b);
void    swap_A(t_stack **A, char *op);
void    swap_B(t_stack **B, char *op);
void    swap_S(t_stack **stackA, t_stack **stackB, char*op);
void    push_A(t_stack **A, t_stack **B, char *op);
void    push_B(t_stack **A, t_stack **B, char *op);
void    push_S(t_stack **A, t_stack **B, char *op);
#endif