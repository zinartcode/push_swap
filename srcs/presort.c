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

int	low_index(t_list *list, int nbr)
{
	t_list *temp;
	int	i;

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
	int	i;
	int	count;
	int	pivot;

	pivot = size(stack->b)/2;
	stack->i = 0;
	i = 0;
	stack->temp = stack->a->data;
	while (size(stack->b) >= 5)
	{
		count = size(stack->b)/4;
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
				stack->i++;
			}
			else
				rb(stack);
		}
	}
	v_operation(stack);
	b_to_a(stack);
	v_operation(stack);
	b_to_a2(stack, i);
	v_operation(stack);
}

void	b_to_a(t_stack *stack)
{
	while (stack->b)
	{
		if (stack->b->data == sml(stack->b))
		{
			pa(stack);
			ra(stack);
			stack->i++;
		}
		else
			rb(stack);
	}
}

void	b_to_a2(t_stack *stack, int i)
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
				i--;
		}
		else
		{
			pb(stack);
			i--;
		}
	}
	// check_b_tail(stack);
}
