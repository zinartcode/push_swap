/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 21:58:49 by azinnatu          #+#    #+#             */
/*   Updated: 2018/01/25 23:54:58 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int			i;
	t_list		*a;
	t_list		*b;

	i = 0;
	b = NULL;
	if (ac == 1)
		return(0);
	// ft_bzero(stack, sizeof(t_stack) * 2);
	while(++i < ac)
	{
		// printf("my av is: %s\n", av[i]);
		if (is_num(av[i]) && check_int(av[i]))
			ls_push_back(&a, ft_atoi(av[i]));
		else
			printf("Error\n");
	}
	print_list(a);
	return (0);
}

void	print_list(t_list *list)
{
    t_list * current = list;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
}