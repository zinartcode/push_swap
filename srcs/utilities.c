/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:02:38 by azinnatu          #+#    #+#             */
/*   Updated: 2018/02/19 23:15:54 by azinnatu         ###   ########.fr       */
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

void	init_stack(t_stack *stack)
{
	stack->b = NULL;
	stack->a = NULL;
	stack->count = 0;
	stack->is_push = 1;
	stack->i = 0;
	stack->temp = 0;
	stack->pivot = 0;
}