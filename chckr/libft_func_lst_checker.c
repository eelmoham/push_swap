/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_func_lst_checker.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 23:03:01 by eelmoham          #+#    #+#             */
/*   Updated: 2022/02/26 15:17:53 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_lstdelone(t_list *lst)
{
	if (!lst)
		return ;
	printf("%p\n", lst);
	free(lst);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*temp;
	t_list	*next;

	temp = (*lst);
	while (temp)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
	(*lst) = NULL;
}

t_list	*ft_lstnew(int content)
{
	t_list	*first_list;

	first_list = (t_list *)malloc(sizeof(t_list));
	if (first_list == NULL)
		return (NULL);
	first_list->content = content;
	first_list->next = NULL;
	return (first_list);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

int	ft_lstsize(t_list *lst)
{
	int		len;
	t_list	*t;

	t = lst;
	len = 0;
	while (t != NULL)
	{
		len++;
		t = t->next;
	}
	return (len);
}
