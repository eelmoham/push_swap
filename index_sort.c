/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 20:41:20 by eelmoham          #+#    #+#             */
/*   Updated: 2022/02/25 10:12:41 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_indexes(t_list **a, int *ptr)
{
	int		i;
	t_list	*t;

	i = 0;
	t = *a;
	while (t)
	{
		t->content = ptr[i];
		i++;
		t = t->next;
	}
	free (ptr);
}

void	ar_sort(t_list **a)
{
	t_list	*t;
	t_list	*l;
	int		pos;
	int		*ptr;
	int		i;

	i = 0;
	ptr = malloc(ft_lstsize(*a) * sizeof(int));
	t = *a;
	while (t)
	{
		l = *a;
		pos = 0;
		while (l)
		{
			if (t->content > l->content)
				pos++;
			l = l->next;
		}
		ptr[i] = pos;
		i++;
		t = t->next;
	}
	get_indexes(a, ptr);
}
