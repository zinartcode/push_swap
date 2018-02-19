/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 23:56:10 by azinnatu          #+#    #+#             */
/*   Updated: 2018/02/19 13:35:51 by azinnatu         ###   ########.fr       */
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
	while (size(stack->b) >= 5)
	{
		count = size(stack->b)/4;
		// printf("count is: %d\n", count);
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
	b_to_a(stack);
	printf("i is: %d\n", stack->i);
	b_to_a2(stack, i);
	b_to_a_tail(stack);
	// while (is_sorted(stack->a) == 0 && last(stack->a) < stack->a->data)
	// {
	// 	rra(stack);
	// 	// 		printf("stac a is: ");
	// 	// print_list(stack->a);  //test
	// }
}

void	b_to_a2(t_stack *stack, int i)
{
	int	*array;
	int	temp;
	array = list_to_array(stack->a, stack->count);
	while (i > 1)
	{
		if (stack->a->data > stack->a->next->data)
			sa(stack);
		// if (low_index(stack->a, stack->a->data) == stack->i)
		// {
			if (low_in_array(array, stack->a->data, stack->count) == stack->i)
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
		// }
		// else
		// {
		// 	pb(stack);
		// 	i--;
		// }

	}
	free(array);
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
