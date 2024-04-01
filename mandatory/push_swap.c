/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 21:07:47 by msaadidi          #+#    #+#             */
/*   Updated: 2024/04/01 21:14:29 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*head;

	if (ac == 1)
		ft_perror(1, NULL);
	head = check_args(ac, av);
	if (!head)
		ft_perror(1, "Error\n");
	if (!ft_islst_sorted(&head))
	{
		if (ft_lstsize(head) == 2)
			sort_2(&head);
		else if (ft_lstsize(head) == 3)
			sort_3(&head);
		else if (ft_lstsize(head) <= 100)
			push_swap(&head, 15);
		else if (ft_lstsize(head) > 100)
			push_swap(&head, 30);
	}
	ft_lstclear(&head);
}
