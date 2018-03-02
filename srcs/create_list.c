/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 20:48:53 by azinnatu          #+#    #+#             */
/*   Updated: 2018/01/31 00:07:46 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ls_push_back(t_stack *stack, int nbr)
{
	t_list *new;

	new = stack->a;
	if (new)
	{
		if (is_double(stack->a, nbr))
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

int		is_double(t_list *list, int nbr)
{
	t_list *tmp;

	tmp = list;
	while(tmp)
	{
		if (tmp->data == nbr)
			return (1);
		tmp = tmp->next;
	}
	return(0);
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

void	create_list(int ac, char **av, t_stack *stack)
{
	int		i;

	i = 0;
	if (ft_strcmp(av[1], "-v") == 0)
	{
		stack->v = 1;
		i++;
	}
	while(++i < ac)
	{
		if (is_num(av[i]) && check_int(av[i]))
			ls_push_back(stack, ft_atoi(av[i]));
		else if (is_multinum(av[i]))
			run_multinum(av[i], stack);
		else
			ft_error(&stack->a);
	}
}