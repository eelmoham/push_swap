/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 19:05:07 by eelmoham          #+#    #+#             */
/*   Updated: 2022/02/26 15:14:49 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	do_sa(t_list **lst)
{
	t_list	*temp;
	int		swap;

	if (ft_lstsize(*lst) > 1)
	{
		temp = (*lst)->next;
		swap = temp->content;
		temp->content = (*lst)->content;
		(*lst)->content = swap;
	}
}

void	do_sb(t_list **lst)
{
	t_list	*temp;
	int		swap;

	if (ft_lstsize(*lst) > 1)
	{
		temp = (*lst)->next;
		swap = temp->content;
		temp->content = (*lst)->content;
		(*lst)->content = swap;
	}
}

void	do_ss(t_list **stck_a, t_list **stck_b)
{
	do_sa(stck_a);
	do_sb(stck_b);
}
