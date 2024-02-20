/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5.costs_target.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:40:25 by matesant          #+#    #+#             */
/*   Updated: 2024/02/20 11:47:05 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

void	ft_get_positions(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = *a;
	while (temp)
	{
		temp->position = i;
		i++;
		temp = temp->next;
	}
	i = 0;
	if (!b)
		return ;
	temp = *b;
	while (temp)
	{
		temp->position = i;
		temp = temp->next;
		i++;
	}
}

void	ft_update_target_pos(t_stack *a, t_stack *b)
{
	while (b)
	{
		b->target_pos = ft_get_target(a, b->index);
		b = b->next;
	}
}

int	ft_get_target(t_stack *a, int b_index)
{
	int		target_position;
	int		target_index;
	t_stack	*head;

	target_position = -1;
	head = a;
	target_index = INT_MAX;
	while (head)
	{
		if (head->index > b_index && head->index < target_index)
		{
			target_index = head->index;
			target_position = head->position;
		}
		head = head->next;
	}
	if (target_position == -1)
		return (ft_get_min(&a));
	return (target_position);
}

void	ft_get_costs(t_stack *a, t_stack *b)
{
	t_stack	*temp;
	int		size_a;
	int		size_b;

	temp = b;
	size_a = ft_listsize(a);
	size_b = ft_listsize(b);
	while (temp)
	{
		if (temp->position <= size_b / 2)
			temp->cost_b = temp->position;
		else
			temp->cost_b = (size_b - temp->position) * -1;
		if (temp->target_pos <= size_a / 2)
			temp->cost_a = temp->target_pos;
		else
			temp->cost_a = (size_a - temp->target_pos) * -1;
		temp = temp->next;
	}
}
