/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:16:47 by eelmoham          #+#    #+#             */
/*   Updated: 2022/02/25 16:24:27 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **stck_a)
{
	int		i;
	t_list	*t;
	t_list	*s;

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
	write (1, "rra\n", 4);
}

void	rrb(t_list **stck_b)
{
	int		i;
	t_list	*t;
	t_list	*s;

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
	write (1, "rrb\n", 4);
}

void	rrr(t_list **stck_a, t_list **stck_b)
{
	rra(stck_a);
	rrb(stck_b);
}
