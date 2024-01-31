/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4.go_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:38:25 by matesant          #+#    #+#             */
/*   Updated: 2024/01/31 19:27:32 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

void	ft_sort(t_stack **a, t_stack **b)
{
	int		temp;
	int		i;
	int		j;

	i = 0;
	if (*b == NULL)
		ft_pb(a, b);
	while (i < 10)
	{
		j = 0;
		temp = 0;
		if ((*a)->x > (*b)->x)
			ft_pb(a, b);
		while (*a)
		{
			ft_printf("%d", (*a)->x);
			ft_pb(a, b);
			*a = (*a)->next;
		}
		temp = (*a)->x;
		while (temp < (*b)->x)
		{
			ft_pa(b, a);
			ft_printf("%d", (*b)->x);
		}
	}
	while (temp != (*a)->x)
	{
		ft_ra(a);
		j++;
	}
	while (j)
	{
		ft_rra(a);
		j--;
	}
	i++;
}
