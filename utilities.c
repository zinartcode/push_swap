/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:02:38 by azinnatu          #+#    #+#             */
/*   Updated: 2018/02/15 00:37:53 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_list *list)
{
    t_list *current;

    current = list;
    if (list)
    {
  		while (current != NULL)
    	{
     	   printf("%d ", current->data);
     	   current = current->next;
		}
	}
    printf("\n");
}

int		ft_error(t_list **list)
{
	ft_putstr_fd("Error\n", 2);
	free_list(list);
	exit(0);
}

void			free_list(t_list **list)
{
	t_list		*temp;
	t_list		*temp2;

	temp = *list;
	while (temp && temp->next)
	{
		temp2 = temp->next;
		free(temp);
		temp = temp2;
	}
}

int		*list_to_array(t_list *list, int size)
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

int	low_in_array(int *arr, int nbr)
{
	int	i;
	int	j;

	j = 0;
	i = 0;

	while (arr[i])
	{
		if (nbr > arr[i])
			j++;
		i++;
	}
	return (j);
}



