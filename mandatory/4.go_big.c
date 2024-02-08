/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4.go_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:09:57 by matesant          #+#    #+#             */
/*   Updated: 2024/02/08 18:48:44 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

void	ft_first_pb(t_stack **a, t_stack **b)
{
	int		i;
	t_stack	*temp;

	i = (ft_listsize(*a)) / 2 + 1;
	temp = *a;
	while (ft_listsize(*a) > i)
	{
		if (temp->index < i)
			ft_pb(a, b);
		else
			ft_ra(a);
		temp = *a;
	}
	while (*a)
	{
		if (ft_listsize(*a) == 3)
		{
			ft_sort_three(a);
			break ;
		}
		else
			ft_pb(a, b);
	}
}

void	ft_swift(t_stack **a)
{
	int	small;
	int	size;

	small = 0;
	size = ft_listsize(*a) / 2;
	while (1)
	{
		small = ft_get_min(a);
		if (small == 0)
			return ;
		if (small < size)
			ft_ra(a);
		else
			ft_rra(a);
		ft_get_positions(a, NULL);
	}
}

void	ft_sort_remaining(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	temp = *b;
	while (temp)
	{
		ft_get_positions(a, b);
		ft_update_target_pos(*a, *b);
		ft_get_costs(*a, *b);
		ft_real_math(a, b);
		temp = *b;
	}
	ft_swift(a);
}

void	ft_go_big(t_stack **a, t_stack **b)
{
	int	*tab;

	tab = malloc(sizeof(int) * ft_listsize(*a) + 1);
	ft_bzero(tab, ft_listsize(*a));
	list_to_tab(*a, tab);
	ft_bubble_sort(tab, ft_listsize(*a));
	ft_create_index(*a, tab);
	ft_first_pb(a, b);
	ft_sort_remaining(a, b);
	free(tab);
}
