/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4.go_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:09:57 by matesant          #+#    #+#             */
/*   Updated: 2024/02/06 19:25:23 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

void	ft_go_big(t_stack **a, t_stack **b, int i)
{
	t_stack	*temp;

	temp = *a;
	while (temp)
	{
		i = ft_listsize(temp);
		if (i != 3)
		{
			ft_pb(a, b);
			temp = *a;
		}
		else
			break ;
	}
}

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

void ft_get_positions(t_stack **a, t_stack **b)
{
	
}

void	ft_test(t_stack **a, t_stack **b)
{
	int	i;
	int	*tab;

	i = 0;
	tab = malloc(sizeof(int) * ft_listsize(*a));
	ft_bzero(tab, ft_listsize(*a));
	list_to_tab(*a, tab);
	ft_bubble_sort(tab, ft_listsize(*a));
	ft_create_index(a, tab);
	ft_first_pb(a, b);
	// ft_go_big(a, b, i);
	//ft_sort_three(a);
	// ft_sort_remaining(a, b);
}
