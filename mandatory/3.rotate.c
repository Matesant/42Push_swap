/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:56:09 by matesant          #+#    #+#             */
/*   Updated: 2024/01/30 14:20:54 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

void	ft_rotate(t_stack **x)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (!*x || !(*x)->next)
		return ;
	temp = *x;
	temp2 = ft_lstend(*x);
	*x = (*x)->next;
	temp->next = NULL;
	temp2->next = temp;
}

void	ft_ra(t_stack **a)
{
	ft_rotate(a);
	ft_printf("ra\n");
}

void	ft_rb(t_stack **b)
{
	ft_rotate(b);
	ft_printf("rb\n");
}

void	ft_rr(t_stack **a, t_stack **b)
{
	ft_rotate(a);
	ft_rotate(b);
	ft_printf("rr\n");
}
