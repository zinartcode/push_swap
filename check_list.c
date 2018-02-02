/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 20:45:08 by azinnatu          #+#    #+#             */
/*   Updated: 2018/01/31 20:43:42 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		size(t_list *list)
{
	int i;

	i = 0;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}

int		sml(t_list *list)
{
	t_list *temp;
	int	i;

	temp = list;
	i = list->data;
	while (temp->next != NULL)
	{
		if (i > temp->next->data)
			i = temp->next->data;
		temp = temp->next;
	}
	return (i);
}

int		big(t_list *list)
{
	t_list *temp;
	int	i;
	temp = list;
	i = temp->data;
	while (temp->next != NULL)
	{
		if (i < temp->next->data)
			i = temp->next->data;
		temp = temp->next;
	}
	return (i);
}

int		last(t_list *list)
{
	int		i;
	t_list *temp;

	temp = list;
	while (temp && temp->next)
		temp = temp->next;
	i = temp->data;
	return (i);
}

int		index_in_list(t_list *list, int n)
{
	int		i;
	t_list *temp;

	temp = list;
	while (temp->data != n)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}