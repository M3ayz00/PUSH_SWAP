/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:29:11 by msaadidi          #+#    #+#             */
/*   Updated: 2024/01/07 20:24:19 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

t_stack	*lst_new(int data)
{
	t_stack	*lst;
	
	lst = malloc(sizeof(t_stack));
	if(!lst)
	{
		free(lst);
		return (NULL);
	}
	lst->data = data;
	lst->next = NULL;
	return (lst);
}

void	free_all(t_stack **lst)
{
	t_stack *current;

	current = *lst;
	while(current)
	{
		free(current);
		current = current->next;
	}
	lst = NULL;
}

t_stack	*init_stack(char **numbers, int i)
{
	t_stack	*head;
	
	head = NULL;
	while(numbers[i])
	{
		ft_lstadd_back(&head, lst_new(ft_atoi(numbers[i])));
		i++;
	}
	return (head);
}

int	ft_strcmp(char *s1, char *s2)
{
	int i = 0;
	while((s1[i] || s2[i]) && s1[i] == s2[i])
		i++;
	return(s1[i] - s2[i]);
}

int	ft_intcmp(int a, int b)
{
	return(a == b);
}
int check_dups(char **strs, int i)
{
	while(strs[i])
	{
		int c = 0;
		int j = 1;

		while(strs[j])
		{
			if(ft_intcmp(ft_atoi(strs[j]), ft_atoi(strs[i])) == 1)
			{
				if(c == 1)
					return (1);
				else if(c == 0)
					c = 1;
			}
			j++;
		}
		i++;
	}
	return(0);
}

void	check_input(char **strs, int i)
{
	while(strs[i])
	{
		int j = 0;
		while(strs[i][j])
		{	
			if (strs[i][j] == '-' || strs[i][j] == '+')
				j++;
			if (strs[i][j] == '-' || strs[i][j] == '+')
				ft_perror(1, "Error : double signs.\n");
			if (!ft_isdigit(strs[i][j]))
				ft_perror(1, "Error : Invalid input (int).\n");
			j++;
		}
		i++;
	}
}

int is_many(char *str, char c)
{
	while(*str)
	{
		if(*str == c)
			return(1);
		str++;
	}
	return(0);
}
int main(int ac, char **av)
{
	char **numbers = av;
	int i = 1;
	if(ac == 1)
		ft_perror(1, "Error : 0 provided arguments.\n");
	if(ac == 2)
	{
		if(is_many(av[1], ' '))
		{
			ac = ft_wordcount(av[1], ' ') + 1;
			numbers = ft_split(av[1], ' ');
			i = 0;
			if (ac <= 2)
				ft_perror(0, "No actions to be done.\n");
		}
		else
			ft_perror(0, "No actions to be done.\n");
	}
	if(ac > 2)
	{
		t_stack	*head = NULL;
		t_stack *test = NULL;
		check_input(numbers, i);
		if(check_dups(numbers, i))
			ft_perror(1, "Error : No duplicates allowed\n");
		else
			head = init_stack(numbers, i);
		if(ft_lstsize(head) == 2)
			sort_2(&head);
		else if(ft_lstsize(head) == 3)
			sort_3(&head);
		else if(ft_lstsize(head) == 5)
			sort_5(&head, &test);
		// if(ac == 3)
		// {
		// 	ft_lstadd_back(&test, lst_new(123));
		// 	ft_lstadd_back(&test, lst_new(-3));
		// 	r_rotate(&head, "rra");
		// 	while(test)
		// 	{
		// 		printf("STACK B -->%d\n",test->data);
		// 		test = test->next;
		// 	}
		while(head)
		{
			printf("STACK A -->%d\n",head->data);
			head = head->next;
		}
		// }
	}
}