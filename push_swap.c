/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 21:58:49 by azinnatu          #+#    #+#             */
/*   Updated: 2018/01/29 16:25:29 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int			i;
	t_stack		*stack;

	i = 0;
	stack = malloc(sizeof(t_stack));
	stack->b = NULL;
	stack->a = NULL;
	stack->count = 0;
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
	printf("Stack has %d elements\n", stack->count);
	// print_list(stack->a);
	// sa(stack);
	// print_list(stack->a);
	// pb(stack);
	// print_list(stack->a);
	// pb(stack);
	// print_list(stack->a);
	// print_list(stack->b);
	// pa(stack);
	// print_list(stack->a);
	// ss(stack);
	// print_list(stack->a);
	// print_list(stack->b);
	// 	ra(stack);
	// print_list(stack->a);
	// print_list(stack->b);
	// 	rb(stack);
	// print_list(stack->a);
	// print_list(stack->b);
		pb(stack);
		pb(stack);
		pb(stack);
		sb(stack);
	printf("stack a is: ");
	print_list(stack->a);
	printf("stack b is: ");
	print_list(stack->b);
			ss(stack);
	printf("stack a is: ");
	print_list(stack->a);
	printf("stack b is: ");
	print_list(stack->b);

	rrr(stack);
	printf("stack a is: ");
	print_list(stack->a);
	printf("stack b is: ");
	print_list(stack->b);


	return (0);
}

static void		run_multinum(int ac, char *av, t_stack *stack)
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
		if (ft_isdigit(av[i]) || (av[i] == '-' &&
		ft_isdigit(av[i + 1])))
		{
			while(av[i] != '\0' && av[i] != ' ')
			{
				count++;
				i++;
			}
			j = i - count;
			tmp = ft_strndup(&av[j], count);
			count = 0;
			ls_push_back(stack, ft_atoi(tmp));
		}
		i++;
	}
}

void	print_list(t_list *list)
{
    t_list * current = list;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

static int	ft_error(t_list **list)
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