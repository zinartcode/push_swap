/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 20:48:53 by azinnatu          #+#    #+#             */
/*   Updated: 2018/01/30 20:51:00 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ls_push_back(t_stack *stack, int nbr)
{
	t_list *new;

	new = stack->a;
	if (new)
	{
		if (new->data == nbr)
			ft_error(&stack->a);
		else
			while (new->next != NULL)
				new = new->next;
			new->next = ft_create_elem(nbr);
			stack->count++;
	}
	else
	{
		stack->a = ft_create_elem(nbr);
		stack->count++;
	}
}

t_list	*ft_create_elem(int nbr)
{
	t_list *new;

	new = ft_memalloc(sizeof(t_list));
	if (new)
	{
		new->data = nbr;
		new->next = NULL;
	}
	return (new);
}