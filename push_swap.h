/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 22:02:04 by azinnatu          #+#    #+#             */
/*   Updated: 2018/01/26 21:44:33 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/includes/libft.h"
# include <stdio.h>
# include <stdlib.h>

// typedef struct	s_stack
// {
// 	t_list	*a;
// 	t_list	*b;
// }				t_stack;

int				is_num(char *str);
int				check_int(char *str);
void			ls_push_back(t_list **list, int nbr);
t_list			*ft_create_elem(int nbr);
void			print_list(t_list *list);
static int		ft_error(t_list **list);
void			free_list(t_list **list);
int				is_multinum(char *str);
static void		run_multin(int ac, char *av, t_list *a);

#endif