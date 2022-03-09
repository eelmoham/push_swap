/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:35:00 by eelmoham          #+#    #+#             */
/*   Updated: 2022/02/25 15:42:49 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	rem(t_list **lst, char **arr)
{
	t_list	*t;
	int		i;
	int		error;

	i = len_arr(arr) - 1;
	error = 1;
	t = NULL;
	if (is_all_digit(arr) != -1 && check_double(arr) != -1)
	{
		while (i && error)
		{
			t = ft_lstnew(ft_atoi(arr[i]));
			if (ft_atoi(arr[i]) <= 2147483647 && ft_atoi(arr[i]) >= -2147483648)
				ft_lstadd_front(lst, t);
			else
				error = 0;
			i--;
		}
	}
	else
		error = 0;
	if (!error)
		write (2, "ERROR\n", 6);
}
