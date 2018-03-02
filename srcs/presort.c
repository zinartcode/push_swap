/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 23:56:10 by azinnatu          #+#    #+#             */
/*   Updated: 2018/02/19 22:41:24 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	presort_a(t_stack *stack)
{
	int	count;
	stack->pivot = size(stack->a)/2;

	while (size(stack->a) >= 5)
	{
		count = size(stack->a)/2;
		while (stack->a && count != 0)
		{
			if (low_index(stack->a, stack->a->data) < count)
			{
				pb(stack);
				count--;
			}
			else
				ra(stack);
		}
	}
	v_operation(stack);
}

void	presort_b(t_stack *stack)
{
	int	count;

	stack->i = 0;
	stack->pivot = 0;
	stack->temp = stack->a->data;
	while (size(stack->b) >= 5)
	{
		count = size(stack->b)/4;
		presort_b2(stack, count);
	}
	v_operation(stack);
	b_to_a(stack);
	v_operation(stack);
	b_to_a2(stack);
	v_operation(stack);
}

void	presort_b2(t_stack *stack, int count)
{
	if (stack->b && count != 0)
	{
		if (high_index(stack->b, stack->b->data) < count)
		{
			pa(stack);
			count--;
			stack->pivot++;
		}
		else if (stack->b->data == sml(stack->b))
		{
			pa(stack);
			if (high_index(stack->b, stack->b->data) >= count &&
				stack->b->data != sml(stack->b))
				rr(stack);
			else
				ra(stack);
			count--;
			stack->i++;
		}
		else
			rb(stack);
	}	
}

void	b_to_a(t_stack *stack)
{
	while (stack->b)
	{
		if (stack->b->data == sml(stack->b))
		{
			pa(stack);
			if (size(stack->b) > 1 && stack->b->data != sml(stack->b))
				rr(stack);
			else
				ra(stack);
				stack->i++;
		}
		else
			rb(stack);
	}
}

void	b_to_a2(t_stack *stack)
{
	stack->i++;
	while (stack->a->data != stack->temp)
	{
		if (low_in_array(stack->array, stack->a->next->data, stack->count) == stack->i)
			sa(stack);
		if (low_in_array(stack->array, stack->a->data, stack->count) == stack->i)
		{
			ra(stack);
			stack->i++;
				stack->pivot--;
		}
		else
		{
			pb(stack);
			stack->pivot--;
		}
	}
}
