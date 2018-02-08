/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:12:32 by azinnatu          #+#    #+#             */
/*   Updated: 2018/02/08 00:41:47 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	b_to_a_head(t_stack *stack)
{
	while (size(stack->b) > stack->count/2)
	{
		while (index_in_list(stack->b, big(stack->b)) < size(stack->b)/2)
		{
			if(stack->b->data < stack->b->next->data)
				sb(stack);
			while (stack->b->data != big(stack->b))
			{
				rb(stack);
				stack->i++;
			}
			pa(stack);
		}
		shift_b_back(stack);
	}
	stack->i = 0;
}

void	shift_b_back(t_stack *stack)
{
	while (stack->i > 0)
	{
		if (stack->b->data == big(stack->b))
			pa(stack);
		if (index_in_list(stack->b, big(stack->b)) < size(stack->b)/2)
		{
			while (stack->b->data != big(stack->b))
			{
				rb(stack);
				stack->i++;
			}
			pa(stack);
		}
		if (stack->a->data > stack->a->next->data)
			sa(stack);
		else
		{
			rrb(stack);
			stack->i--;
		}
	}
}

void	b_to_a_tail(t_stack *stack)
{
	stack->i = 0;
	while (stack->b)
	{
		ft_tail1(stack);
		ft_tail2(stack);
		if (size(stack->b) <= 3)
		{
			if (stack->b && last(stack->b) == big(stack->b))
				rrb(stack);
			while (stack->b && stack->b->data != big(stack->b))
				rb(stack);
			pa(stack);
		}
	}
}

void	ft_tail1(t_stack *stack)
{
	if (index_in_list(stack->b, big(stack->b)) < size(stack->b)/2)
	{
		if(stack->b->data < stack->b->next->data)
			sb(stack);
		while (stack->b->data != big(stack->b))
		{
			rb(stack);
			stack->i++;
		}
		pa(stack);	
	}
	if (index_in_list(stack->b, big(stack->b)) > size(stack->b)/2)
	{
		while (stack->b->data != big(stack->b))
		{
			rrb(stack);
			stack->i--;
		}
		pa(stack);
	}
}

void	ft_tail2(t_stack *stack)
{
	while (stack->i > 0 && size(stack->b) > 3)
	{
		if (stack->b->data == big(stack->b))
			pa(stack);
		if (index_in_list(stack->b, big(stack->b)) <= size(stack->b)/2)
		{
			while (stack->b->data != big(stack->b))
			{
				rb(stack);
				stack->i++;
			}
			pa(stack);
		}
		if (stack->a->data > stack->a->next->data)
			sa(stack);
		else
		{
			rrb(stack);
			stack->i--;
		}
	}	
}


// void	long_sort(t_stack *stack)
// {
// 	 int	i;
// 	 int	pivot;
// 	 int	mid;

// 	 i = 0;
// 	 mid = stack->count;
// 	 while (mid != 0)
// 	 {
// 	 	pivot = mid/2;
// 	 	if (index_in_list(stack->a, sml(stack->a)) < pivot)
// 	 	{
// 	 		while (stack->a && stack->a->data != sml(stack->a))
// 	 		{
// 	 			ra(stack);
// 	 		}
// 	 		pb(stack);
// 	 	}
// 	 	else
// 	 	{
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

