/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.push.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:39:59 by matesant          #+#    #+#             */
/*   Updated: 2024/01/31 19:23:47 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

void	ft_push(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!*a || a)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
}

void	ft_pa(t_stack **a, t_stack **b)
{
	ft_push(b, a);
	ft_printf("pa\n");
}

void	ft_pb(t_stack **a, t_stack **b)
{
	ft_push(a, b);
	ft_printf("pb\n");
}
