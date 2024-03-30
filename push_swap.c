/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:29:11 by msaadidi          #+#    #+#             */
/*   Updated: 2024/03/30 21:24:28 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n--)
		*p++ = (unsigned char)c;
	return (s);
}

void	*ft_calloc(size_t num_elements, size_t element_size)
{
	void	*a;

	if (num_elements != 0 && SIZE_MAX / num_elements < element_size)
		return (NULL);
	a = malloc(num_elements * element_size);
	if (!a)
		return (NULL);
	if (num_elements == 0 || element_size == 0)
	{
		ft_memset(a, 0, 1);
		return (a);
	}
	ft_memset(a, 0, element_size * num_elements);
	return (a);
}
void	free_strs(char **strs)
{
	int	i;

	i = -1;
	while (strs && strs[++i])	
		free(strs[i]);
	strs = NULL;
	free(strs);
}

t_stack	*check_args(int ac, char **av)
{
	int	i;
	char	**tmp;
	t_stack	*stack;

	i = -1;
	stack = NULL;
	while (++i < ac - 1)
	{
		tmp = ft_split(av[i + 1], " \t");
		if (!tmp)
			return (free_strs(tmp), ft_lstclear(&stack) ,NULL);
		if (check_input(tmp))
			return (free_strs(tmp), ft_lstclear(&stack) ,NULL);
		init_stack(tmp, &stack);
		free_strs(tmp);
	}
	if (check_dups(stack))
		return (ft_lstclear(&stack), NULL);
	return (stack);
}

void	print_list(t_stack *head)
{
	t_stack *curr = head;
	while (curr)
	{
		printf("%d\n", curr->data);
		curr = curr->next;
	}
}

int	main(int ac, char **av)
{
	t_stack	*head;

	if(ac == 1)
		ft_perror(1, NULL);
	head = check_args(ac, av);
	if (!head)
		ft_perror(1, "Error\n");
	if(!ft_islst_sorted(&head))
	{		
		if(ft_lstsize(head) == 2)
			sort_2(&head);
		else if(ft_lstsize(head) == 3)
			sort_3(&head);
		else if (ft_lstsize(head) > 3)
			push_swap(&head);
	}
	ft_lstclear(&head);
}