/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_matematica.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:34:04 by matesant          #+#    #+#             */
/*   Updated: 2024/02/07 16:57:18 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

t_stack	*ft_get_cheapest(t_stack **b)
{
	int		current;
	int		cheapest;
	t_stack	*temp;
	t_stack	*good_node;

	current = INT_MAX;
	cheapest = INT_MIN;
	while (temp)
	{
		current = ft_abs(temp->cost_a) + ft_abs(temp->cost_b);
		if (current < cheapest)
		{
			cheapest = current;
			good_node = temp;
		}
		temp = temp->next;
	}
	return (good_node);
}

void	ft_move_both(t_stack **a, t_stack **b, t_stack *cheap)
{
	if (cheap->cost_a < 0 && cheap->cost_b < 0)
	{
		while (cheap->cost_a && cheap->cost_b)
		{
			cheap->cost_a++;
			cheap->cost_b++;
			ft_rrr(a, b);
		}
	}
	else if (cheap->cost_a > 0 && cheap->cost_b > 0)
	{
		while (cheap->cost_a && cheap->cost_b)
		{
			cheap->cost_a--;
			cheap->cost_b--;
			ft_rr(a, b);
		}
	}
}

void	ft_real_math(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = ft_get_cheapest(b);
	ft_move_both(a, b, cheapest);
	// ft_move_a(a, cheapest);
	// ft_move_b(b, cheapest);
	ft_pa(a, b);
}
