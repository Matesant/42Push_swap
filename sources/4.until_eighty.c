/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4.until_eighty.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:38:25 by matesant          #+#    #+#             */
/*   Updated: 2024/02/06 16:26:22 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

int		ft_search(t_stack *a);

void	ft_adjust_stack_a(t_stack **a, t_stack **b, int i, t_stack *temp)
{
	int	counter;

	while (temp)
	{
		i = ft_listsize(temp);
		counter = ft_search(temp);
		if (counter > (i / 2))
			counter = (i - counter) * -1;
		if (counter < 0)
			while (counter++ < 0)
				ft_rra(a);
		else
			while (counter-- > 0)
				ft_ra(a);
		if (i != 3)
			ft_pb(a, b);
		else
			break ;
		temp = *a;
	}
}

void	ft_below_fifty(t_stack **a, t_stack **b)
{
	int		i;
	t_stack	*temp;

	i = 0;
	temp = *a;
	ft_adjust_stack_a(a, b, i, temp);
	ft_sort_three(a);
	while (*b)
		ft_pa(a, b);
}

int	ft_search(t_stack *a)
{
	int		temp;
	int		counter;
	t_stack	*temp2;

	temp2 = a;
	temp = a->x;
	counter = 0;
	while (a)
	{
		if (temp > a->x)
			temp = a->x;
		a = a->next;
	}
	while (temp2->x != temp)
	{
		temp2 = temp2->next;
		counter++;
	}
	return (counter);
}

