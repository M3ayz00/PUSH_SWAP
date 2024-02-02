/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m3ayz00 <m3ayz00@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:54:25 by m3ayz00           #+#    #+#             */
/*   Updated: 2024/02/02 02:45:10 by m3ayz00          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack **stack)
{
	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	if (((*stack)->data > (*stack)->next->data))
		swap(stack, "sa");
}

void	sort_3(t_stack **stack)
{
	if (!stack || !(*stack) || !(*stack)->next || !(*stack)->next->next)
		return ;
	if ((*stack)->data == ft_lstget_max(*stack))
		rotate(stack, "ra");
	if ((*stack)->next->data == ft_lstget_max(*stack))
		r_rotate(stack, "rra");
	if ((*stack)->data > (*stack)->next->data)
		swap(stack, "sa");
}

void	init_nodes(t_stack *A, t_stack *B)
{
	update_position(A);
	update_position(B);
	set_target_node(A, B);
	set_push_cost(A, B);
}

void	move_nodes(t_stack **A, t_stack **B)
{
	t_stack	*cheapest;

	cheapest = get_cheapest(*B);
	// printf("cheapest's data : %d and its push cost %d\n", cheapest->data, cheapest->push_cost);
	if (cheapest->above_median == 1 && cheapest->target->above_median == 1)
		rotate_both(A, B, cheapest);
	else if (cheapest->above_median == 0 && cheapest->target->above_median == 0)
		r_rotate_both(A, B, cheapest);
	last_rotations(B, cheapest, 'b');
	last_rotations(A, cheapest->target, 'a');
	push(B, A, "pa");
}


int partitions(int *arr, int start, int end)
{
    int pivot = arr[end];
    int j = start;
    int i = start - 1;
    while(j <= end)
    {
        if(arr[j] < pivot)
        {
            i++;
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
        j++;
    }
    i++;
    int temp = arr[i];
    arr[i] = arr[end];
    arr[end] = temp;
    return (i);
}

void    quicksort(int *arr, int start, int end)
{
    if (start >= end)
        return ;
    int pivot = partitions(arr, start, end);
    quicksort(arr, start, pivot - 1);
    quicksort(arr, pivot + 1 , end);
}

int *list_to_arr(t_stack *stack)
{
    int *arr = (int *)malloc(sizeof(int) * ft_lstsize(stack));
    int i = 0;
    int size = ft_lstsize(stack);
    while(stack)
    {
        arr[i] = stack->data;
        i++;
        stack = stack->next;
    }
    quicksort(arr, 0, size - 1);
    return (arr);
}

t_stack *ft_lstget_median(t_stack *stack)
{
    int *arr = list_to_arr(stack);
    int size = ft_lstsize(stack);
    int median = arr[size / 2];
    while(stack)
    {
        if (stack->data == median)
		{
    		free(arr);
            return (stack);
		}
        stack = stack->next;
    }
    return (NULL);
}

void	push_to_b(t_stack **A, t_stack **B)
{
	int		len_a;
	t_stack	*median = ft_lstget_median(*A);

	len_a = ft_lstsize(*A);
	while (len_a-- > 3)
	{
		if((*A)->data < median->data)
			push(A, B, "pb");
		else
		{
			push(A, B, "pb");
			rotate(B, "rb");
		}
	}
}

void	push_swap(t_stack **A, t_stack **B)
{
	t_stack	*min;

	push_to_b(A, B);
	sort_3(A);
	while (B && *B)
	{
		init_nodes(*A, *B);
		move_nodes(A, B);
	}
	update_position(*A);
	min = ft_lstget_minnode(*A);
	if (min->above_median == 1)
		while (*A != min)
			rotate(A, "ra");
	else
		while (*A != min)
			r_rotate(A, "rra");
}
