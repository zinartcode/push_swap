/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 21:58:49 by azinnatu          #+#    #+#             */
/*   Updated: 2018/01/30 00:03:32 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int			i;
	t_stack		*stack;

	i = 0;
	stack = malloc(sizeof(t_stack));
	init_stack(stack);
	if (ac == 1)
		return(0);
	while(++i < ac)
	{
		if (is_num(av[i]) && check_int(av[i]))
			ls_push_back(stack, ft_atoi(av[i]));
		else if (is_multinum(av[i]))
			run_multinum(ac, av[i], stack);
		else
			ft_error(&stack->a);
	}
	printf("Stack has %d elements\n", stack->count);  //test
	printf("stack a is: ");  //test
	print_list(stack->a);  //test
	if (stack->count <= 5)
		short_sort(stack);
	else
		long_sort(stack);
	printf(" Sorted stack a is: ");  //test
	print_list(stack->a);  //test
	return (0);
}

void	init_stack(t_stack *stack)
{
	stack->b = NULL;
	stack->a = NULL;
	stack->count = 0;
	stack->is_push = 1;
}