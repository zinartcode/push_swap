/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:12:32 by azinnatu          #+#    #+#             */
/*   Updated: 2018/02/01 16:20:55 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	long_sort(t_stack *stack)
{
	 int	i;
	 int	pivot;
	 int	mid;

	 i = 0;
	 mid = stack->count;
	 // printf("mid is: %d\n", mid);
	 while (mid > 1 && stack->a)
	 {
	 	pivot = mid/2;
	 	if (index_in_list(stack->a, sml(stack->a)) <= pivot)
	 	{
	 		// printf("it's on left\n");
	 		while (stack->a->data != sml(stack->a))
	 		{
	 			if (stack->a->data == big(stack->a))
	 			{
	 				// printf("its big here: %d\n", stack->a->data);
	 				pb(stack);
	 				// rr(stack);
	 				rb(stack);
	 			}
	 			else
	 				ra(stack);
	 		}
	 		pb(stack);
	 	}
	 	else
	 	{
	 		while (last(stack->a) != sml(stack->a))
	 		{
	 	 		if (last(stack->a) == big(stack->a))
	 			{
	 				rra(stack);
	 				pb(stack);
	 				rb(stack);
	 			}
	 			else
	 				rra(stack);
	 		}
	 		rra(stack);
	 		pb(stack);
	 	}
	 	mid--;
	 	// printf("mid is: %d\n", mid);
	 	// print_list(stack->b);  //test
	 }
	 b_to_a(stack);
}

void	b_to_a(t_stack *stack)
{
	while(stack->b)
	{
		while (last(stack->b) > stack->b->data)
		{
			rrb(stack);
		}
		pa(stack);
		// printf("sorted b is: ");
		// print_list(stack->b);  //test
	}
}

// void	long_sort(t_stack *stack)
// {
// 	 int	i;
// 	 int	pivot;
// 	 int	mid;

// 	 i = 0;
// 	 mid = stack->count;
// 	 printf("mid is: %d\n", mid);
// 	 while (mid != 0)
// 	 {
// 	 	pivot = mid/2;
// 	 	if (index_in_list(stack->a, sml(stack->a)) < pivot)
// 	 	{
// 	 		// printf("it's on left\n");
// 	 		while (stack->a->data != sml(stack->a))
// 	 		{
// 	 			ra(stack);
// 	 		}
// 	 		pb(stack);
// 	 	}
// 	 	else
// 	 	{
// 	 		// printf("it's on right\n");
// 	 		while (last(stack->a) != sml(stack->a))
// 	 		{
// 	 			rra(stack);
// 	 		}
// 	 		rra(stack);
// 	 		pb(stack);
// 	 	}
// 	 	mid--;
// 	 }
// }

