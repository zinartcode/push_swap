/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 21:58:49 by azinnatu          #+#    #+#             */
/*   Updated: 2018/02/15 00:50:26 by azinnatu         ###   ########.fr       */
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
	if (is_sorted(stack->a))
	{
		printf("stack a is sorted ");  //test
		free_list(&stack->a);
		return (0);
	}
	printf("Stack has %d elements\n", stack->count);  //test
	printf("stack a is: ");  //test
	print_list(stack->a);  //test
	if (stack->count != 1 && stack->count <= 5)
		short_sort(stack);
	else if (stack->count > 5)
	{
		// print_list(stack->a);  //test
				// stack->is_push = 0;
		presort_a(stack);
				// stack->is_push = 1;
		short_sort(stack);
				// printf("after short sort stack b in short is: ");  //test
				// print_list(stack->b);  //test
				// printf(" stack a is: ");  //test
				// print_list(stack->a);  //test
		b_to_a_head(stack);
		// 		printf("after b_to_a_head stack b in short is: ");  //test
		// 		print_list(stack->b);  //test
		// 		printf(" stack a is: ");  //test
		// 		print_list(stack->a);  //test
		presort_b(stack);
		// 		printf("after presort_b stack b in short is: ");  //test
		// 		print_list(stack->b);  //test
		// 		printf(" stack a is: ");  //test
		// 		print_list(stack->a);  //test
		// b_to_a_tail(stack);
	}
	if (is_sorted(stack->a))
	{
		printf(" Sorted stack a is: ");  //test
		print_list(stack->a);  //test
	}
	else
	{
		printf(" stack a is: ");  //test
		print_list(stack->a);  //test
	}
	printf("stack b is: ");  //test
	print_list(stack->b);  //test
	free_list(&stack->a);
	free_list(&stack->b);
	return (0);
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