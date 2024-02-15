/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.swap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:39:47 by matesant          #+#    #+#             */
/*   Updated: 2024/02/15 10:50:16 by matesant         ###   ########.fr       */
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
}

void	ft_sb(t_stack **b)
{
	ft_swap(b);
}

void	ft_ss(t_stack **a, t_stack **b)
{
	ft_swap(a);
	ft_swap(b);
}
