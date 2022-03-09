/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 19:09:12 by eelmoham          #+#    #+#             */
/*   Updated: 2022/02/25 15:35:59 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((i < n) && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] == s2[i])
			i++;
		else
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}

void	do_ins(char *str, t_list **a, t_list **b)
{
	if (str != NULL && ft_strncmp(str, "sa", ft_strlen1(str) - 1) == 0)
		do_sa(a);
	else if (str != NULL && ft_strncmp(str, "pb", ft_strlen1(str) - 1) == 0)
		do_pb(b, a);
	else if (str != NULL && ft_strncmp(str, "pa", ft_strlen1(str) - 1) == 0)
		do_pa(a, b);
	else if (str != NULL && ft_strncmp(str, "ra", ft_strlen1(str) - 1) == 0)
		do_ra(a);
	else if (str != NULL && ft_strncmp(str, "rra", ft_strlen1(str) - 1) == 0)
		do_rra(a);
	else if (str != NULL && ft_strncmp(str, "sb", ft_strlen1(str) - 1) == 0)
		do_sb(a);
	else if (str != NULL && ft_strncmp(str, "rrr", ft_strlen1(str) - 1) == 0)
		do_rrr(a, b);
	else if (str != NULL && ft_strncmp(str, "rrb", ft_strlen1(str) - 1) == 0)
		do_rrb(b);
	else if (str != NULL && ft_strncmp(str, "rr", ft_strlen1(str) - 1) == 0)
		do_rr(a, b);
	else if (str != NULL && ft_strncmp(str, "rb", ft_strlen1(str) - 1) == 0)
		do_rb(b);
	else if (str != NULL && ft_strncmp(str, "ss", ft_strlen1(str) - 1) == 0)
		do_ss(a, b);
}
/*void display(t_list *lst)
{
	t_list *ptr;
	ptr = lst;
	while (ptr != NULL)
	{
		printf("*>>>>%d\n",ptr->content);
		ptr = ptr->next;
	}
}*/

int	main(int ar, char **arv)
{
	t_list	**stack_a;
	t_list	**stack_b;
	char	*str;

	stack_b = malloc(sizeof (t_list *));
	stack_a = malloc(sizeof (t_list *));
	*stack_a = NULL;
	*stack_b = NULL;
	str = ft_strdup("");
	if (ar < 3)
		return (0);
	rem(stack_a, arv);
	while (str)
	{
		str = get_next_line(0);
		do_ins(str, stack_a, stack_b);
	}
	if (its_ok(stack_a, stack_b))
		write (2, "ok\n", 3);
	else
		write (2, "ko\n", 3);
	free (str);
}
