/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 23:56:10 by azinnatu          #+#    #+#             */
/*   Updated: 2018/02/12 23:03:14 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	low_index(t_list *list, int nbr)
{
	t_list *temp;
	int	i;
	int n;

	temp = list;
	i = 0;

	while (temp)
	{
		if (nbr > temp->data)
			i++;
		temp = temp->next;
	}
	return (i);
}

int	high_index(t_list *list, int nbr)
{
	t_list *temp;
	int	i;
	int n;

	temp = list;
	i = 0;

	while (temp)
	{
		if (nbr < temp->data)
			i++;
		temp = temp->next;
	}
	return (i);
}

void	presort_a(t_stack *stack)
{
	int	i;
	int	count;
	stack->pivot = size(stack->a)/2;

	while (size(stack->a) >= 5)
	{
		count = size(stack->a)/2;
		while (stack->a && count != 0)	 //size(stack->a) != 5
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
}

void	presort_b(t_stack *stack)
{
	int	i;
	int	count;
	int	pivot;

	pivot = size(stack->b)/2;
	i = 0;
	count = size(stack->b)/4;
	while (size(stack->b) >= 5)
	{
		count = size(stack->b)/4;
		printf("count is: %d\n", count);
		if (stack->b && count != 0)
		{
			if (high_index(stack->b, stack->b->data) < count)
			{
				pa(stack);
				count--;
				i++;
			}
			else if (stack->b->data == sml(stack->b))
			{
				pa(stack);
				ra(stack);
				count--;
			}
			else
				rb(stack);
		}
	}
	// while (i > 0)
	// {
		// pb(stack);
	// 	i--;
	// }
}
