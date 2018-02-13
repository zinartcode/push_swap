/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:12:32 by azinnatu          #+#    #+#             */
/*   Updated: 2018/02/12 22:10:27 by azinnatu         ###   ########.fr       */
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
	stack->i = 0;
	while (last(stack->a) < stack->a->data)
		rra(stack);
}

void	check_big(t_stack *stack)
{
	int i = stack->pivot; //test

	stack->temp = second_big(stack->b);
	while (stack->b->data != big(stack->b))
	{
		// printf("data %d low index is: %d, pivot is %d\n",stack->b->data, low_index(stack->b, stack->b->data), stack->pivot);
		if (low_index(stack->b, stack->b->data) == i)
		{
			pa(stack);
			ra(stack);
		}
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
		if (index_in_list(stack->b, big(stack->b)) < size(stack->b)/2)
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
	while (size(stack->b) > 3)
	{
		while (index_in_list(stack->b, big(stack->b)) < size(stack->b)/2)
			check_big(stack);
		shift_b_back(stack);
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
}

// void	b_to_a_tail(t_stack *stack)
// {
// 	stack->i = 0;
// 	while (stack->b)
// 	{
// 		ft_tail1(stack);
// 		ft_tail2(stack);
// 		if (size(stack->b) <= 3)
// 		{
// 			if (stack->b && last(stack->b) == big(stack->b))
// 				rrb(stack);
// 			while (stack->b && stack->b->data != big(stack->b))
// 				rb(stack);
// 			pa(stack);
// 		}
// 	}
// }

// void	ft_tail1(t_stack *stack)
// {
// 	if (index_in_list(stack->b, big(stack->b)) < size(stack->b)/2)
// 	{
// 		stack->temp = second_big(stack->b);
// 		check_head_b(stack);
// 		while (stack->b->data != big(stack->b))
// 		{
// 			if (stack->b->data == stack->temp)
// 				pa(stack);
// 			else
// 			{
// 				rb(stack);
// 				stack->i++;
// 			}
// 		}
// 		pa(stack);
// 		check_head_a(stack);	
// 	}
// 	if (index_in_list(stack->b, big(stack->b)) > size(stack->b)/2)
// 	{
// 		while (stack->b->data != big(stack->b))
// 		{
// 			rrb(stack);
// 			stack->i--;
// 		}
// 		pa(stack);
// 	}
// }

// void	ft_tail2(t_stack *stack)
// {
// 	while (size(stack->b) > 3 && stack->i > 0)
// 	{
// 		if (stack->b->data == big(stack->b))
// 			pa(stack);
// 		if (index_in_list(stack->b, big(stack->b)) <= size(stack->b)/2)
// 		{
// 			while (stack->b->data != big(stack->b))
// 			{
// 				rb(stack);
// 				stack->i++;
// 			}
// 			pa(stack);
// 		}
// 		if (stack->a->data > stack->a->next->data)
// 			sa(stack);
// 		else
// 		{
// 			rrb(stack);
// 			stack->i--;
// 		}
// 	}	
// }

// void	shift_b_back(t_stack *stack)
// {
// 	while (stack->i > 0)
// 	{
// 		if (stack->b->data == big(stack->b))
// 			pa(stack);
// 		if (index_in_list(stack->b, big(stack->b)) < size(stack->b)/2)
// 		{
// 			while (stack->b->data != big(stack->b))
// 			{
// 				rb(stack);
// 				stack->i++;
// 			}
// 			pa(stack);
// 		}
// 		if (stack->a->data > stack->a->next->data)
// 			sa(stack);
// 		else
// 		{
// 			rrb(stack);
// 			stack->i--;
// 		}
// 	}
// }

