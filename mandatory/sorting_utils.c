/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:39:50 by msaadidi          #+#    #+#             */
/*   Updated: 2024/04/01 20:33:06 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

