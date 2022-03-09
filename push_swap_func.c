/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:35:00 by eelmoham          #+#    #+#             */
/*   Updated: 2022/02/25 10:31:38 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_list **a)
{
	t_list	*t;
	int		x;

	t = *a;
	x = t->content;
	while (t)
	{
		if (x > t->content)
			x = t->content;
		t = t->next;
	}
	return (x);
}

int	get_max(t_list **a)
{
	t_list	*t;
	int		x;

	t = *a;
	x = t->content;
	while (t)
	{
		if (x < t->content)
			x = t->content;
		t = t->next;
	}
	return (x);
}

int	its_ok(t_list **a, t_list **b)
{
	t_list	*t;

	t = *a;
	if (ft_lstsize(*b) > 0)
		return (0);
	while (t)
	{
		if (t->next)
		{
			if (t->content > t->next->content)
				return (0);
		}
		t = t->next;
	}
	return (1);
}

int	len_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	is_all_digit(char **args)
{
	int	i;
	int	j;
	int	len;

	i = 1;
	while (args[i])
	{
		len = ft_strlen(args[i]);
		if (len == 0)
			return (-1);
		j = 0;
		while (j <= len && args[i][j])
		{
			if (args[i][j] == '-' || args[i][j] == '+')
				j++;
			else if (ft_isdigit(args[i][j]) == 1)
				j++;
			else if (ft_isdigit(args[i][j]) == 0)
				return (-1);
		}
		i++;
	}
	return (1);
}
