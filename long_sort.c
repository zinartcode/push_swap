/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:12:32 by azinnatu          #+#    #+#             */
/*   Updated: 2018/01/30 23:57:02 by azinnatu         ###   ########.fr       */
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
	 printf("mid is: %d\n", mid);
	 while (mid != 0)
	 {
	 	pivot = mid/2;
	 	if (index_in_list(stack->a, sml(stack->a)) < pivot)
	 	{
	 		// printf("it's on left\n");
	 		while (stack->a->data != sml(stack->a))
	 		{
	 			ra(stack);
	 		}
	 		pb(stack);
	 	}
	 	else
	 	{
	 		// printf("it's on right\n");
	 		while (last(stack->a) != sml(stack->a))
	 		{
	 			rra(stack);
	 		}
	 		rra(stack);
	 		pb(stack);
	 	}
	 	mid--;
	 }
}