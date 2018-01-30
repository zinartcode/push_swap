/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:45:38 by azinnatu          #+#    #+#             */
/*   Updated: 2018/01/29 15:59:39 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack)
{
	t_list *temp;
	t_list *temp2;

	temp = stack->a;
	if (temp)
	{
		temp2 = stack->a->next;
		while (stack->a->next)
			stack->a = stack->a->next;
		stack->a->next = temp;
		temp->next = NULL;
		stack->a = temp2;
	}
}

void	rb(t_stack *stack)
{
	t_list *temp;
	t_list *temp2;

	temp = stack->b;
	if (temp)
	{
		temp2 = stack->b->next;
		while (stack->b->next)
			stack->b = stack->b->next;
		stack->b->next = temp;
		temp->next = NULL;
		stack->b = temp2;
	}
}

void	rr(t_stack *stack)
{
	ra(stack);
	rb(stack);
}