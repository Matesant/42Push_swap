/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.rev_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:22:35 by matesant          #+#    #+#             */
/*   Updated: 2024/02/15 17:22:35 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_rev_rotate(t_stack **x)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (!*x || !(*x)->next)
		return ;
	temp = ft_lstend(*x);
	temp2 = ft_lstend2(*x);
	temp->next = *x;
	temp2->next = NULL;
	*x = temp;
}

void	ft_rra(t_stack **a)
{
	ft_rev_rotate(a);
}

void	ft_rrb(t_stack **b)
{
	ft_rev_rotate(b);
}

void	ft_rrr(t_stack **a, t_stack **b)
{
	ft_rev_rotate(a);
	ft_rev_rotate(b);
}
