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

void			print_list(t_list *list)
{
	t_list		*current;

	current = list;
	if (list)
	{
		while (current != NULL)
		{
			ft_putnbr(current->data);
			ft_putchar(' ');
			current = current->next;
		}
	}
	ft_putchar('\n');
}

int				ft_error(t_list **list)
{
	ft_putstr_fd(RED"Error\n", 2);
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
	free(temp);
}

void			init_stack(t_stack *stack)
{
	stack->b = NULL;
	stack->a = NULL;
	stack->count = 0;
	stack->is_push = 1;
	stack->i = 0;
	stack->temp = 0;
	stack->pivot = 0;
	stack->v = 0;
}

void			v_operation(t_stack *stack)
{
	if (stack->v == 1)
	{
		if (is_sorted(stack->a))
		{
			ft_putstr(GRN" Sorted stack a is: "NRM);
			print_list(stack->a);
		}
		else
		{
			ft_putstr(GRN" stack a is: "NRM);
			print_list(stack->a);
		}
		ft_putstr(GRN" size: "NRM);
		ft_putnbr(size(stack->a));
		ft_putchar('\n');
		ft_putstr(GRN"stack b is: "NRM);
		print_list(stack->b);
		ft_putstr(GRN" size: "NRM);
		ft_putnbr(size(stack->b));
		ft_putchar('\n');
	}
}
