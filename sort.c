/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 22:40:25 by eelmoham          #+#    #+#             */
/*   Updated: 2022/02/25 09:51:16 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_3(t_list **a)
{
	if ((*a)->content > (*a)->next->content
		&& (*a)->content > (*a)->next->next->content
		&& (*a)->next->content > (*a)->next->next->content)
	{
		sa(a);
		rra(a);
	}
	else if ((*a)->content < (*a)->next->content
		&& (*a)->content < (*a)->next->next->content
		&& (*a)->next->content > (*a)->next->next->content)
	{
		rra(a);
		sa(a);
	}
	else if (ft_lstlast((*a))->content < (*a)->content
		&& ft_lstlast((*a))->content < (*a)->next->content
		&& (*a)->content < (*a)->next->content)
		rra(a);
	else if ((*a)->content > (*a)->next->content
		&& (*a)->content > ft_lstlast((*a))->content
		&& (*a)->next->content < ft_lstlast((*a))->content)
		ra(a);
}

void	case_5(t_list **a, t_list **b)
{
	t_list	*t;

	t = *a;
	while (t && ft_lstsize(*a) != 3)
	{
		if (ft_lstlast(*a)->content == get_min(a))
			rra(a);
		else if ((*a)->content == get_min(a))
			pb(b, a);
		else
			ra(a);
		t = t->next;
	}
	case_3(a);
	while (ft_lstsize(*b))
		pa(a, b);
}

int	len_degit(int x)
{
	int	i;

	i = 0;
	while ((x >> i) != 0)
		i++;
	return (i);
}

void	case2(t_list **a, t_list **b)
{
	if ((*b))
		return ;
	else if ((*a)->content > (*a)->next->content)
		sa(a);
}

void	cases(t_list **a, t_list **b)
{
	int	size_stack;
	int	count;
	int	i;
	int	x;

	x = len_degit(get_max(a));
	count = 0;
	size_stack = ft_lstsize(*a);
	ar_sort(a);
	while (count < x)
	{
		i = 0;
		while (i < size_stack)
		{
			if ((((*a)->content >> count) & 1) == 1)
				ra(a);
			else
				pb(b, a);
			i++;
		}
		while (ft_lstsize(*b))
			pa(a, b);
		count++;
	}
}
