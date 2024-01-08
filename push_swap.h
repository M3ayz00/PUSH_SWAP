/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m3ayz00 <m3ayz00@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:29:14 by msaadidi          #+#    #+#             */
/*   Updated: 2024/01/08 00:12:09 by m3ayz00          ###   ########.fr       */
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

void    swap_data(int *a, int *b);
void    swap(t_stack **B, char *op);
void    swap_S(t_stack **A, t_stack **B, char*op);
void    push(t_stack **A, t_stack **B, char *op);
void    rotate(t_stack **stack, char *op);
void    rotate_S(t_stack **A, t_stack **B ,char *op);
void    r_rotate(t_stack **stack, char *op);
void    r_rotate_S(t_stack **A, t_stack **B, char *op);
void    sort_2(t_stack **stack);
void    sort_3(t_stack **stack);

void    sort_5(t_stack **A, t_stack **B);
#endif