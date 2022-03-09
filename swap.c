/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 19:05:07 by eelmoham          #+#    #+#             */
/*   Updated: 2022/02/25 16:24:13 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **lst)
{
	t_list	*temp;
	int		swap;

	if (ft_lstsize(*lst) > 1)
	{
		temp = (*lst)->next;
		swap = temp->content;
		temp->content = (*lst)->content;
		(*lst)->content = swap;
		write (1, "sa\n", 3);
	}
}

void	sb(t_list **lst)
{
	t_list	*temp;
	int		swap;

	if (ft_lstsize(*lst) > 1)
	{
		temp = (*lst)->next;
		swap = temp->content;
		temp->content = (*lst)->content;
		(*lst)->content = swap;
		write (1, "sb\n", 3);
	}
}

void	ss(t_list **stck_a, t_list **stck_b)
{
	sa(stck_a);
	sb(stck_b);
}
