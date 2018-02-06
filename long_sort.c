/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:12:32 by azinnatu          #+#    #+#             */
/*   Updated: 2018/02/05 16:09:15 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

// void	long_sort(t_stack *stack)
// {
// 	 int	flag;
// 	 int	flag2;
// 	 int	pivot;
// 	 int	mid;

// 	 flag = 0;
// 	 flag2 = 0;
// 	 mid = stack->count;
// 	 // printf("mid is: %d\n", mid);
// 	 // printf("its first big here: %d\n", big(stack->a));
// 	 // printf("its first small here: %d\n", sml(stack->a));
// 	 // printf("its second big here: %d\n", second_big(stack->a));
// 	 // printf("its second small here: %d\n", second_sml(stack->a));
// 	 while (mid > 1 && stack->a)
// 	 {
// 	 	// printf("a is: ");
// 	 	// print_list(stack->a);  //test
// 	 	// printf("b is: ");
// 	 	// print_list(stack->b);  //test

// 	 	pivot = mid/2;
// 	 	// printf ("pivot is: %d\n", pivot);
// 	 	if (index_in_list(stack->a, sml(stack->a)) < pivot)
// 	 	{
// 	 		// printf("it's on left\n");
// 	 		// printf("its small here: %d\n", sml(stack->a));
// 	 		while (stack->a && stack->a->data != sml(stack->a))
// 	 		{
// 	 			if (stack->a->data == big(stack->a) && flag == 0)
// 	 			{
// 	 				// printf("its big here: %d\n", stack->a->data);
// 	 				pb(stack);
// 	 				// check_tail(stack);
// 	 				if (stack->b->data > last(stack->b))
// 	 				{
// 	 					rrb(stack);
// 	 					sb(stack);
// 	 					rb(stack);
// 	 				}
// 	 				rb(stack);
// 	 				check_tail(stack);
// 	 				flag = 1;
// 	 				// print_list(stack->b);  //test
// 	 			}
// 	 			if (stack->a->data == second_big(stack->a) && flag == 1)
// 	 			{
// 	 				// printf("its  second big here: %d\n", stack->a->data);
// 	 				pb(stack);
// 	 				rb(stack);
// 	 				check_tail(stack);
// 	 				flag = 0;
// 	 				// print_list(stack->b);  //test
// 	 			}
// 	 			else if (stack->a->data == second_sml(stack->a))
// 	 			{
// 	 				// printf("its  second sml here: %d\n", stack->a->data);
// 	 				pb(stack);
// 	 			}	 			
// 	 			else
// 	 				ra(stack);
// 	 		}
// 	 		// printf("its sml here: %d\n", stack->a->data);
// 	 		pb(stack);
// 	 		// check_tail(stack);
// 	 		if (stack->b->data > last(stack->b))
// 	 			{
// 	 				rrb(stack);
// 	 				sb(stack);
// 	 				rb(stack);
// 	 			}
// 	 	}
// 	 	else
// 	 	{
// 	 		// printf("it's on right\n");
// 	 		// check_head(stack);
// 	 		while (stack->a && last(stack->a) != sml(stack->a))
// 	 		{
// 	 	 		if (last(stack->a) == big(stack->a) && flag == 0)
// 	 			{
// 	 				rra(stack);
// 	 				pb(stack);
// 	 				rb(stack);
// 	 			}
// 	 			else if (last(stack->a) == second_big(stack->a)) // && flag == 1
// 	 			{
// 	 				// printf("its  second big here: %d\n", stack->a->data);
// 	 				rra(stack);
// 	 				pb(stack);
// 	 				rb(stack);
// 	 				check_tail(stack);
// 	 				flag = 0;
// 	 				// print_list(stack->b);  //test
// 	 			}
// 	 			else if (last(stack->a) == second_sml(stack->a))
// 	 			{
// 	 				// printf("its  second sml here: %d\n", stack->a->data);
// 	 				rra(stack);
// 	 				pb(stack);
// 	 				sb(stack);
// 	 			}
// 	 			else
// 	 				rra(stack);
// 	 		}
// 	 		// printf("its sml here: %d\n", last(stack->a));
// 	 		rra(stack);
// 	 		// pb(stack);
// 	 	}
// 	 	check_head(stack);
// 	 	mid--;
// 	 }
// 	 b_to_a(stack);
// }

// void	b_to_a(t_stack *stack)
// {
// 	while(stack->b)
// 	{
// 		while (last(stack->b) > stack->b->data)
// 		{
// 			rrb(stack);
// 		}
// 		pa(stack);
// 	}
// }

void	check_head(t_stack *stack)
{
	if (stack->b->next != NULL)
	{
		if (stack->b->data < stack->b->next->data)
		{
			sb(stack);
		}
	}
}

void	check_tail(t_stack *stack)
{
	if (stack->b->data > last(stack->b))
	{
		rrb(stack);
		sb(stack);
		rb(stack);
		rb(stack);
	}
}

void	long_sort(t_stack *stack)
{
	 int	i;
	 int	pivot;
	 int	mid;

	 i = 0;
	 mid = stack->count;
	 while (mid != 0)
	 {
	 	pivot = mid/2;
	 	if (index_in_list(stack->a, sml(stack->a)) < pivot)
	 	{
	 		while (stack->a && stack->a->data != sml(stack->a))
	 		{
	 			ra(stack);
	 		}
	 		pb(stack);
	 	}
	 	else
	 	{
	 		while (last(stack->a) != sml(stack->a))
	 		{
	 			rra(stack);
	 		}
	 		rra(stack);
	 		pb(stack);
	 	}
	 	mid--;
	 }
	 // b_to_a(stack);
}

