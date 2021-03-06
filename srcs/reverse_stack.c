/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:48:46 by azinnatu          #+#    #+#             */
/*   Updated: 2018/01/31 20:18:21 by azinnatu         ###   ########.fr       */
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
		if (stack->is_push == 1)
			ft_putstr("rra\n");
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
		if (stack->is_push == 1)
			ft_putstr("rrb\n");
	}
}

void	rrr(t_stack *stack)
{
	if (stack->is_push == 1)
	{
		stack->is_push = 0;
		rra(stack);
		rrb(stack);
		stack->is_push = 1;
	}
	else
	{
		rra(stack);
		rrb(stack);
	}
	if (stack->is_push == 1)
		ft_putstr("rr\n");
}
