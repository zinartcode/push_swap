/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 20:45:08 by azinnatu          #+#    #+#             */
/*   Updated: 2018/02/07 20:47:21 by azinnatu         ###   ########.fr       */
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

int		second_sml(t_list *list)
{
	t_list *temp;
	int	i;
	int n;

	temp = list;
	i = big(temp);
	n = sml(temp);
	while (temp->next != NULL)
	{
		if (i > temp->next->data && temp->next->data != n)
			i = temp->next->data;
		temp = temp->next;
	}
	return (i);
}

int		big(t_list *list)
{
	t_list *temp;
	int	i;

	i = 0;
	temp = NULL;
	if (list)
	{
	temp = list;
	i = temp->data;
	while (temp->next != NULL)
	{
		if (i < temp->next->data)
			i = temp->next->data;
		temp = temp->next;
	}
	}
	return (i);
}

int		second_big(t_list *list)
{
	t_list *temp;
	int	i;
	int	n;

	temp = list;
	n = big(temp);
	i = sml(temp);
	if (temp->data < n && temp->data > i)
		i = temp->data;
	while (temp->next != NULL)
	{
		if (i < temp->next->data && temp->next->data != n)
			i = temp->next->data;
		temp = temp->next;
	}
	return (i);
}

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