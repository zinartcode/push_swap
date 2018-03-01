/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:12:32 by azinnatu          #+#    #+#             */
/*   Updated: 2018/02/19 22:55:25 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	b_to_a_head(t_stack *stack)
{
	while (size(stack->b) > stack->count/2)
	{
		while (index_in_list(stack->b, big(stack->b)) < size(stack->b)/2)
			check_big(stack);
		shift_b_back(stack);
	}
	if (index_in_list(stack->b, big(stack->b)) >  size(stack->b) - 5)
	{
		stack->temp = second_big(stack->b);
		while (stack->b->data != big(stack->b))
		{
			if (stack->b->data == stack->temp)
				pa(stack);
			else
			{
				rrb(stack);
				stack->i++;
			}
		}
		pa(stack);
		check_head_a(stack);
		v_operation(stack);
	}
	while (last(stack->a) < stack->a->data)
		rra(stack);
}

// void check_b_tail(t_stack *stack)
// {
// 	if (size(stack->b) > 5)
// 	{
// 		while (last(stack->b) == sml(stack->b) || last(stack->b) == big(stack->b)
// 		 || stack->b->data == sml(stack->b) || stack->b->data == big(stack->b))
// 		{
// 		if (stack->b && stack->b->data == big(stack->b))
// 			pa(stack);
// 		if (stack->b && last(stack->b) == big(stack->b))
// 		{
// 			rrb(stack);
// 			pa(stack);
// 		}
// 		if (stack->b && stack->b->data == sml(stack->b))
// 		{
// 			pa(stack);
// 			ra(stack);
// 			stack->i++;
// 		}
// 		if (stack->b && last(stack->b) == sml(stack->b))
// 		{
// 			rrb(stack);
// 			pa(stack);
// 			ra(stack);
// 			stack->i++;
// 		}
// 		}
// 	}
// }

void	check_big(t_stack *stack)
{
	stack->temp = second_big(stack->b);
	while (stack->b->data != big(stack->b))
	{
		if (stack->b->data == stack->temp)
			pa(stack);
		else
		{
			rb(stack);
			stack->i++;
		}
	}
	pa(stack);
	check_head_a(stack);	
}

void	shift_b_back(t_stack *stack)
{
	while (stack->b && stack->i > 0)
	{
		if (index_in_list(stack->b, big(stack->b)) <= size(stack->b)/2)
			check_big(stack);
		else
		{
			rrb(stack);
			stack->i--;
		}
	}
	v_operation(stack);
}

void	b_to_a_tail(t_stack *stack)
{
	while (size(stack->b) > 3)
	{
		// check_b_tail(stack);
		while (index_in_list(stack->b, big(stack->b)) <= size(stack->b)/2)
			check_big(stack);
		if (stack->b && stack->i > 0)
		shift_b_back(stack);
		else
		{
			while (index_in_list(stack->b, big(stack->b)) > size(stack->b)/2)
				rrb(stack);	
		}
	}
	if (size(stack->b) <= 3)
	{
		if (stack->b && last(stack->b) == big(stack->b))
			rrb(stack);
		while (stack->b && stack->b->data != big(stack->b))
			rb(stack);
		pa(stack);
		pa(stack);
	}
	while (is_sorted(stack->a) == 0 && last(stack->a) < stack->a->data)
		rra(stack);
}

