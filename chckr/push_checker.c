/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 20:32:52 by eelmoham          #+#    #+#             */
/*   Updated: 2022/02/26 16:02:42 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	do_pa(t_list **stck_a, t_list **stck_b)
{
	t_list	*temp;

	if (ft_lstsize(*stck_b) > 0)
	{
		ft_lstadd_front(stck_a, ft_lstnew((*stck_b)->content));
		temp = *stck_b;
		*stck_b = (*stck_b)->next;
		free (temp);
	}
}

void	do_pb(t_list **stck_b, t_list **stck_a)
{
	t_list	*temp;

	if (ft_lstsize(*stck_a) > 0)
	{
		ft_lstadd_front(stck_b, ft_lstnew((*stck_a)->content));
		temp = *stck_a;
		*stck_a = (*stck_a)->next;
		free(temp);
	}
}
