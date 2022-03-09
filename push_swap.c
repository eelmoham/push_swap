/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 23:02:41 by eelmoham          #+#    #+#             */
/*   Updated: 2022/02/25 15:06:01 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_double(char **arr)
{
	int	i;
	int	j;

	i = 1;
	while (arr[i])
	{
		j = i + 1;
		while (arr[j])
		{
			if (ft_atoi(arr[i]) == ft_atoi(arr[j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

void	psrr(t_list **stack_a, t_list **stack_b)
{
	if (its_ok(stack_a, stack_b) == 1)
		return ;
	else if (ft_lstsize(*stack_a) == 2)
		case2(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) == 3)
	{
		if ((*stack_a)->content > (*stack_a)->next->content
			&& (*stack_a)->next->content < (*stack_a)->next->next->content
			&& (*stack_a)->content < ft_lstlast((*stack_a))->content)
			sa(stack_a);
		else
			case_3(stack_a);
	}
	else if (ft_lstsize(*stack_a) == 4 || ft_lstsize(*stack_a) == 5)
		case_5(stack_a, stack_b);
	else
		cases(stack_a, stack_b);
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

int	main(int ar, char **arv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	stack_b = malloc(sizeof (t_list *));
	stack_a = malloc(sizeof (t_list *));
	*stack_a = NULL;
	*stack_b = NULL;
	if (ar < 2)
	{
		write (1, "Error\n", 6);
		return (0);
	}
	rem(stack_a, arv);
	psrr(stack_a, stack_b);
	ft_lstclear(stack_a);
	ft_lstclear(stack_b);
}
