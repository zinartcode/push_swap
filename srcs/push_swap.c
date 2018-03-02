/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 21:58:49 by azinnatu          #+#    #+#             */
/*   Updated: 2018/02/19 22:58:13 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{	
	t_stack		*stack;

	stack = malloc(sizeof(t_stack));
	init_stack(stack);
	if (ac == 1)
		return(0);
	else if (ac >= 2)
		create_list(ac, av, stack);
	if (is_sorted(stack->a))
	{
		free_list(&stack->a);
		return (0);
	}
	else
		sort_stack(stack);
	free_list(&stack->a);
	free_list(&stack->b);
	free(stack->array);
	return (0);
}

void	sort_stack(t_stack *stack)
{
	stack->array = list_to_array(stack->a, stack->count);
	bubble_sort(stack->array, stack->count);
	if (stack->count != 1 && stack->count <= 5)
		short_sort(stack);
	else if (stack->count > 5)
	{
		v_operation(stack);
		presort_a(stack);
		short_sort(stack);
		b_to_a_head(stack);
		presort_b(stack);
		b_to_a_tail(stack);
		v_operation(stack);
	}
}

