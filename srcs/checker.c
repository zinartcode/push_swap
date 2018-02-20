/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 21:17:28 by azinnatu          #+#    #+#             */
/*   Updated: 2018/02/19 23:43:20 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				main(int ac, char **av)
{
	t_stack		*stack;
	char *str;

	str = NULL;
	stack = malloc(sizeof(t_stack));
	init_stack(stack);
	stack->is_push = 0;
	if (ac == 1)
		return(0);
	if (ac >= 2)
	{
		if (process_args(ac, av, stack))
		{
 			if (is_sorted(stack->a))
				ft_putstr("OK\n");
			else
				ft_putstr("KO\n");
		}
	}
	free_list(&stack->a);
	free_list(&stack->b);
	return (0);
}

int				process_args(int ac, char **av, t_stack *stack)
{
	int			i;
	char		*str;

	i = 0;
	str = NULL;
	while(++i < ac)
	{
		if (is_num(av[i]) && check_int(av[i]))
			ls_push_back(stack, ft_atoi(av[i]));
		else if (is_multinum(av[i]))
			run_multinum(av[i], stack);
		else
			ft_error(&stack->a);
	}
	while (get_next_line(0, &str))
	{
		if (!ft_check(str, stack))
		{
			ft_putstr_fd("Error\n", 2);
			free_list(&stack->a);
			free_list(&stack->b);
			return (0);
		}
	}
	return (1);
}

int		ft_check(char *str, t_stack *stack)
{
	if (!(ft_strcmp(str, "sa")))
		sa(stack);
	else if (!(ft_strcmp(str, "sb")))
		sb(stack);
	else if (!(ft_strcmp(str, "ss")))
		ss(stack);
	else if (!(ft_strcmp(str, "pa")))
		pa(stack);
	else if (!(ft_strcmp(str, "pb")))
		pb(stack);
	else if (!(ft_strcmp(str, "ra")))
		ra(stack);
	else if (!(ft_strcmp(str, "rb")))
		rb(stack);
	else if (!(ft_strcmp(str, "rr")))
		rr(stack);
	else if (!(ft_strcmp(str, "rra")))
		rra(stack);
	else if (!(ft_strcmp(str, "rrb")))
		rrb(stack);
	else if (!(ft_strcmp(str, "rrr")))
		rrr(stack);
	else
		return (0);
	return (1);
}