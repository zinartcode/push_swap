/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 21:58:49 by azinnatu          #+#    #+#             */
/*   Updated: 2018/01/26 21:45:22 by azinnatu         ###   ########.fr       */
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
	while(++i < ac)
	{
		printf("my av is: %s\n", av[i]);
		if (is_num(av[i]) && check_int(av[i]))
			ls_push_back(&a, ft_atoi(av[i]));
		else if (is_multinum(av[i]))
		{
			printf("there are numbers here: %s\n", av[i]);
			run_multin(ac, av[i], a);
		}
		else
			ft_error(&a);
	}
	print_list(a);
	return (0);
}

static void		run_multin(int ac, char *av, t_list *a)
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
				printf("i is: %d\n", i);
				tmp = ft_strndup(&av[j], count);
				count = 0;
				ls_push_back(&a, ft_atoi(tmp));
				printf("number is: %s\n", tmp);
			}
			i++;
		}
		print_list(a);
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