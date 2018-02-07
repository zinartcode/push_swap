/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 23:56:10 by azinnatu          #+#    #+#             */
/*   Updated: 2018/02/06 19:12:36 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	low_index(t_list *list, int nbr)
{
	t_list *temp;
	int	i;
	int n;

	temp = list;
	i = 0;

	while (temp)
	{
		if (nbr > temp->data)
			i++;
		temp = temp->next;
	}
	return (i);
}

int	high_index(t_list *list, int nbr)
{
	t_list *temp;
	int	i;
	int n;

	temp = list;
	i = 0;

	while (temp)
	{
		if (nbr < temp->data)
			i++;
		temp = temp->next;
	}
	return (i);
}

void	presort_a(t_stack *stack)
{
	 int	i;
	 int	count;

	 count = size(stack->a)/2;
	 while (stack->a && count != 0)
	 {
	 	if (low_index(stack->a, stack->a->data) < count)
	 	{
	 		pb(stack);
	 		count--;
	 	}
	 	else
	 		ra(stack);
	 }
	 // printf("b stack size is: %d\n", size(stack->b));
}

void	b_to_a_head(t_stack *stack)
{
	int	i;

	i = 0;
	while (size(stack->b) > stack->count/2)
	{
		while (stack->b->data != big(stack->b))
		{
			rb(stack);
			i++;
		}
		pa(stack);
		while (i > 0)
		{
			// printf("I is %d\n", i);
			if (stack->b->data == big(stack->b))
				pa(stack);
			if (stack->a->data > stack->a->next->data)
				sa(stack);
			else
			{
				rrb(stack);
				i--;
			}
		}
	}
}

void	presort_b(t_stack *stack)
{
	 int	i;
	 int	j;
	 int	count;

	 i = 0;
	 j = 0;
	 while (size(stack->b) >= 5)
	 {
	 	count = size(stack->b)/2;
	 while (stack->b && count != 0)
	 {
	 	if (high_index(stack->b, stack->b->data) < count)
	 	{
	 		pa(stack);
	 		count--;
	 		// ra(stack);
	 		// rb(stack);
	 		i++;
	 	}
	 	else
	 	{
	 		rb(stack);
	 		j++;
	 	}
	 }
	}
	 
	 while (i > 0)
	 {
	 	// printf("i is %d\n", i);
	 	// rra(stack);
	 	pb(stack);
	 	i--;
	 }
	 // printf("b stack size is: %d\n", size(stack->b));
}

void	b_to_a_tail(t_stack *stack)
{
	int	i;

	i = stack->count/4;
	// printf(" I is %d\n", i);
	while (stack->b)
	{
		if (index_in_list(stack->b, big(stack->b)) < i)
		{
			while (stack->b && stack->b->data != big(stack->b))
				rb(stack);
			pa(stack);
			if (stack->a->data > stack->a->next->data)
				sa(stack);
			i--;
		}
		if (index_in_list(stack->b, big(stack->b)) > i)
		{
			while (stack->b && stack->b->data != big(stack->b))
				rrb(stack);
			pa(stack);
			if (stack->a->data > stack->a->next->data)
				sa(stack);
			i--;
		}
		else //while (stack->b && stack->b->data != big(stack->b))
				rb(stack);
			// pa(stack);
	}
}

void	pre_sort_b(t_stack *stack)
{
	 int	i;
	 int	mid;

	 i = find_mid(stack->b);
	 while (stack->b)
	 {
	 	if (stack->b->next != NULL && stack->b->data > stack->b->next->data)
	 		sb(stack);
	 	if (stack->b->data < i)
	 	{
	 		pa(stack);
	 		if (stack->a->next != NULL && stack->a->data > stack->a->next->data)
	 			sa(stack);
	 	}
	 	else
	 	{
	 		pa(stack);
	 		if (stack->a->data < last(stack->a))
	 		{
	 			rra(stack);
	 			sa(stack);
	 			ra(stack);
	 		}
	 		ra(stack);
	 	}
	 }
	 // 	printf("mid is %d\n", i);
	 // 	printf(" stack a is: ");  //test
		// print_list(stack->a);  //test
	 // 	printf(" stack b is: ");  //test
		// print_list(stack->b);  //test
}

int		find_mid(t_list *list)
{
	int	i;
	int	n;
	t_list *temp;

	temp = list;
	n = 0;
	i = temp->data;
	while(temp->next != NULL)
	{
		n++;
		i += temp->next->data;
		temp = temp->next;
	}
	i = i / n;
	return (i);
}

// void	b_to_a(t_stack *stack)
// {
// 	int	i;

// 	i = 0;
// 	// printf("Stack count is %d\n", stack->count); 
// 	// printf("Stack b has %d elements\n", size(stack->b)); 
// 	// printf("I'm here\n");  //test
// 	while (size(stack->b) >= stack->count/2)
// 	{
// 		if (stack->b->data == big(stack->b))
// 		{
// 			pa(stack);
// 			while (last(stack->b))
// 			{
// 				rrb(stack);
// 				i--;
// 			}
// 		}
// 		else
// 		{
// 		 	rb(stack);
// 		 	i++;
// 		}
// 		if (last(stack->b) == big(stack->b))
// 		{
// 			rrb(stack);
// 			pa(stack);
// 		}
// 		// if (stack->b->data == second_big(stack->b) && flag == 0)
// 		// {
// 		// // printf("its  second big here: %d\n", stack->a->data);
// 		// 	pa(stack);
// 		// 	flag = 0
// 		// 	if (stack->a->data > stack->a->next->data)
// 		// 		sb(stack);
// 		// }
// 		// else
// 		// 	rb(stack);
// 	}
// }