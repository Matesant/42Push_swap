/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.push.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:39:59 by matesant          #+#    #+#             */
/*   Updated: 2024/02/15 10:49:39 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

void	ft_push(t_stack **from, t_stack **to)
{
	t_stack	*temp;

	if (!*from || !from)
		return ;
	temp = *from;
	*from = (*from)->next;
	temp->next = *to;
	*to = temp;
}

void	ft_pa(t_stack **a, t_stack **b)
{
	ft_push(b, a);
}

void	ft_pb(t_stack **a, t_stack **b)
{
	ft_push(a, b);
}
