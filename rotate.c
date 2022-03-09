/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:54:12 by eelmoham          #+#    #+#             */
/*   Updated: 2022/02/24 22:26:30 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stck_a)
{
	t_list	*t;

	if (ft_lstsize(*stck_a) > 1)
	{
		t = (*stck_a);
		(*stck_a) = (*stck_a)->next;
		ft_lstadd_back(stck_a, ft_lstnew(t->content));
		free (t);
	}
	write(1, "ra\n", 3);
}

void	rb(t_list **stck_b)
{
	t_list	*t;

	if (ft_lstsize(*stck_b) > 1)
	{
		t = (*stck_b);
		(*stck_b) = (*stck_b)->next;
		ft_lstadd_back(stck_b, ft_lstnew(t->content));
		free(t);
	}
	write(1, "rb\n", 3);
}

void	rr(t_list **stck_a, t_list **stck_b)
{
	ra(stck_a);
	rb(stck_b);
}
