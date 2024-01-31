/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4.sort_bellow_5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:36:39 by matesant          #+#    #+#             */
/*   Updated: 2024/01/31 17:28:46 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

void	ft_sort_two(t_stack **a)
{
	if ((*a)->x > (*a)->next->x)
		ft_sa(a);
}

void	ft_sort_three(t_stack **a)
{
	if ((*a)->x > (*a)->next->x
		&& (*a)->x > (*a)->next->next->x)
		ft_ra(a);
	if ((*a)->next->x > (*a)->next->next->x && (*a)->next->x > (*a)->x)
		ft_rra(a);
	if ((*a)->x > (*a)->next->x)
		ft_sa(a);
}
