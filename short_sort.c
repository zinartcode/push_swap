/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 16:57:20 by azinnatu          #+#    #+#             */
/*   Updated: 2018/02/15 15:45:54 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	short_sort(t_stack *stack)
{
	// printf("stack count is: %d\n", stack->count);  //test
	// printf("stack size is: %d\n", size(stack->a));  //test
	if (size(stack->a) <= 3)
	{
		if (size(stack->a) == 2)
		{
			if (stack->a->data > stack->a->next->data)
				sa(stack);
		}
		else
			sort_three(stack);
	}
	else if (size(stack->a) <= 5)
		sort_five(stack);
	else
		ft_error(&stack->a);
}

void	sort_three(t_stack *stack)
{
	if (size(stack->a) == 3 && is_sorted(stack->a) == 0)
	{
	// printf(" stack a in sort three is: ");
	// print_list(stack->a);  //test
		if (stack->a->data == sml(stack->a) && stack->a->next->data == big(stack->a))
		{
			rra(stack);
			sa(stack);
		}
		else if (stack->a->next->data == sml(stack->a))
		{
			if (stack->a->data > stack->a->next->next->data)
				ra(stack);
			else
				sa(stack);
		}
		else if (stack->a->data > stack->a->next->data)
		{
			ra(stack);
			sa(stack);
		}
		else
			rra(stack);
		// printf("after sort_three stack b in short is: ");  //test
		// print_list(stack->b);  //test
		// printf(" stack a in short is: ");  //test
		// print_list(stack->a);  //test
	}
}

// int	sort_five(t_stack *stack)
// {
// 	while (size(stack->a) > 3)
// 	{
// 		if (sml(stack->a) == stack->a->data)
// 			pb(stack);
// 		else if (sml(stack->a) == last(stack->a))
// 		{
// 			rra(stack);
// 			pb(stack);
// 		}
// 		else while (sml(stack->a) != stack->a->data)
// 			ra(stack);	
// 	}
// 	sort_three(stack);
// 	pa(stack);
// 	pa(stack);
// 	return (0);
// }

int	sort_five(t_stack *stack)
{
	int	i;

	i = 0;
	if (size(stack->a) <= 5)
	{
	// 		printf(" stack a in sort five is: ");
	// print_list(stack->a);  //test
		while (i < 2) //&& size(stack->a) > 3
		{
			if (sml(stack->a) == stack->a->data)
			{
				pb(stack);
				i++;
			}
			else if (sml(stack->a) == last(stack->a))
			{
				rra(stack);
				pb(stack);
				i++;
			}
			else
				while (sml(stack->a) != stack->a->data)
					ra(stack);
		}
		// sort_three(stack);
		short_sort(stack);
		pa(stack);
		pa(stack);
	}
		// printf(" stack b in short is: ");  //test
		// print_list(stack->b);  //test
		// printf(" stack a in short is: ");  //test
		// print_list(stack->a);  //test
	return (0);
}

int	is_sorted(t_list *list)
{
	t_list *tmp;

	tmp = list;
	if (tmp->next == NULL)
		return (1);
	else
		while (tmp->next != NULL)
		{ 
			if (tmp->data > tmp->next->data)
				return (0);
			tmp = tmp->next;
		}
		return (1);
}
