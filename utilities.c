/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:02:38 by azinnatu          #+#    #+#             */
/*   Updated: 2018/02/05 00:30:15 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		run_multinum(int ac, char *av, t_stack *stack)
{
	int		i;
	int		j;
	int		count;
	char	*tmp;

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

void	print_list(t_list *list)
{
    t_list *current;

    current = list;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int		ft_error(t_list **list)
{
	ft_putstr_fd("Error\n", 2);
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
}

// int		find_mid(t_list *list)
// {
// 	int	i;
// 	int	n;
// 	t_list *temp;

// 	temp = list;
// 	n = 0;
// 	i = temp->data;
// 	while(temp->next != NULL)
// 	{
// 		n++;
// 		i += temp->next->data;
// 		temp = temp->next;
// 	}
// 	i = i / n;
// 	return (i);
// }

// void	pre_sort_a(t_stack *stack)
// {
// 	 int	i;
// 	 int	mid;

// 	 i = find_mid(stack->a);
// 	 printf("mid is %d\n", i);
// 	 while (stack->a)
// 	 {
// 	 	if (stack->a->data < i)
// 	 		pb(stack);
// 	 	else
// 	 	{
// 	 		pb(stack);
// 	 		rb(stack);
// 	 	}
// 	 }
// }

// void	pre_sort_b(t_stack *stack)
// {
// 	 int	i;
// 	 int	mid;

// 	 i = find_mid(stack->b);
// 	 while (stack->b)
// 	 {
// 	 	if (stack->b->next != NULL && stack->b->data > stack->b->next->data)
// 	 		sb(stack);
// 	 	if (stack->b->data < i)
// 	 	{
// 	 		pa(stack);
// 	 		if (stack->a->next != NULL && stack->a->data > stack->a->next->data)
// 	 			sa(stack);
// 	 	}
// 	 	else
// 	 	{
// 	 		pa(stack);
// 	 		if (stack->a->data < last(stack->a))
// 	 		{
// 	 			rra(stack);
// 	 			sa(stack);
// 	 			ra(stack);
// 	 		}
// 	 		ra(stack);
// 	 	}
// 	 }
// 	 // 	printf("mid is %d\n", i);
// 	 // 	printf(" stack a is: ");  //test
// 		// print_list(stack->a);  //test
// 	 // 	printf(" stack b is: ");  //test
// 		// print_list(stack->b);  //test
// }

