/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 16:57:20 by azinnatu          #+#    #+#             */
/*   Updated: 2018/01/30 00:15:11 by azinnatu         ###   ########.fr       */
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
	// printf(" smallest stack a is: %d\n", sml(stack->a));  //test
	// printf(" biggest stack a is: %d\n", big(stack->a));  //test

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

void	sort_five(t_stack *stack)
{
	printf("its %d\n", stack->count);
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
