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
	while (index_in_list(stack->b, big(stack->b)) < 5)
		check_big(stack);
	shift_b_back(stack);
	stack->high = size(stack->a);
	printf("low index of 1 is: %d\n", low_in_array(stack->array, 1, stack->count));
	printf("low index of 1 is: %d\n", low_index(stack->b, 1));
	while (size(stack->b) > 5)
	{
		if (low_in_array(stack->array, stack->b->next->data, stack->count) == stack->low)
			sb(stack);
		if (low_in_array(stack->array, stack->b->data, stack->count) == stack->low)
		{
			pa(stack);
			ra(stack);
			stack->low++;
		}
		else if (low_in_array(stack->array, stack->b->data, stack->count) <= 6 + stack->low)
			rb(stack);
		else
			pa(stack);
	}
	move_five_b(stack);
}

void	move_five_b(t_stack *stack)
{
	int	i;

	i = 0;
	if (size(stack->b) <= 5)
	{
		while (i < 2)
		{
			if (sml(stack->b) == stack->b->data)
			{
				pa(stack);
				ra(stack);
				i++;
			}
			else if (sml(stack->b) == last(stack->b))
			{
				rrb(stack);
				pa(stack);
				ra(stack);
				i++;
			}
			else
				while (sml(stack->b) != stack->b->data)
					rb(stack);
		}
	}
	if (size(stack->b) <= 3)
	{
		if (stack->b->data == sml(stack->b))
		{
			pa(stack);
			ra(stack);
		}
		else if (stack->b->next->data == sml(stack->b))
		{
			sb(stack);
			pa(stack);
			ra(stack);
		}
		else
		{
			rrb(stack);
			pa(stack);
			ra(stack);
		}
		if (stack->b->data > stack->b->next->data)
		{
			sb(stack);
			pa(stack);
			ra(stack);
			pa(stack);
			ra(stack);
		}
		else
		{
			pa(stack);
			ra(stack);
			pa(stack);
			ra(stack);
		}
	}
}

// void	b_to_a_head(t_stack *stack)
// {
// 	while (size(stack->b) > stack->count/2)
// 	{
// 		while (index_in_list(stack->b, big(stack->b)) < size(stack->b)/2)
// 			check_big(stack);
// 		shift_b_back(stack);
// 	}
// 	stack->i = 0;
// 	while (last(stack->a) < stack->a->data)
// 		rra(stack);
// 	// check_b_tail(stack);
// }

void check_b_tail(t_stack *stack)
{
	if (size(stack->b) > 5)
	{
		while (last(stack->b) == sml(stack->b) || last(stack->b) == big(stack->b)
		 || stack->b->data == sml(stack->b) || stack->b->data == big(stack->b))
		{
		if (stack->b && stack->b->data == big(stack->b))
			pa(stack);
		if (stack->b && last(stack->b) == big(stack->b))
		{
			rrb(stack);
			pa(stack);
		}
		if (stack->b && stack->b->data == sml(stack->b))
		{
			pa(stack);
			ra(stack);
			stack->i++;
		}
		if (stack->b && last(stack->b) == sml(stack->b))
		{
			rrb(stack);
			pa(stack);
			ra(stack);
			stack->i++;
		}
		}
	}
}

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
}

void	b_to_a_tail(t_stack *stack)
{
	// check_b_tail(stack);
	while (size(stack->b) > 3)
	{
		check_b_tail(stack);
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

