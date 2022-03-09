/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:16:47 by eelmoham          #+#    #+#             */
/*   Updated: 2022/02/26 15:59:37 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	do_rra(t_list **stck_a)
{
	t_list	*t;
	t_list	*s;
	int		i;

	i = ft_lstsize(*stck_a);
	if (i > 1)
	{
		s = *stck_a;
		t = ft_lstlast((*stck_a));
		ft_lstadd_front(stck_a, t);
		while (i - 2)
		{
			s = s->next;
			i--;
		}
		s->next = NULL;
	}
}

void	do_rrb(t_list **stck_b)
{
	t_list	*t;
	t_list	*s;
	int		i;

	i = ft_lstsize(*stck_b);
	if (i > 1)
	{
		s = *stck_b;
		t = ft_lstlast((*stck_b));
		ft_lstadd_front(stck_b, t);
		while (i - 2)
		{
			s = s->next;
			i--;
		}
		s->next = NULL;
	}
}

void	do_rrr(t_list **stck_a, t_list **stck_b)
{
	do_rra(stck_a);
	do_rrb(stck_b);
}
