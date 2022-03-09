/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:54:12 by eelmoham          #+#    #+#             */
/*   Updated: 2022/02/26 16:01:15 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	do_ra(t_list **stck_a)
{
	t_list	*t;

	if (ft_lstsize(*stck_a) > 1)
	{
		t = (*stck_a);
		(*stck_a) = (*stck_a)->next;
		ft_lstadd_back(stck_a, ft_lstnew(t->content));
		free(t);
	}
}

void	do_rb(t_list **stck_b)
{
	t_list	*t;

	if (ft_lstsize(*stck_b) > 1)
	{
		t = (*stck_b);
		(*stck_b) = (*stck_b)->next;
		ft_lstadd_back(stck_b, ft_lstnew(t->content));
		free(t);
	}
}

void	do_rr(t_list **stck_a, t_list **stck_b)
{
	do_ra(stck_a);
	do_rb(stck_b);
}
