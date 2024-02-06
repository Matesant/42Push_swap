/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4.go_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:09:57 by matesant          #+#    #+#             */
/*   Updated: 2024/02/06 17:02:20 by matesant         ###   ########.fr       */
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
	ft_go_big(a, b, i);
	ft_sort_three(a);
	// ft_sort_remaining(a, b);
}
