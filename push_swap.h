/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 22:02:04 by azinnatu          #+#    #+#             */
/*   Updated: 2018/01/29 16:12:54 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/includes/libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct	s_stack
{
	t_list	*a;
	t_list	*b;
	int		count;
}				t_stack;

int				is_num(char *str);
int				check_int(char *str);
void			ls_push_back(t_stack *stack, int nbr);
t_list			*ft_create_elem(int nbr);
void			print_list(t_list *list);
static int		ft_error(t_list **list);
void			free_list(t_list **list);
int				is_multinum(char *str);
static void		run_multinum(int ac, char *av, t_stack *stack);
void			sa(t_stack *stack);
void			sb(t_stack *stack);
void			ss(t_stack *stack);
void			pa(t_stack *stack);
void			pb(t_stack *stack);
void			ra(t_stack *stack);
void			rb(t_stack *stack);
void			rr(t_stack *stack);
void			rra(t_stack *stack);
void			rrb(t_stack *stack);
void			rrr(t_stack *stack);

#endif