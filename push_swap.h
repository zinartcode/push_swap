/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 22:02:04 by azinnatu          #+#    #+#             */
/*   Updated: 2018/01/25 23:52:38 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/includes/libft.h"
# include <stdio.h>

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

#endif