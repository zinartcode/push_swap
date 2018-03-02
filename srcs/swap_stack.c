/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:46:28 by azinnatu          #+#    #+#             */
/*   Updated: 2018/01/30 00:10:28 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	int swap;

	if (stack->a && stack->a->next)
	{
		swap = stack->a->data;
		stack->a->data = stack->a->next->data;
		stack->a->next->data = swap;
	}
	if (stack->is_push == 1)
		ft_putstr("sa\n");
}

void	sb(t_stack *stack)
{
	int swap;

	if (stack->b && stack->b->next)
	{
		swap = stack->b->data;
		stack->b->data = stack->b->next->data;
		stack->b->next->data = swap;
	}
	if (stack->is_push == 1)
		ft_putstr("sb\n");
}

void	ss(t_stack *stack)
{
	if (stack->is_push == 1)
	{
		stack->is_push = 0;
		sa(stack);
		sb(stack);
		stack->is_push = 1;
	}
	else
	{
		sa(stack);
		sb(stack);
	}
	if (stack->is_push == 1)
		ft_putstr("rr\n");
}

void	pa(t_stack *stack)
{
	t_list *temp;

	if (stack->b)
	{
		temp = stack->b;
		stack->b = stack->b->next;
		temp->next = stack->a;
		stack->a = temp;
	}
	if (stack->is_push == 1)
		ft_putstr("pa\n");
}

void	pb(t_stack *stack)
{
	t_list *temp;

	if (stack->a)
	{
		temp = stack->a;
		stack->a = stack->a->next;
		temp->next = stack->b;
		stack->b = temp;
	}
	if (stack->is_push == 1)
		ft_putstr("pb\n");
}