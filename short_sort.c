/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 16:57:20 by azinnatu          #+#    #+#             */
/*   Updated: 2018/01/30 21:44:10 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	short_sort(t_stack *stack)
{
	if (stack->count <= 3)
	{
		if (stack->count == 2)
		{
			if (stack->a->data > stack->a->next->data)
				sa(stack);
		}
		else
			sort_three(stack);
	}
	else if (stack->count <= 5)
		sort_five(stack);
	else
		ft_error(&stack->a);
}

void	sort_three(t_stack *stack)
{
	if (is_sorted(stack->a))
	{
		if (stack->a->data == sml(stack->a) && stack->a->next->data == big(stack->a))
		{
			rra(stack);
			sa(stack);
		}
		else if (stack->a->next->data == sml(stack->a))
		{
			if (stack->a->data > stack->a->next->next->data)
				ra(stack);
			else
				sa(stack);
		}
		else if (stack->a->data > stack->a->next->data)
		{
			ra(stack);
			sa(stack);
		}
		else
			rra(stack);
	}
}

// int	sort_five(t_stack *stack)
// {
// 	if (size(stack->b) == 2)
// 		return (0);
// 	if (stack->a->data < stack->a->next->data &&
// 			stack->a->data < last(stack->a))
// 		pb(stack);
// 	else if (last(stack->a) < stack->a->data &&
// 			last(stack->a) < stack->a->next->data)
// 		rra(stack);
// 	else
// 		ra(stack);
// 	sort_five(stack);
// 	return (0);
// }

int	sort_five(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (sml(stack->a) == stack->a->data)
		{
			pb(stack);
			i++;
		}
		else if (sml(stack->a) == last(stack->a))
		{
			rra(stack);
			pb(stack);
			i++;
		}
		else
			while (sml(stack->a) != stack->a->data)
				ra(stack);
	}
	sort_three(stack);
	pa(stack);
	pa(stack);
	// print_list(stack->a);  //test
	// print_list(stack->b);  //test
	return (0);
}

int	is_sorted(t_list *list)
{
	if (list->next == NULL)
		return (0);
	else if (list->data > list->next->data)
		return (1);
	else
		return (is_sorted(list->next));
}
