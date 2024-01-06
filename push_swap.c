/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:40:50 by msaadidi          #+#    #+#             */
/*   Updated: 2024/01/06 19:10:18 by msaadidi         ###   ########.fr       */
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

void	lst_add_back(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	if(!(*lst))
	{
		*lst = new;
		return ;
	}
	t_stack	*current = *lst;
	while(current->next)
		current = current->next;
	current->next = new;
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
		lst_add_back(&head, lst_new(ft_atoi(numbers[i])));
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

int check_dups(char **strs)
{
	int i = 1;

	while(strs[i])
	{
		int c = 0;
		int j = 1;
		while(strs[j])
		{
			if(ft_strcmp(strs[j], strs[i]) == 0)
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
			ac = count_words(av[1], ' ') + 1;
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
		if(check_dups(numbers))
			ft_perror(1, "Error : No duplicates allowed\n");
		else
			head = init_stack(numbers, i);
		if(ac == 3)
		{
			t_stack *test = NULL;
			lst_add_back(&test, lst_new(123));
			push_S(&head, &test, "pp");
			while(test)
			{
				printf("STACK B -->%d\n",test->data);
				test = test->next;
			}
			while(head)
			{
				printf("STACK A -->%d\n",head->data);
				head = head->next;
			}
		}
		// while(head)
		// {
		// 	printf("%d, ",head->data);
		// 	head = head->next;
		// }
		printf("\n");
		
	}
}