/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.swap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:39:47 by matesant          #+#    #+#             */
/*   Updated: 2024/01/30 15:16:36 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

void	ft_swap(t_stack **x)
{
	t_stack	*temp;

	if (*x && (*x)->next)
	{
		temp = *x;
		*x = (*x)->next;
		temp->next = (*x)->next;
		(*x)->next = temp;
	}
}

void	ft_sa(t_stack **a)
{
	ft_swap(a);
	ft_printf("sa\n");
}

void	ft_sb(t_stack **b)
{
	ft_swap(b);
	ft_printf("sb\n");
}

void	ft_ss(t_stack **a, t_stack **b)
{
	ft_swap(a);
	ft_swap(b);
	ft_printf("ss\n");
}
