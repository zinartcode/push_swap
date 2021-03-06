/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 22:02:04 by azinnatu          #+#    #+#             */
/*   Updated: 2018/02/19 23:37:27 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>

# define RED "\x1B[31m"
# define GRN "\x1B[32m"
# define YEL "\x1B[33m"
# define NRM "\x1B[0m"

typedef struct	s_stack
{
	t_list	*a;
	t_list	*b;
	int		count;
	int		is_push;
	int		v;
	int		i;
	int		temp;
	int		pivot;
	int		*array;
}				t_stack;

int				is_num(char *str);
int				size(t_list *list);
int				sml(t_list *list);
int				second_sml(t_list *list);
int				big(t_list *list);
int				second_big(t_list *list);
int				last(t_list *list);
int				low_index(t_list *list, int nbr);
int				high_index(t_list *list, int nbr);
int				index_in_list(t_list *list, int n);
int				check_int(char *str);
int				is_double(t_list *list, int nbr);
void			check_head_a(t_stack *stack);
void			check_head_b(t_stack *stack);
void			check_big(t_stack *stack);
void			init_stack(t_stack *stack);
void			ls_push_back(t_stack *stack, int nbr);
void			create_list(int ac, char **av, t_stack *stack);
t_list			*ft_create_elem(int nbr);
void			print_list(t_list *list);
int				ft_error(t_list **list);
void			free_list(t_list **list);
int				is_multinum(char *str);
void			run_multinum(char *av, t_stack *stack);
void			sort_stack(t_stack *stack);
int				is_sorted(t_list *list);
void			short_sort(t_stack *stack);
void			sort_three(t_stack *stack);
void			sort_five(t_stack *stack);
void			shift_b_back(t_stack *stack);
void			presort_a(t_stack *stack);
void			presort_b(t_stack *stack);
void			presort_b2(t_stack *stack, int count);
void			long_sort(t_stack *stack);
void			b_to_a_head(t_stack *stack);
void			b_to_a_tail(t_stack *stack);
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

void			b_to_a(t_stack *stack);
void			b_to_a2(t_stack *stack);
int				ft_check(char *str, t_stack *stack);
int				process_args(int ac, char **av, t_stack *stack);
int				*list_to_array(t_list *list, int size);
int				low_in_array(int *arr, int nbr, int size);
void			bubble_sort(int *array, int size);
void			v_operation(t_stack *stack);

#endif
