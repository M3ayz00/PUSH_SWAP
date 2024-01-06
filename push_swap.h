/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:33:05 by msaadidi          #+#    #+#             */
/*   Updated: 2024/01/04 17:29:07 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack_a
{
    int                 data;
    struct s_stack_a    *next;
}   t_stack_a;

typedef struct s_stack_b
{
    int                 data;
    struct s_stack_b    *next;
}   t_stack_b;

# include "LIBFT-main/libft.h"
# include <stdio.h>

#endif