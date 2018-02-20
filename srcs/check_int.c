/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 23:11:24 by azinnatu          #+#    #+#             */
/*   Updated: 2018/02/19 21:55:36 by azinnatu         ###   ########.fr       */
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

void			run_multinum(char *av, t_stack *stack)
{
	size_t		i;
	int			j;
	int			count;
	char		*tmp;

	j = 0;
	count = 0;
	i = 0;
	while (i <= ft_strlen(av))
	{
		while (av[i] && av[i] == ' ')
			i++;
		if (ft_isdigit(av[i]) || (av[i] == '-' && ft_isdigit(av[i + 1])))
		{
			while(av[i] != '\0' && av[i] != ' ')
			{
				count++;
				i++;
			}
			j = i - count;
			tmp = ft_strndup(&av[j], count);
			count = 0;
			if (check_int(tmp))
				ls_push_back(stack, ft_atoi(tmp));
			else
				ft_error(&stack->a);
		}
		i++;
	}
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
