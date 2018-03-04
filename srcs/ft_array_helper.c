/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 19:44:03 by azinnatu          #+#    #+#             */
/*   Updated: 2018/02/19 12:15:51 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			*list_to_array(t_list *list, int size)
{
	int		*array;
	int		i;
	t_list	*temp;

	i = 0;
	if (list == NULL)
		return (NULL);
	array = (int*)malloc(sizeof(int) * size + 1);
	temp = list;
	while (temp)
	{
		array[i] = temp->data;
		temp = temp->next;
		i++;
	}
	return (array);
}

int			low_in_array(int *arr, int nbr, int size)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (size > 0)
	{
		if (nbr >= arr[i])
			j++;
		i++;
		size--;
	}
	return (j);
}

void		bubble_sort(int *array, int size)
{
	int		i;
	int		tmp;

	i = 1;
	while (i < size)
	{
		if (array[i - 1] <= array[i])
			++i;
		else
		{
			tmp = array[i];
			array[i] = array[i - 1];
			array[i - 1] = tmp;
			--i;
			if (i == 0)
				i = 1;
		}
	}
	return ;
}
