/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 00:40:05 by azinnatu          #+#    #+#             */
/*   Updated: 2018/02/08 00:41:50 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		last(t_list *list)
{
	int		i;
	t_list *temp;

	i = 0;
	temp = NULL;
	if (list)
	{
	temp = list;
	while (temp && temp->next)
		temp = temp->next;
	i = temp->data;
	}
	return (i);
}

int		index_in_list(t_list *list, int n)
{
	int		i;
	t_list *temp;

	i = 0;
	temp = NULL;
	if (list)
	{
	temp = list;
	i = 0;
	while (temp->data != n)
	{
		temp = temp->next;
		i++;
	}
	}
	return (i);
}

void	check_head_b(t_stack *stack)
{
	if (stack->b && stack->b->next != NULL)
	{
		if (stack->b->data < stack->b->next->data)
		{
			sb(stack);
		}
	}
}

void	check_head_a(t_stack *stack)
{
	if (stack->a && stack->a->next != NULL)
	{
		if (stack->a->data > stack->a->next->data)
		{
			sa(stack);
		}
	}
}