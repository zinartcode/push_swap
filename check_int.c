/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 23:11:24 by azinnatu          #+#    #+#             */
/*   Updated: 2018/01/29 00:57:23 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_num(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i] == '\0')
		return (1);
	else
		return (0);
}

int	is_multinum(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] && (ft_isdigit(str[i]) || str[i] == ' '))
		i++;
	if (str[i] == '\0')
		return (1);
	else
		return (0);
}

int	check_int(char *str)
{
	ssize_t i;
	ssize_t neg;
	ssize_t res;

	neg = 1;
	i = 0;
	res = 0;
	if (str[i] == '-')
	{
		neg = -1;
		str++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	res = res * neg;
	if ((res < -2147483648) || (res > 2147483647))
		return (0);
	return (1);
}

void	ls_push_back(t_stack *stack, int nbr)
{
	t_list *new;

	new = stack->a;
	if (new)
	{
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