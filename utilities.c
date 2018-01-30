/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:02:38 by azinnatu          #+#    #+#             */
/*   Updated: 2018/01/29 22:47:52 by azinnatu         ###   ########.fr       */
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
    t_list *current;

    current = list;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int	ft_error(t_list **list)
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

int	sml(t_list *list)
{
	t_list *temp;
	int	i;

	temp = list;
	i = list->data;
	while (temp->next != NULL)
	{
		if (i > temp->next->data)
			i = temp->next->data;
		temp = temp->next;
	}
	return (i);
}

int	big(t_list *list)
{
	t_list *temp;
	int	i;

	temp = list;
	i = list->data;
	while (temp->next != NULL)
	{
		if (i < temp->next->data)
			i = temp->next->data;
		temp = temp->next;
	}
	return (i);
}