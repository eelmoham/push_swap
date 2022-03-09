/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 19:09:56 by eelmoham          #+#    #+#             */
/*   Updated: 2022/02/26 16:04:19 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "get_next_line/get_next_line.h"
# include "../push_swap.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	do_sa(t_list **lst);
void	do_sb(t_list **lst);
void	do_ss(t_list **stck_a, t_list **stck_b);
void	do_pa(t_list **stck_a, t_list **stck_b);
void	do_pb(t_list **stck_b, t_list **stck_a);
void	do_ra(t_list **stck_a);
void	do_rb(t_list **stck_b);
void	do_rr(t_list **stck_a, t_list **stck_b);
void	do_rra(t_list **stck_a);
void	do_rrb(t_list **stck_b);
void	do_rrr(t_list **stck_a, t_list **stck_b);
int		its_ok(t_list **a, t_list **b);
int		len_arr(char **arr);
int		is_all_digit(char **args);
void	rem(t_list **lst, char **arr);
size_t	ft_strlen1(const char *str);

#endif
