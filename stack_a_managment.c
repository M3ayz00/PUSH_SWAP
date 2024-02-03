// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   stack_a_managment.c                                :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/02/02 17:05:01 by msaadidi          #+#    #+#             */
// /*   Updated: 2024/02/02 17:05:02 by msaadidi         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "push_swap.h"

// void	*ft_memcpy(void *dest, const void *src, size_t n)
// {
// 	unsigned char		*d;
// 	unsigned char		*s;

// 	if (!src && !dest)
// 		return (NULL);
// 	d = (unsigned char *)dest;
// 	s = (unsigned char *)src;
// 	while (n--)
// 		*d++ = *s++;
// 	return (dest);
// }

// void	*ft_memset(void *s, int c, size_t n)
// {
// 	unsigned char	*p;

// 	p = (unsigned char *)s;
// 	while (n--)
// 		*p++ = (unsigned char)c;
// 	return (s);
// }
// void	ft_bzero(void *s, size_t n)
// {
// 	ft_memset(s, 0, n);
// }

// int count_ones(int *arr, int size)
// {
//     int i;
//     int count;

//     i = 0;
//     count = 0;
//     while(i < size)
//     {
//         if(arr[i] == 1)
//             count++;
//         i++;
//     }
//     return (count); 
// }

// void    apply_movements(t_stack **a, t_stack **b, int *arr)
// {
//     t_stack *median = ft_lstget_median(*a);
//     // push_median_to_B(a, b);
//     while (*a)
//     {
//         if (ft_islst_sorted(a))
//             break;
//         if (arr[(*a)->index] == 0)
//         {
//             if((*a)->data <= median->data)
//                 push(a, b, "pb");
//             else if((*a)->data > median->data)
//             {
//                 push(a, b, "pb");
//                 rotate(b, "rb");
//             }
//         }
//         else if (arr[(*a)->index] == 1)
//             rotate(a, "ra");
//     }
// }

// int *find_longest_sequence(t_stack *stack)
// {
//     int     *flags;
//     t_stack *curr;
//     t_stack *head;
//     int     *curr_flags;
//     int     stack_len;
//     int     count;
//     int     cmp;

//     stack_len = ft_lstsize(stack);
//     flags = (int *)malloc(sizeof(int) * stack_len);
//     ft_bzero(flags, stack_len * sizeof(int));
//     head = stack;
//     while(stack)
//     {
//         count = 0;
//         curr = stack;
//         cmp = curr->data;
//         curr_flags = (int *)malloc(sizeof(int) * stack_len);
//         ft_bzero(curr_flags, stack_len * sizeof(int));
//         curr_flags[curr->index] = 1;
//         while (count < stack_len)
//         {
//             if (curr->data > cmp)
//             {
//                 curr_flags[curr->index] = 1;
//                 cmp = curr->data;
//             }
//             count++;
//             curr = curr->next;
//             if(curr == NULL)
//                 curr = head;
//         }
//         int count_flags = count_ones(flags, stack_len);
//         int count_curr_flags = count_ones(curr_flags, stack_len);
//         if (count_flags < count_curr_flags)
//             ft_memcpy(flags, curr_flags, stack_len * sizeof(int));
//         free(curr_flags);
//         stack = stack->next;
//     }
//     return (flags);
// }

// void    manage_stack_a(t_stack **A, t_stack **B)
// {
//     update_position(*A);
//     if(!ft_islst_sorted(A))
//     {
//         int *arr = find_longest_sequence(*A);
//         apply_movements(A, B, arr);
//         free(arr);
//     }
// }