/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 21:58:49 by azinnatu          #+#    #+#             */
/*   Updated: 2018/02/19 22:58:13 by azinnatu         ###   ########.fr       */
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
	else if (ac >= 2)
	{
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
	if (is_sorted(stack->a))
	{
		free_list(&stack->a);
		return (0);
	}
	stack->array = list_to_array(stack->a, stack->count);
	bubble_sort(stack->array, stack->count);
	if (stack->count != 1 && stack->count <= 5)
		short_sort(stack);
	else if (stack->count > 5)
	{
		v_operation(stack);
		presort_a(stack);
		short_sort(stack);
		b_to_a_head(stack);
		presort_b(stack);
		b_to_a_tail(stack);
	}
	// if (is_sorted(stack->a))
	// {
	// 	ft_putstr(GRN" Sorted stack a is: "NRM);  //test
	// 	print_list(stack->a);  //test
	// }
	// else
	// {
	// 	ft_putstr(RED" stack a is: "NRM);  //test
	// 	print_list(stack->a);  //test
	// }
	// printf("Size: %d\n", size(stack->a));
	// printf("stack b is: ");  //test
	// print_list(stack->b);  //test
	// printf("Size: %d\n", size(stack->b));
	free_list(&stack->a);
	free_list(&stack->b);
	free(stack->array);
	return (0);
}

