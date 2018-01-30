/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:48:46 by azinnatu          #+#    #+#             */
/*   Updated: 2018/01/29 16:05:22 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack)
{
	t_list *temp;
	t_list *temp2;

	temp = stack->a;
	if (temp && temp->next)
	{
		while (stack->a->next->next)
			stack->a = stack->a->next;
		temp2 = stack->a->next;
		stack->a->next = NULL;
		temp2->next = temp;
		stack->a = temp2;
	}
}

void	rrb(t_stack *stack)
{
	t_list *temp;
	t_list *temp2;

	temp = stack->b;
	if (temp && temp->next)
	{
		while (stack->b->next->next)
			stack->b = stack->b->next;
		temp2 = stack->b->next;
		stack->b->next = NULL;
		temp2->next = temp;
		stack->b = temp2;
	}
}

void	rrr(t_stack *stack)
{
	rra(stack);
	rrb(stack);
}
