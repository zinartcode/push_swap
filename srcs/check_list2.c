/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 00:40:05 by azinnatu          #+#    #+#             */
/*   Updated: 2018/02/19 19:06:10 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			last(t_list *list)
{
	int		i;
	t_list	*temp;

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

int			index_in_list(t_list *list, int n)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = list;
	if (list)
	{
		i = 0;
		while (temp->next != NULL && temp->data != n)
		{
			temp = temp->next;
			i++;
		}
	}
	return (i);
}

void		check_head_a(t_stack *stack)
{
	if (stack->a && stack->a->next != NULL)
	{
		if (stack->a->data > stack->a->next->data)
			sa(stack);
	}
}

int			low_index(t_list *list, int nbr)
{
	t_list	*temp;
	int		i;

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

int			high_index(t_list *list, int nbr)
{
	t_list	*temp;
	int		i;

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
