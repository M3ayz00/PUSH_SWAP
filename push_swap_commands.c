/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:54:25 by m3ayz00           #+#    #+#             */
/*   Updated: 2024/02/03 16:42:17 by msaadidi         ###   ########.fr       */
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
void	init_nodesa(t_stack *A, t_stack *B)
{
	update_position(A);
	update_position(B);
	set_target_nodea(A, B);
	set_push_cost(A, B);
}

void	move_nodes(t_stack **A, t_stack **B)
{
	t_stack	*cheapest;

	cheapest = get_cheapest(*B);
	if (cheapest->above_median == 1 && cheapest->target->above_median == 1)
		rotate_both_b(A, B, cheapest);
	else if (cheapest->above_median == 0 && cheapest->target->above_median == 0)
		r_rotate_both_b(A, B, cheapest);
	last_rotations(B, cheapest, 'b');
	last_rotations(A, cheapest->target, 'a');
	push(B, A, "pa");
}
void	move_nodesa(t_stack **A, t_stack **B)
{
	t_stack	*cheapest;

	cheapest = get_cheapest(*A);
	if (cheapest->above_median == 1 && cheapest->target->above_median == 1)
		rotate_both_a(A, B, cheapest);
	else if (cheapest->above_median == 0 && cheapest->target->above_median == 0)
		r_rotate_both_a(A, B, cheapest);
	last_rotations(A, cheapest, 'a');
	last_rotations(B, cheapest->target, 'b');
	push(A, B, "pb");
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

	len_a = ft_lstsize(*A);
	push(A, B ,"pb");
	push(A, B, "pb");
	while (len_a-- > 3)
	{
		init_nodesa(*B, *A);
		move_nodesa(A, B);
	}
}

void push_lower_nodes(t_stack **A, t_stack **B, t_stack *median, int *iterations)
{
	t_stack *curr_top = *A;
	t_stack *current_bot = ft_lstlast(curr_top);

	while (current_bot->data < median->data && *iterations > 0)
	{
		r_rotate(A, "rra");
		push(A, B, "pb");
		current_bot = ft_lstlast(*A);
		(*iterations)--;
	}
}

void push_middle_nodes(t_stack **A, t_stack **B, t_stack *median, int *iterations)
{
	t_stack *curr_top = *A;

	while (*iterations > 0)
	{
		// printf("data : %d///size_chunk : %d\n", (*A)->data, (*A)->size_chunk);
		curr_top = *A;
		if (curr_top->data >= median->data)
			rotate(A, "ra");
		else if (curr_top->data < median->data)
		{
			push(A, B, "pb");
			(*iterations)--;
		}
	}
}

void oof_a(t_stack **A, t_stack **B)
{
	t_stack *median;
	t_stack *curr_top = *A;
	int size = ft_lstsize(curr_top);
	int iterations;
	while (size > 3)
	{
		iterations = size / 2;
		median = ft_lstget_median(curr_top);
		push_lower_nodes(A, B, median, &iterations);
		push_middle_nodes(A, B, median, &iterations);
		curr_top = *A;
		size = ft_lstsize(curr_top);
	} 
	sort_3(A);
}

void	push_swap(t_stack **A, t_stack **B)
{
	t_stack	*min;

	// manage_stack_a(A, B);
	// oof_a(A, B);
	push_to_b(A, B);
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
