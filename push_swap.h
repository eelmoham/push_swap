/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:30:09 by eelmoham          #+#    #+#             */
/*   Updated: 2022/02/25 15:11:03 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

int		len_arr(char **arr);
int		is_all_digit(char **args);
void	sa(t_list **lst);
void	sb(t_list **lst);
void	ss(t_list **stck_a, t_list **stck_b);
void	pa(t_list **stck_a, t_list **stck_b);
void	pb(t_list **stck_b, t_list **stck_a);
void	ra(t_list **stck_a);
void	rb(t_list **stck_b);
void	rr(t_list **stck_a, t_list **stck_b);
void	rra(t_list **stck_a);
void	rrb(t_list **stck_b);
void	rrr(t_list **stck_a, t_list **stck_b);
void	case2(t_list **a, t_list **b);
void	case_3(t_list **a);
void	case_5(t_list **a, t_list **b);
void	cases(t_list **a, t_list **b);
int		get_min(t_list **a);
int		get_max(t_list **a);
int		its_ok(t_list **a, t_list **b);
void	ft_lstdelone(t_list *lst);
void	ft_lstclear(t_list **lst);
t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *str);
int		check_double(char **arr);
void	rem(t_list **lst, char **arr);
void	ar_sort(t_list **a);
#endif
