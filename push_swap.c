/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:29:11 by msaadidi          #+#    #+#             */
/*   Updated: 2024/01/11 13:09:58 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int	main(int ac, char **av)
{
	char	**numbers;
	int		i;

	numbers = av;
	i = 1;
	if(ac == 1 || (ac == 2 && !av[1][0]))
		ft_perror(1, "Error : 0 provided arguments.\n");
	if(ac == 2)
	{
		if(is_many(av[1], ' '))
		{
			ac = ft_wordcount(av[1], ' ') + 1;
			if (ac <= 2)
				ft_perror(0, "No actions to be done.\n");
			numbers = ft_split(av[1], ' ');
			i = 0;
		}
		else
			ft_perror(0, "No actions to be done.\n");
	}
	if(ac > 2)
	{
		t_stack	*head = NULL;
		t_stack *test = NULL;
		check_input(numbers, i);
		head = init_stack(numbers, i);
		if(!ft_islst_sorted(&head))
		{		
			if(ft_lstsize(head) == 2)
				sort_2(&head);
			else if(ft_lstsize(head) == 3)
				sort_3(&head);
			else if (ft_lstsize(head) > 3)
				push_swap(&head, &test);
		}
		ft_lstclear(&head);
	}
	// system("Leaks ./push_swap");
}