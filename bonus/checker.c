/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 19:45:51 by msaadidi          #+#    #+#             */
/*   Updated: 2024/04/01 22:01:51 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	apply_moves(t_stack **A, t_stack **B, char *operation)
{
	if (!ft_strncmp(operation, "pa\n", 3))
		push(B, A, NULL);
	else if (!ft_strncmp(operation, "pb\n", 3))
		push(A, B, NULL);
	else if (!ft_strncmp(operation, "sa\n", 3))
		swap(A, NULL);
	else if (!ft_strncmp(operation, "sb\n", 3))
		swap(B, NULL);
	else if (!ft_strncmp(operation, "ss\n", 3))
		swap_s(B, A, NULL);
	else if (!ft_strncmp(operation, "ra\n", 3))
		rotate(A, NULL);
	else if (!ft_strncmp(operation, "rb\n", 3))
		rotate(B, NULL);
	else if (!ft_strncmp(operation, "rr\n", 3))
		rotate_s(A, B, NULL);
	else if (!ft_strncmp(operation, "rra\n", 3))
		r_rotate(A, NULL);
	else if (!ft_strncmp(operation, "rrb\n", 3))
		r_rotate(B, NULL);
	else if (!ft_strncmp(operation, "rrr\n", 3))
		r_rotate_s(A, B, NULL);
	else
		(free(operation), ft_lstclear(A),
			ft_lstclear(B), ft_perror(1, "Error\n"));
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*operation;

	if (ac == 1)
		ft_perror(1, NULL);
	a = check_args(ac, av);
	if (!a)
		ft_perror(1, "Error\n");
	b = NULL;
	operation = get_next_line(0);
	while (operation)
	{
		apply_moves(&a, &b, operation);
		free(operation);
		operation = get_next_line(0);
	}
	if (ft_islst_sorted(&a) && !b)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	ft_lstclear(&a);
	ft_lstclear(&b);
}
