/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8.utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:52:59 by matesant          #+#    #+#             */
/*   Updated: 2024/02/07 19:18:03 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

void	list_to_tab(t_stack *a, int *tab)
{
	int	i;

	i = 0;
	while (a)
	{
		tab[i] = a->x;
		a = a->next;
		i++;
	}
}

void	ft_bubble_sort(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	ft_create_index(t_stack *a, int *tab)
{
	t_stack	*temp;
	int		j;

	temp = a;
	while (temp)
	{
		j = 0;
		while (tab[j] != temp->x)
			j++;
		if (tab[j] == temp->x)
			temp->index = j + 1;
		temp = temp->next;
	}
}

int	ft_get_min(t_stack **a)
{
	t_stack	*temp;
	int		min_index;
	int		position;

	temp = *a;
	min_index = INT_MAX;
	while (temp)
	{
		if (temp->index < min_index)
		{
			min_index = temp->index;
			position = temp->position;
		}
		temp = temp->next;
	}
	return (position);
}
