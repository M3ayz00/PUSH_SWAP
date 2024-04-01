#include "push_swap.h"

void    indexing(t_stack *a)
{
    int *arr = list_to_arr(a);
    int arr_size = ft_lstsize(a);
    t_stack *tmp = a;
    while (tmp)
    {
        int i = -1;
        while (++i < arr_size)
        {
            if (tmp->data == arr[i])
            {
                tmp->arr_index = i;
                break;
            }
        }
        tmp = tmp->next;
    }
    free(arr);
}

t_stack *find_node(t_stack *stack, int index, int chunksize)
{
    t_stack *tmp = stack;

    while (tmp)
    {
        if (tmp->arr_index <= index || tmp->arr_index <= index + chunksize)
            return (tmp);
        tmp = tmp->next;
    }
    return (NULL);
}

void    push_to_b(t_stack **a, t_stack **b, int chunksize)
{
    int i = 0;
    int size = ft_lstsize(*a);
    indexing(*a);
    while (i < size)
    {
        printf("%d\n", (*a)->data);
        update_position(*a);
        if ((*a)->arr_index <= i + chunksize)
        {
            push(a, b, "pb");
            i++;
        }
        else if ((*a)->arr_index <= i)
        {
            push(a, b, "pb");
            rotate(b, "rb");
            i++;
        }
        else
            last_rotations(a, find_node(*a, i, chunksize),'a');
    }
}

void    push_to_a(t_stack **a, t_stack **b)
{
    int index;

    while (b)
    {
        index = ft_lstsize(*b) - 1;
        if ((*b)->arr_index != index)
            last_rotations(b, find_node(*b, index, 0), 'b');
        push(b, a, "pa");
    }
}

void    push_swap(t_stack **a, int chunksize)
{
    t_stack *b;

    b = NULL;
    push_to_b(a, &b, chunksize);
    push_to_a(a, &b);
}