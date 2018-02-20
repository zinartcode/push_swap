/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 21:16:17 by azinnatu          #+#    #+#             */
/*   Updated: 2018/02/19 21:17:15 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ft_check(char *str, t_liste **begin_liste, t_liste **begin_liste_bis)
{
	if (!(ft_strcmp(str, "sa")))
		sa(begin_liste);
	else if (!(ft_strcmp(str, "sb")))
		sb(begin_liste_bis);
	else if (!(ft_strcmp(str, "ss")))
		ss(begin_liste, begin_liste_bis);
	else if (!(ft_strcmp(str, "pa")))
		pa(begin_liste, begin_liste_bis);
	else if (!(ft_strcmp(str, "pb")))
		pb(begin_liste, begin_liste_bis);
	else if (!(ft_strcmp(str, "ra")))
		ra(begin_liste);
	else if (!(ft_strcmp(str, "rb")))
		rb(begin_liste_bis);
	else if (!(ft_strcmp(str, "rr")))
		rr(begin_liste, begin_liste_bis);
	else if (!(ft_strcmp(str, "rra")))
		rra(begin_liste);
	else if (!(ft_strcmp(str, "rrb")))
		rrb(begin_liste_bis);
	else if (!(ft_strcmp(str, "rrr")))
		rrr(begin_liste, begin_liste_bis);
	else
		return (0);
	return (1);
}